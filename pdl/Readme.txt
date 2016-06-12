==============================================================================================
                              Universal PDL Project for FM Family 
==============================================================================================

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
                                                                                                                                                   
==========================================================================
 
History
Date        Ver   IAR    ARM    Description
2014-12-11  0.1   6.50   4.70   First version
2014-12-19  0.2   6.50   4.70   Add RTC, VBAT, LPM driver
                                Add examples of WDG, DT, RTC, MFT  
                                Support S6E2CDHx series
2015-01-08  0.3   6.50   4.70   Add I2S-Lite, VBAT, Reset, LVD drivers
                                Add I2S-Lite, VBAT, LPM, LVD examples
                                Support S6E100xF series
2015-02-13  0.4   6.50   4.70   Add Program-CRC, DSTC, LCD, I2S, HyperBus,
                                Flash, External Bus I/F drivers and examples.
                                Add utility drivers for HyperFlash, Nand 
                                Flash, SDRAM, PSRAM and Seg-LCD.
                                Support S6E1B8X/S6E1B7X.
2015-03-30  0.5   6.50   4.70   Add HSSPI, CAN, CANFD, SDIF, HDMI-CEC driver 
                                and examples. 
2015-04-01  1.0   6.50   4.70   First formal release 
2015-08-17  1.0.1 6.50   4.70   Support S6E2GMx series
2015-09-22  1.1.0 6.50   4.70   Support S6E2HGx, S6E1C3x series
2015-09-29  2.0.0 6.50   4.70   Change location of pdl_device.h

==========================================================================

PDL (Peripheral Driver Library)

This library contains driver modules for the following peripherals and
resources:

- ADC   Analog Digital Cionverter
- BT    Base Timer
- CAN   Controller Area Network
- CANFD CAN with Flexible Data Rate
- CLK   Clock
- CR    CR Trimming
- CRC   Cyclic Redundancy Check
- CSV   Clock supervisor
- DAC   Digital Analog Converter
- DMA   Direc Memory Access
- DTSC  Descriptor System data Transfer Controller
- DT    Dual Timer
- EXINT External Interrupt
- EXTIF External Bus Inerface
- Flash Internal Flash Operation
- GPIO  General Purpose Inoput/Output Ports (only header file)
- HBIF  Hyper Bus Interface
- HSSPI High Speed Quad SPI
- I2CS  I2C Slave
- I2S   Inter-IC Sound
- I2SL  I2S Lite Version
- ICC   IC Card Interface
- LCD   Segment LCD Controller
- LPM   Low Power Consumption Mode
- LVD   Low Volatage Detection
- MFS   Multi Function Serial Interface
- MFT   Multi Function Timer
- PCRC  Programmable Cyclic Redundancy Check
- PPG   Programmable Pulse Generator
- QPRC  Quad Decoder and Position/Revolution Counter
- RC    HDMI-CEC/Remote Control Reception/Transmission
- RESET Reset Cause Register
- RTC   Real Time Clock
- SDIF  SD card interface   
- UID   Unique ID
- VBAT  VBAT Domain
- WC    Watch Counter
- WDG   Watch Dog Timer

