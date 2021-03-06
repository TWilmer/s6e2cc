/*************************************************************************************
* Copyright (C) 2013-2015, Cypress Semiconductor Corporation. All rights reserved.    
*                                                                                     
* This software, including source code, documentation and related                     
* materials ( "Software" ), is owned by Cypress Semiconductor                         
* Corporation ( "Cypress" ) and is protected by and subject to worldwide              
* patent protection (United States and foreign), United States copyright              
* laws and international treaty provisions. Therefore, you may use this               
* Software only as provided in the license agreement accompanying the                 
* software package from which you obtained this Software ( "EULA" ).                  
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,             
* non-transferable license to copy, modify, and compile the                           
* Software source code solely for use in connection with Cypress's                    
* integrated circuit products. Any reproduction, modification, translation,           
* compilation, or representation of this Software except as specified                 
* above is prohibited without the express written permission of Cypress.              
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO                                
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,                                
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED                                        
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A                                     
* PARTICULAR PURPOSE. Cypress reserves the right to make                              
* changes to the Software without notice. Cypress does not assume any                 
* liability arising out of the application or use of the Software or any              
* product or circuit described in the Software. Cypress does not                      
* authorize its products for use in any products where a malfunction or               
* failure of the Cypress product may reasonably be expected to result in              
* significant property damage, injury or death ( "High Risk Product" ). By            
* including Cypress's product in a High Risk Product, the manufacturer                
* of such system or application assumes all risk of such use and in doing             
* so agrees to indemnify Cypress against all liability.                               
*/
/******************************************************************************/
/** \file main.c
 **
 ** This example demonstrates both interrupt and polling access mode of PWM timer.
 ** PWM wave can be observed at P40 during demonstration process.
 **
 ** History:
 **   - 2013-05-20  0.0.1  Edison Zhang        First version.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pdl_header.h"

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/
#define  USER_BT             BT0
#if !defined(SetPinFunc_TIOA0_1_OUT)
#error TIOA0_1 pin is not available in this MCU product, \
change to other re-location pin! Then delete "me" !
#endif
#define  PwmInitOutput()     SetPinFunc_TIOA0_1_OUT()

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
/*! \brief Interrupt count value */
static uint32_t m_u32CntIntTrg, m_u32CntIntDuty, m_u32CntIntUnder;

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PwmDutyMatchIrqHandler(void);
static void PwmUnderflowIrqHandler(void);
static void PwmTrigIrqHandler(void);
static void Delay(void);
/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief PWM timer example code
 **
 ** 1. Initialization
 ** 3. Enable interrupt.
 ** 4. Enable count operation.
 ** 5. Start software trigger.
 ** 6. Disable interrupt
 ** 7. Restart software trigger
 ** 8. Disable count operation.
 ******************************************************************************
 */
int32_t main(void)
{
    stc_bt_pwm_config_t stcPwmConfig;
    stc_pwm_irq_en_t stcIrqEn;
    stc_pwm_irq_cb_t stcIrqCb;
    uint32_t u32Cnt=0;
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("PWM Example Program Start \n");
    printf("==================================================\n");
#endif
    
    // Set Basetimer IO port  
    PwmInitOutput();
    // Clear structures
    PDL_ZERO_STRUCT(stcPwmConfig);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);
    
    // Initialize interrupt
    stcPwmConfig.pstcPwmIrqEn = &stcIrqEn;
    stcPwmConfig.pstcPwmIrqCb = &stcIrqCb;
    // Set requested I/O mode 
    Bt_ConfigIOMode(&USER_BT, BtIoMode0);
    
    // Initialize PWM timer
    stcPwmConfig.enPres = PwmPres1Div4;  // PWM clock = 5MHz @ PCLK = 20MHz
    stcPwmConfig.enMode = PwmContinuous; 
    stcPwmConfig.enExtTrig = PwmExtTrigDisable;
    stcPwmConfig.enOutputMask = PwmOutputNormal;
    stcPwmConfig.enOutputPolarity = PwmPolarityLow;
    stcPwmConfig.enRestartEn = PwmRestartEnable;    
    stcPwmConfig.pstcPwmIrqEn->bPwmTrigIrq = 1;
    stcPwmConfig.pstcPwmIrqEn->bPwmDutyMatchIrq = 1;
    stcPwmConfig.pstcPwmIrqEn->bPwmUnderflowIrq = 1;
    stcPwmConfig.pstcPwmIrqCb->pfnPwmTrigIrqCb = PwmTrigIrqHandler;
    stcPwmConfig.pstcPwmIrqCb->pfnPwmDutyMatchIrqCb = PwmDutyMatchIrqHandler;
    stcPwmConfig.pstcPwmIrqCb->pfnPwmUnderflowIrqCb = PwmUnderflowIrqHandler;
    stcPwmConfig.bTouchNvic = TRUE;
    Bt_Pwm_Init(&USER_BT , &stcPwmConfig);
    // Set cycle and duty value
    Bt_Pwm_WriteCycleVal(&USER_BT, 999); // Cycle = (1+m)*PWM clock cycle = 200us
    Bt_Pwm_WriteDutyVal(&USER_BT, 199);  // Duty = (1+m)*PWM clock cycle = 40us
            
    // Enable count operatoin
    Bt_Pwm_EnableCount(&USER_BT);
    
    // Start triggered by software
    Bt_Pwm_EnableSwTrig(&USER_BT);
    
    // Delay some time
    Delay();     

