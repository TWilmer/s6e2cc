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
 ** This example demonstrates firstly access free run timer normal count mode 
 ** with peak/zero match interrupt, then demo free run timer offset count mode 
 ** (Only supported by products after TYPE3 of FM4).
 **
 ** History:
 **   - 2014-11-23  0.0.1  DHo       First version.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pdl_header.h"

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
 
/// MFT channel
#define USER_MFT_CH          MFT0_FRT
/// FRT channel
#define USER_FRT_CH          MFT_FRT_CH0
#define USER_FRT_OFFSET_CH   MFT_FRT_CH1

#define USER_FRT_MODE0       FrtUpCount
#define USER_FRT_MODE1       FrtUpDownCount

#define USER_FRT_TEST_TIME   (10u)

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/


/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/


/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/


/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

// Interrupt count value of offset mode
#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
static uint32_t m_au32OffsetChZeroMatchCount[USER_FRT_TEST_TIME];
static uint32_t m_au32OffsetChPeakMatchCount[USER_FRT_TEST_TIME];
#endif
#endif

// Interrupt count value of normal mode
static uint32_t m_u32NormalCntPeakMatch;
static uint32_t m_u32NormalCntZeroMatch;

#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
// Interrupt count value of offset mode
static uint32_t m_u32OffsetCntPeakMatch;
static uint32_t m_u32OffsetCntZeroMatch;
#endif
#endif

/*!
 ******************************************************************************
 ** \brief FRT peak match interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
static void NormalFrtPeakIrqCallback(void)
{
    m_u32NormalCntPeakMatch ++;  // count for frt peak match
}

/*!
 ******************************************************************************
 ** \brief FRT zero match interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
static void NormalFrtZeroIrqCallback(void)
{
    m_u32NormalCntZeroMatch ++; // count for frt zero match
}

#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
/*!
 ******************************************************************************
 ** \brief FRT peak match interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
static void OffsetFrtPeakIrqCallback(void)
{
    m_au32OffsetChPeakMatchCount[m_u32OffsetCntPeakMatch++] = Mft_Frt_GetCurCount(&USER_MFT_CH, USER_FRT_OFFSET_CH);
}

/*!
 ******************************************************************************
 ** \brief FRT zero match interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
static void OffsetFrtZeroIrqCallback(void)
{
    m_au32OffsetChZeroMatchCount[m_u32OffsetCntZeroMatch++] = Mft_Frt_GetCurCount(&USER_MFT_CH, USER_FRT_OFFSET_CH);
}
#endif
#endif

/**
 ******************************************************************************
 ** \brief  Main function of project for frt.
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int32_t main(void)
{
    stc_mft_frt_config_t stcFrtConfig;
    stc_frt_irq_en_t stcFrtIrqEn;
    stc_frt_irq_cb_t stcFrtIrqCallBack;
/******************************************************************************/
/*                            FRT normal mode                                 */
/******************************************************************************/ 
    // Clear structures
    PDL_ZERO_STRUCT(stcFrtConfig);
    PDL_ZERO_STRUCT(stcFrtIrqEn);
    PDL_ZERO_STRUCT(stcFrtIrqCallBack);
    
    //configure frt interrupt mode
    stcFrtIrqEn.bFrtZeroMatchIrq = TRUE; //enable zero match interrupt
    stcFrtIrqEn.bFrtPeakMatchIrq = TRUE; //enable peak match interrupt

    //configure callback function of frt
    stcFrtIrqCallBack.pfnFrtPeakIrqCb = NormalFrtPeakIrqCallback;
    stcFrtIrqCallBack.pfnFrtZeroIrqCb = NormalFrtZeroIrqCallback;
    
    //configure the FRT parameter
    stcFrtConfig.enFrtMode = USER_FRT_MODE0;
    stcFrtConfig.enFrtClockDiv = FrtPclkDiv256;
    stcFrtConfig.bEnExtClock = FALSE;
    stcFrtConfig.bEnBuffer = TRUE;
    stcFrtConfig.pstcIrqEn = &stcFrtIrqEn;
    stcFrtConfig.pstcIrqCb = &stcFrtIrqCallBack;
    stcFrtConfig.bTouchNvic = TRUE;
    
    Mft_Frt_Init(&USER_MFT_CH ,USER_FRT_CH, &stcFrtConfig);
    //set frt cycle value
    Mft_Frt_SetCountCycle(&USER_MFT_CH ,USER_FRT_CH, 50000u);
    //start frt
    Mft_Frt_Start(&USER_MFT_CH ,USER_FRT_CH);

    m_u32NormalCntPeakMatch = 0u;
    m_u32NormalCntZeroMatch = 0u;
    while(1)
    {
        // stop FRT after occurred 10 times interrupt
        if((m_u32NormalCntPeakMatch >= USER_FRT_TEST_TIME ) && (m_u32NormalCntZeroMatch >= USER_FRT_TEST_TIME))
        {
            Mft_Frt_Stop(&USER_MFT_CH, USER_FRT_CH);
            break;
        }
    }

