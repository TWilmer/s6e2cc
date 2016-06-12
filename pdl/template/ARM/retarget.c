/*******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.  
*/
/******************************************************************************/
/** \file retaget.c
 **
 ** Implement re-target function of fputc
 **
 ** History:
 **   - 2014-11-08  1.0  EZh  First version
 **   - 2015-09-16  1.1  EZh  Use ITM API to retarget 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include <stdio.h>
#include <rt_misc.h>
#include "pdl_user.h"
#include "mcu.h"

#if (PDL_MCU_CORE == PDL_FM4_CORE) || (PDL_MCU_CORE == PDL_FM3_CORE)

#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_OFF) && (PDL_UTILITY_ENABLE_UART_SCANF == PDL_OFF)
#pragma import(__use_no_semihosting_swi)
#endif 
 
struct __FILE { int handle; /* Add whatever you need here */ };
 
FILE __stdout;
FILE __stdin;

#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_OFF)
int fputc(int ch, FILE *f) 
{
    return ITM_SendChar(ch);
}
#endif

#if (PDL_UTILITY_ENABLE_UART_SCANF == PDL_OFF)
volatile int32_t ITM_RxBuffer;
int fgetc(FILE *f)
{
    while (ITM_CheckChar() != 1) __NOP();
    return (ITM_ReceiveChar());
}
#endif 

int ferror(FILE *f)
{
/* Your implementation of ferror */
return EOF;
 
}
 
void _ttywrch(int c)
{
    ITM_SendChar(c);
}
 

int __backspace()
{
    return 0;
}
 
void _sys_exit(int return_code)
{
label:
    goto label;  /* endless loop */
 
}

#endif

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