For almost all peripheral modules there is several example code available.
These examples are located in the example folder and its sub folders (see
below at the PDL's directory tree).


The following examples are available:
-------------------------------------
- ADC
  - adc_scan_multich_irq_bt       ADC multi-channels scan sample with interrupt mode triggered by base timer
  - adc_scan_multich_irq_sw       ADC multi-channels scan conversion with usage of interrupt callback triggered by software
  - adc_scan_multich_polling_sw   ADC multi-channels scan conversion with polling for conversion finish triggered by software
  - adc_scan_onech_irq_sw         ADC single-channel scan sample with interrupt mode triggered by software
  - adc_scan_onech_polling_sw     ADC single-channel scan conversion with polling for conversion finish triggered by software
  - adc_scan_dma                  ADC single-channel scan sample using DMA transfer
  - adc_prio_irq_sw               ADC priority conversion with usage of interrupt callback triggered by software
  - adc_prio_polling_sw           ADC priority conversion with polling for finished conversion triggered by software
  - adc_range_compare             ADC result range comparison function implementation
  - adc_result_compare            ADC result value comparison function implementation  
  - adc_scan_onech_mft_frt        ADC single-channel scan sample with interrupt mode triggered by Free Run Timer of MFT
  - adc_scan_onech_mft_adcmp      ADC single-channel scan sample with interrupt mode triggered by ADC compare unit of MFT
                                
- BT
  - bt_iomode        Base Timer IO modes demonstration             
  - bt_ppg           Base Timer configured as Programmable Pulse Generator
  - bt_pwc           Base Timer configured as Pulse Width Counter
  - bt_pwm           Base Timer configured as Pulse With Modulator
  - bt_rt            Base Timer configured as Reload Timer 

- CAN
  - can_simple       Perform CAN standard frame transmission and reception

- CANFD
  - canfd_simple     Perform CANFD standard frame transmission and reception

- CLK 
  - clock_gating     Implement peripheral clock gating and enable
  - clk_init         Implement clock initialization with clock setting API

- CR
  - cr_trimming
    - fm0p
      - type1_2      The CR-trimming samples of FM0P type 1 and 2 products
    - fm3
      - type0        The CR-trimming samples of FM3 type 0 products
      - type1_5      The CR-trimming samples of FM3 type 1 and 5 products
      - type2_4      The CR-trimming samples of FM3 type 2 and 4 products
      - type3_7      The CR-trimming samples of FM3 type 3 and 7 products
      - type8_9_10_11_12  The CR-trimming samples of FM3 type 8-12 products
    - fm4
      - type1_2_3_4  The CR-trimming samples of FM4 type 1,2,3,4 products

- CRC
  - crc_16_32  Generate CRC16 and CRC32 code using hardware CRC module

- CSV
  - csv_reset        CSV reset demonstration when main/sub clock frequency is abnormal
  - fcs_int          FCS interrupt demonstration when main clock frequency is abnormal
  - fcs_reset        CSV reset demonstration when main clock frequency is abnormal

- DAC
  - dac_sin_tri_wave Output sin and triangle wave via DAC

- DMA                
  - dma_software     The DMA perform a sotware block transfer

- DSTC
  - dstc_sw_transfer Transfer data using DSTC triggered by software
  - dstc_hw_transfer Transfer data using DSTC triggered by Base Timer 0

- DT                 
  - dt_unuse_int     Dual Timer configured as periodic mode for ch.0 and one-shot mode for ch.1 with interrupt flag polling
  - dt_use_int       Dual Timer configured as periodic mode for ch.0 and one-shot mode for ch.1 with usage interruption callback

- EXINT
  - exint_simple     Simple external interrupt occurence demonstration

- EXTIF
  - extif_access_nanflash_s34ml101g  Access to Nand Flash (S34ML101G) with External Bus
  - extif_access_psaram_sv6p1615     Access to PSRAM (SV6P1615) with External Bus
  - extif_access_sdram_is42s16800    Access to SDRAM (IS42S1688) with External Bus

- Flash
  - fm0p
    - type1_2   Implement Flash operation of FM0+ type 1 and 2 products
  - fm3 
    - type0     Implement Flash operation of FM3 type 0 products
    - type1_2_5 Implement Flash operation of FM3 type 1,2,5 products
    - type3_7   Implement Flash operation of FM3 type 3,7 products
    - type4     Implement Flash operation of FM3 type 4 products 
    - type6_8_9 Implement Flash operation of FM3 type 6,8,9 products
    - type10_11 Implement Flash operation of FM3 type 10,11 products
    - type12    Implement Flash operation of FM3 type 12 products 
   - fm4
     - type1     Implement Flash operation of FM4 type 1 products
     - type2_3_4 Implement Flash operation of FM4 type 2,3,4 products

- GPIO               
  - gpio_set        Simple GPIO pin setting
  - fgpio_set       Simple Fast GPIO pin setting

- HBIF
  - hbif_access_s26kl512s  Access Hyper Flash S26KL512S via HyperBus interface

- HSSPI
  - hsspi_access_s25l164k  Access Flash S25L164K via High Speed Quad SPI interface

- I2CS
  - i2c_slave_wkup
    - wkup_master   Send correponding slave address or reserved address to wakeup slave MCU from standby mode via i2S Slave I/F
    - wkup_slave    Enter standby mode after initializing I2C Slave and wait for wakeup via I2C slave

- I2S
  - i2s_play_wave_via_wm8731  Play wave files by I2S via I2S codec WM8731

- I2SL
  - i2s_irq_play_wave_via_wm8731       Play wave data via WM8731 using I2S-Lite with interrupt callback
  - i2s_polling_play_wave_via_wm8731   Play wave data via WM8731 using I2S-Lite with interrupt flag polling

- ICC
  - icc_atr_interrupt  Receive ATR from IC card via IC card interface with interrupt enabled

- LCD
  - cl1010   Use LCD controller to control Segment LCD CL1010
  - tsdh1188 Use LCD controller to control Segment LCD TSDH1188

- LPM
  - lpm_rtc_mode               RTC mode waken up by RTC interrupt
  - lpm_sleep_mode             Sleep mode waken up by external interrupt
  - lpm_deep_standby_rtc_mode  Deep standby RTC mode waken up by RTC interrupt

- LVD
  - lvd_interrupt     
    - fm0p_type2      Detect low voltage by generating interrupt on TYPE2 product of FM0+
    - fmx_other       Detect low voltage by generating interrupt on other products
  - lvd_polling       
    - fm0p_type2      Detect low votage by polling interrupt flag on TYPE2 product of FM0+
    - fmx_other       Detect low votage by polling interrupt flag on other products
 
- MFS 
  - UART
    - uart_interrupt      UART communication between 2 channels with interrupt enabled
    - uart_polling        UART communication between 2 channels with interrupt flag polling
    - uart_printf         Use "printf" to print data out via UART
    - uart_fifo_interrupt UART communication between 2 channels with interrupt enabled using FIFO
    - uart_dma            UART communication between 2 channels using DMA
  - CSIO
    - csio_interrupt      CSIO communication between 2 channels(one for Master, the other for Slave) with interrupt enabled
    - csio_polling        CSIO communication between 2 channels(one for Master, the other for Slave) with interrupt flag polling
    - csio_fifo_interrupt CSIO communication between 2 channels(one for Master, the other for Slave) with interrupt enabled using FIFO
    - csio_trig_by_sync_timer CSIO communication between 2 channels(one for Master, the other for Slave) with interrupt enabled triggered by Serial timer
    - csio_using_cs           CSIO communication between 2 channels(one for Master, the other for Slave) with interrupt enabled and CS pin enabled 
    - csio_dma                CSIO communication between 2 channels using DMA
  - i2c
    - i2c_polling
      - i2c_master_polling   I2C channel acts as I2C master with TX/RX completion polling, which communicates with the slave "i2c_slave_polling"
      - i2c_slave_polling    I2C channel acts as I2C slave with TX/RX completion polling, which communicates with the slave "i2c_master_polling"
    - i2c_eeprom             Access to EEPROm with I2C interface with interrupt mode or polling mode
  - lin
    - lin_interrupt
      - lin_master           LIN channel acts as LIN master with interrupt mode, which communicates with the slave "lin_slave" at current folder.
      - lin_slave            LIN channel acts as LIN slave with interrupt mode, which communicates with the master "lin_master" at current folder.
    - lin_polling
      - lin_master           LIN channel acts as LIN master with interrupt polling mode, which communicates with the slave "lin_slave" at current folder.
      - lin_slave            LIN channel acts as LIN slave with interrupt polling mode, which communicates with the master "lin_master" at current folder.
                    
- MFT                
  - FRT              
    - frt_int        Free-run Timer function with usage of zero/peak match interrupt callback
    - frt_polling    Free-run Timer function with polling for zero/peak match
  - ICU              
    - icu_int        Input Captuer Unit function with usage of interrupt callback
    - icu_polling    Input Captuer Unit function with polling for capture completion
  - OCU
    - fm3_fm4_fm0
      - ocu_ch_linked  Perform 2 change linked mode of Output Compare Unit with FM3 compatile mode
      - ocu_ch_single  Perform 1-change/low-active/high-active mode of Output Compare Unit with FM3 compatile mode
    - fm4_fm0
    - ocu_ch_linked  Perform 2 change linked mode of Output Compare Unit   
    - ocu_ch_single  Perform 1-change/low-active/high-active mode of Output Compare Unit
  - WFG
    - fm3_fm0_fm4
      - wfg_ppg_dead_timer_mode  Perform PPG-dead timer mode of Waveform Generator Unit with FM3 compatile mode
      - wfg_rt_dead_timer_mode   Perform RT-dead timer mode of Waveform Generator Unit with FM3 compatile mode
      - wfg_rt_ppg_mode          Perform RT-PPG mode of Waveform Generator Unit with FM3 compatile mode
      - wfg_through_mode         Perform through mode of Waveform Generator Unit with FM3 compatile mode
      - wfg_timer_ppg_mode       Perform Timer-PPG mode of Waveform Generator Unit with FM3 compatile mode
      - wfg_nzcl_dtif_sw_trig    Perform DTIF interrupt caused by software trigger with FM3 compatile mode
      - wfg_nzcl_dtif_dttix_trig Perform DTIF interrupt caused by DTTIX pin trigger with FM3 compatile mode
    - fm0_fm4
      - wfg_ppg_dead_timer_mode  Perform PPG-dead timer mode of Waveform Generator Unit
      - wfg_rt_dead_timer_mode   Perform RT-dead timer mode of Waveform Generator Unit
      - wfg_rt_ppg_mode          Perform RT-PPG mode of Waveform Generator Unit
      - wfg_through_mode         Perform through mode of Waveform Generator Unit
      - wfg_timer_ppg_mode       Perform Timer-PPG mode of Waveform Generator Unit
      - wfg_nzcl_dtif_sw_trig    Perform DTIF interrupt caused by software trigger
      - wfg_nzcl_dtif_dttix_trig Perform DTIF interrupt caused by DTTIX pin trigger

- PCRC
  - pcrc_gen  Generate CRC code with programmable CRC

- QPRC
  - qprc_pc_directional       Perform Count mode with direction (mode 3) of Position Counter  
  - qprc_pc_updown            Perform Up/down count mode (mode 1) of Position Counter
  - qprc_pc_phase_diff        Perform Phase different count mode (mode 2) of Position Counter 
  - qprc_rc_pc_ofuf_trig      Perform Revolution Counter mode 2 (triggered by Position Counter)
  - qprc_rc_zin_pcofuf_trig   Perform Revolution Counter mode 3 (triggered by ZIN or Position Counter)
  - qprc_rc_zin_trig          Perform Revolution Counter mode 1 (triggered by ZIN)

- RC
  - cec
    - cec_rx_interrupt  Perform CEC format data reception using interrupt callback
    - cec_rx_polling    Perform CEC format data reception with interrupt flag polling
    - cec_tx_interrupt  Perform CEC format data tranmission using interrupt callback
    - cec_tx_polling    Perform CEC format data tranmission with interrupt flag polling
  - nec
    - nec_rx_interrupt  Perform NEC format data reception using interrupt callback
    - nec_rx_polling    Perform NEC format data reception with interrupt flag polling

- RTC
  - rtc_count        Usage of time counting and alarm interruption for RTC
  - rtc_timer        Usage of timer interruption for RTC
  - rtc_calibration  Usage of calibration function for RTC  

- SDIF
  - sd_card_block_rw  Perform data block read/write from/to SD memory card via SDIO inferface

- UID
  - uid_read         Read product unique ID with several method.

- VBAT
  - vbat_gpio        Implement GPIO output/input of VBAT domain

- WC
  - wc_int           Perform Watch Counter counting with interrupt mode
  - wc_polling       Perform Watch Counter counting with interrupt flag polling mode

- WDG
  - hwwdg             Usage of hardware watchdog
  - swwdg
    - swwdg_normal    Usage of normal mode for software watchdog
    - swwdg_window    Usage of window mode for software watchdog  


Usage of example code:
----------------------

Each example code consists of a 'main.c' and a 'pdl_user.h' module.
The main module contains the example code, where 'pdl_user.h'
contains all necessary settings and definitions for the example
itself.
To use and compile an example, just copy these two modules
to the 'template/source' folder, overwriting the modules located
there. The overwritten modules have backups in the 'template/
source/backup' folder for recovery.
The default device selected is MB9BF506R, if other device is used, 
refer to "fm_pdl_quick_start_guide.pdf" about how to adjust the setting 
in the IAR and Keil for this device.
Follow the explanations and process in the main.c module's
description in the comment lines at the top.


Folder structure of the PDL project:
------------------------------------

fm_pdl-vxy
 !
 +-- common
 !
 +-- example
 !    !
 !    +-- adc
 !    !    ! 
 !    !    +-- adc_dma
 !    !    +-- adc_irq
 !    !    +-- adc_polling
 !    !   ...
 !    !
 !    +-- bt
 !    !    !
 !   ...   +-- ...
 !
 +-- driver
 !    !    !
 !    !    +-- adc
 !    !    +-- bt
 !    !    +-- ...
 !    !   ...
 !    !
 +-- utility
 !    !    !
 !    !    +-- eeprom
 !    !    +-- qspi_flash
 !    !    ...
 !    !
 +-- midware
 !    !    !
 !    !    +-- usb
 !    !    ...
 !
 !
 +-- template
       !
       +-- ARM
       !    !
       !    +-- output
       !         !
       !         +-- debug
       !         *-- release
       !
       +-- IAR
       !    !
       !    +-- config
       !    !    !
       !    !    +-- flashloader
       !    !
       !    +-- debug
       !    !    !
       !    !    +-- exe
       !    !    +-- list
       !    !    +-- obj
       !    !
       !    +-- release 
       !    !    !
       !    !    +-- exe
       !    !    +-- list
       !    !    +-- obj
       !    !
       !    +-- settings
       !
       +-- source