#if (PDL_MCU_CORE == PDL_FM4_CORE)
    #if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
/******************************************************************************/
/*                            FRT offset mode                                 */
/******************************************************************************/    
    // Clear structures
    PDL_ZERO_STRUCT(stcFrtConfig);
    PDL_ZERO_STRUCT(stcFrtIrqEn);
    PDL_ZERO_STRUCT(stcFrtIrqCallBack);
    
    // configure frt interrupt mode
    stcFrtIrqEn.bFrtZeroMatchIrq = TRUE; //enable zero match interrupt
    stcFrtIrqEn.bFrtPeakMatchIrq = TRUE; //enable peak match interrupt

    // configure callback function of frt
    stcFrtIrqCallBack.pfnFrtPeakIrqCb = OffsetFrtPeakIrqCallback;
    stcFrtIrqCallBack.pfnFrtZeroIrqCb = OffsetFrtZeroIrqCallback;
    
    //configure the FRT parameter
    stcFrtConfig.enFrtMode = USER_FRT_MODE1;
    stcFrtConfig.enFrtClockDiv = FrtPclkDiv256;
    stcFrtConfig.bEnExtClock = FALSE;
    stcFrtConfig.bEnBuffer = TRUE;
    stcFrtConfig.pstcIrqEn = &stcFrtIrqEn;
    stcFrtConfig.pstcIrqCb = &stcFrtIrqCallBack;
    stcFrtConfig.bTouchNvic = TRUE;
    
    Mft_Frt_Init(&USER_MFT_CH, USER_FRT_CH, &stcFrtConfig);
    //set frt cycle value
    Mft_Frt_SetCountCycle(&USER_MFT_CH, USER_FRT_CH, 15000u);
    //set offset value
    Mft_Frt_SetCountCycle(&USER_MFT_CH, USER_FRT_OFFSET_CH, 200u);
    // set the ch 1 to offset mode corperating with ch.0
    Mft_Frt_SetOffsetMode(&USER_MFT_CH, USER_FRT_OFFSET_CH, TRUE);   
    //start frt
    Mft_Frt_Start(&USER_MFT_CH, USER_FRT_CH);
    
    m_u32OffsetCntZeroMatch = 0;
    m_u32OffsetCntPeakMatch = 0;
    while(1)
    {
        // stop FRT after occurred 10 times interrupt
        if((m_u32OffsetCntZeroMatch >= USER_FRT_TEST_TIME ) && (m_u32OffsetCntPeakMatch >= USER_FRT_TEST_TIME))
        {
            Mft_Frt_Stop(&USER_MFT_CH, USER_FRT_CH);            
            break;
        }
    }
    
    #endif
#endif

    while(1);
}

/*****************************************************************************/
/* END OF FILE */

