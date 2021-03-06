================================================================================
                               ADC example program
================================================================================

Copyright (C) 2013-2015, Cypress Semiconductor Corporation. All rights reserved.    
                                                                                     
This software, including source code, documentation and related                     
materials ( "Software" ), is owned by Cypress Semiconductor                         
Corporation ( "Cypress" ) and is protected by and subject to worldwide              
patent protection (United States and foreign), United States copyright              
laws and international treaty provisions. Therefore, you may use this               
Software only as provided in the license agreement accompanying the                 
software package from which you obtained this Software ( "EULA" ).                  
If no EULA applies, Cypress hereby grants you a personal, nonexclusive,             
non-transferable license to copy, modify, and compile the                           
Software source code solely for use in connection with Cypress's                    
integrated circuit products. Any reproduction, modification, translation,           
compilation, or representation of this Software except as specified                 
above is prohibited without the express written permission of Cypress.              
Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO                                
WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,                                
BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED                                        
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A                                     
PARTICULAR PURPOSE. Cypress reserves the right to make                              
changes to the Software without notice. Cypress does not assume any                 
liability arising out of the application or use of the Software or any              
product or circuit described in the Software. Cypress does not                      
authorize its products for use in any products where a malfunction or               
failure of the Cypress product may reasonably be expected to result in              
significant property damage, injury or death ( "High Risk Product" ). By            
including Cypress's product in a High Risk Product, the manufacturer                
of such system or application assumes all risk of such use and in doing             
so agrees to indemnify Cypress against all liability.  

================================================================================
History 
Date        Ver    AE          IAR     ARM   Description
2014-12-30  0.1    DHo         6.50.1  4.50  first version
================================================================================
Function description:
================================================================================
This example samples a single channel ADC channel under following condition:
Conversion mode                    :   scan mode
Trigger mode                       :   timer
Data conversion notification       :   interrupt

================================================================================
Environment
================================================================================
Test Board:
---------------------
MCU mini board

Assistance tool:
---------------------
Regulated DC power supply (DC Power)

Assistance software:
---------------------
None

================================================================================
Usage Procedure:
================================================================================
1) Connect to a DC power, PIN AN00 to V+, AVSS to V-.
2) Turn on the DC power.
3) Run the project.
4) Check the output value in terminal I/O if is equal to DC power settings.
   the output value from 0~4096 mapping to DC 0~3.3v.

================================================================================
Notice:
================================================================================
1) The printf content can be output to debug viewer In IAR with semi-hosting mode.
2) The printf content can be output to debug viewer In Keil MDK via SWO line. 
3) The printf content can also output to UART0 (SOT0_0).
   Make following steps to enable this method:
   - Set "PDL_PERIPHERAL_ENABLE_MFS0" and "PDL_UTILITY_ENABLE_UART_PRINTF" to PDL_ON in pdl.user.h
   - Call "Uart_Io_Init()" at the begin of main function 
4) For FM3 and FM4 products, All of 1), 2), 3) can be supported. However SWO pin is not available 
   in FM0+ product. So only 1), 3) can be suppoted for FM0+ products.
5) Before using printf function, enable the definition "DEBUG_PRINT" in pdl_user.h. When user
   Want to program the code into Flash and run the code standalone, disable the definition 
   "DEBUG_PRINT" in pdl_user.h. 

================================================================================