#ifdef DEBUG_PRINT 
    printf("Cycle: %d\n", 999);
    printf("Duty: %d\n", 199);       
#endif    
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Enable Interrupt mode, waiting several seconds approximately\n");
#endif  
    
    // Delay some time
    Delay(); 
    
    /* Disable Interrupt */ 
    Bt_Pwm_DisableIrq(&USER_BT, PwmTrigIrq);
    Bt_Pwm_DisableIrq(&USER_BT, PwmDutyMatchIrq);
    Bt_Pwm_DisableIrq(&USER_BT, PwmUnderflowIrq);
       
#ifdef DEBUG_PRINT 
    printf("Interrupt times:\n"); 
    printf("PWM trigger interrupt:   %d\n", m_u32CntIntTrg);    
    printf("PWM duty match interrupt:%d\n", m_u32CntIntDuty);       
    printf("PWM underflow interrupt: %d\n", m_u32CntIntUnder);  
#endif
    
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Disable Interrupt mode, waiting several seconds approximately\n");
#endif
    
    m_u32CntIntTrg = 0;
    m_u32CntIntDuty = 0;
    m_u32CntIntUnder = 0;   
    
    // Delay some time
    Delay(); 
    
#ifdef DEBUG_PRINT 
    printf("Interrupt times:\n"); 
    printf("PWM trigger interrupt:   %d\n", m_u32CntIntTrg);    
    printf("PWM duty match interrupt:%d\n", m_u32CntIntDuty);       
    printf("PWM underflow interrupt: %d\n", m_u32CntIntUnder);
#endif 
    
    // Restart triggered by software
    Bt_Pwm_EnableSwTrig(&USER_BT);
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Enable query mode, waiting several seconds approximately\n");
#endif
 
    m_u32CntIntTrg = 0;
    m_u32CntIntDuty = 0;
    m_u32CntIntUnder = 0; 
    
    // Interrupt query mode 
    do 
    {   
        if (Bt_Pwm_GetIrqFlag(&USER_BT, PwmTrigIrq) == PdlSet)
        {
            Bt_Pwm_ClrIrqFlag(&USER_BT, PwmTrigIrq);
            m_u32CntIntTrg++;
        }
        else if (Bt_Pwm_GetIrqFlag(&USER_BT, PwmDutyMatchIrq) == PdlSet)
        {
            Bt_Pwm_ClrIrqFlag(&USER_BT, PwmDutyMatchIrq);
            m_u32CntIntDuty++;
        }
        else if (Bt_Pwm_GetIrqFlag(&USER_BT, PwmUnderflowIrq) == PdlSet)
        {
            Bt_Pwm_ClrIrqFlag(&USER_BT, PwmUnderflowIrq);
            m_u32CntIntUnder++;
        }
        u32Cnt++;
    } while(u32Cnt <2500000UL);
    
#ifdef DEBUG_PRINT
    printf("Interrupt request times:\n"); 
    printf("PWM trigger interrupt:   %d\n", m_u32CntIntTrg);    
    printf("PWM duty match interrupt:%d\n", m_u32CntIntDuty);       
    printf("PWM underflow interrupt: %d\n", m_u32CntIntUnder);
#endif 
    
    // Disable PWM count
    Bt_Pwm_DisableCount(&USER_BT);
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("PWM Example Program End \n");
    printf("==================================================\n");
#endif
    
    // De-Initialize PWM 
    Bt_Pwm_DeInit(&USER_BT, TRUE);

    while(1);
}
/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief PWM duty match interrupt handler
 ******************************************************************************
 */
static void PwmDutyMatchIrqHandler(void)
{
    m_u32CntIntDuty++;
}

/*!
 ******************************************************************************
 ** \brief PWM underflow interrupt handler
 ******************************************************************************
 */
static void PwmUnderflowIrqHandler(void)
{
    m_u32CntIntUnder++;
}

/*!
 ******************************************************************************
 ** \brief PWM trigger interrupt handler
 ******************************************************************************
 */
static void PwmTrigIrqHandler(void)
{
    m_u32CntIntTrg++;
}

/*
 ******************************************************************************
 ** \brief Delay requested secondes approximately
 ******************************************************************************
 */
static void Delay(void)
{
    int32_t u8Cnt1,u8Cnt2;
   
    u8Cnt2 = SystemCoreClock;
     
    u8Cnt1 = 0;
    while (1) 
    {
        u8Cnt1++;
        if (u8Cnt1 > u8Cnt2) 
        {
            break;
        }
    }   
}

/*****************************************************************************/
/* END OF FILE */
