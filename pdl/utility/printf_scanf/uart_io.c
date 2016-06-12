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
/** \file uart_printf.c
 **
 ** The file re-targets the "fputc" and "fgetc" function. The printf can be 
 ** output via UART with fputc function. The scanf can receive input character
 ** from UART with fgetc function.
 **
 ** A detailed description is available at 
 ** @link UartIoGroup Uart Printf/scanf Module description @endlink
 **
 ** History:
 **   - 2014-11-14  1.0  EZh         First version for FM universal PDL.
 **
 ******************************************************************************/
#include "uart_io.h"
#include "mfs\mfs.h"
#include "gpio\gpio.h"   

#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON) || (PDL_UTILITY_ENABLE_UART_SCANF == PDL_ON)
/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define InitPrintfIo()     {SetPinFunc_SIN0_0();SetPinFunc_SOT0_0();}   
/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/
volatile stc_mfsn_uart_t* UartCh = &UART0;
/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/
/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
/**
 ******************************************************************************
 ** \brief  UART initialization for printf usage
 ******************************************************************************/
void Uart_Io_Init(void)
{
    stc_mfs_uart_config_t stcUartConfig;

    /* Initialize UART function I/O */
    InitPrintfIo();

    /* Initialize UART TX channel  */
    stcUartConfig.enMode = UartNormal;
    stcUartConfig.u32BaudRate = 115200;
    stcUartConfig.enDataLength = UartEightBits;
    stcUartConfig.enParity = UartParityNone;
    stcUartConfig.enStopBit = UartOneStopBit;
    stcUartConfig.enBitDirection = UartDataLsbFirst;
    stcUartConfig.bInvertData = FALSE;
    stcUartConfig.bHwFlow = FALSE;
    stcUartConfig.pstcFifoConfig = NULL;

    Mfs_Uart_Init(UartCh, &stcUartConfig);

    /* Enable TX and RX function of UART0   */
#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON)    
    Mfs_Uart_EnableFunc(UartCh, UartTx);
#endif
#if (PDL_UTILITY_ENABLE_UART_SCANF == PDL_ON)     
    Mfs_Uart_EnableFunc(UartCh, UartRx);
#endif    
}

#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON)  
/**
 ******************************************************************************
 ** \brief  Re-target putchar function
 ******************************************************************************/
int fputc(int ch, FILE *f)
{
    if(((uint8_t)ch) == '\n')
    {
        while (TRUE != Mfs_Uart_GetStatus(UartCh, UartTxEmpty)); /* wait until TX buffer empty */
        Mfs_Uart_SendData(UartCh, '\r');
    }

    while (TRUE != Mfs_Uart_GetStatus(UartCh, UartTxEmpty)); /* wait until TX buffer empty */
    Mfs_Uart_SendData(UartCh, ch);

    return ch;
}
#endif

#if (PDL_UTILITY_ENABLE_UART_SCANF == PDL_ON)   
/**
 ******************************************************************************
 ** \brief  Re-target getchar function
 ******************************************************************************/
int fgetc(FILE *f)
{
  uint8_t u8Data;
  
  while (TRUE != Mfs_Uart_GetStatus(UartCh, UartRxFull)); // wait until RX buffer full 
 
  u8Data = Mfs_Uart_ReceiveData(UartCh); // Read a character from the UART 
  
  return u8Data;
}

#endif

#endif // #if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON) || (PDL_UTILITY_ENABLE_UART_SCANF == PDL_ON)

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
