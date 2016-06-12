/*******************************************************************************
* Copyright (C) 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
*
* This software, including source code, documentation and related
* materials "Software", is owned by Cypress Semiconductor
* Corporation "Cypress" and is protected by and subject to worldwide
* patent protection (United States and foreign), United States copyright
* laws and international treaty provisions. Therefore, you may use this
* Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software "EULA".
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
* significant property damage, injury or death "High Risk Product". By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*/
/******************************************************************************/
/** \file iomux.c
 **
 ** A detailed description is available at 
 ** @link IomuxGroup IOMUX Module description @endlink
 **
 ** History:
 **   - 2016-01-10  1.0  Pin And Code Wizard  Generated code.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "iomux.h"
#include "gpio/gpio.h"

/**
 ******************************************************************************
 ** \addtogroup IomuxGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/
static void Iomux_CLOCK_Init(void);
static void Iomux_CLOCK_DeInit(void);

static void Iomux_DEBUG_Init(void);
static void Iomux_DEBUG_DeInit(void);

static void Iomux_CAN_Init(void);
static void Iomux_CAN_DeInit(void);

static void Iomux_EXTBUS_Init(void);
static void Iomux_EXTBUS_DeInit(void);

static void Iomux_USB_Init(void);
static void Iomux_USB_DeInit(void);

static void Iomux_GPIO_Init(void);
static void Iomux_GPIO_DeInit(void);


/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
/**
 *****************************************************************************
 ** \brief This function initializes CLOCK
 **
 *****************************************************************************/
static void Iomux_CLOCK_Init(void)
{
	// Init CLOCK pin function
	SetPinFunc_X0();
	SetPinFunc_X1();
	SetPinFunc_X1A();
	SetPinFunc_X0A();
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes CLOCK
 **
 *****************************************************************************/
static void Iomux_CLOCK_DeInit(void)
{
	// DeInit CLOCK pin function
}



/**
 *****************************************************************************
 ** \brief This function initializes DEBUG
 **
 *****************************************************************************/
static void Iomux_DEBUG_Init(void)
{
	// Init DEBUG pin function
	PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 17u, 1u, 0x1u );
	bFM_GPIO_PFR0_P0 = 1u;
	PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 16u, 1u, 0x1u );
	bFM_GPIO_PFR0_P1 = 1u;
	PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 16u, 1u, 0x1u );
	bFM_GPIO_PFR0_P4 = 1u;
	PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 17u, 1u, 0x1u );
	bFM_GPIO_PFR0_P2 = 1u;
	PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 16u, 1u, 0x1u );
	bFM_GPIO_PFR0_P3 = 1u;
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes DEBUG
 **
 *****************************************************************************/
static void Iomux_DEBUG_DeInit(void)
{
	// DeInit DEBUG pin function
}


/**
 *****************************************************************************
 ** \brief This function initializes CAN
 **
 *****************************************************************************/
static void Iomux_CAN_Init(void)
{
	// Init CAN pin function
	SetPinFunc_TX1_1();
	SetPinFunc_RX1_1();
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes CAN
 **
 *****************************************************************************/
static void Iomux_CAN_DeInit(void)
{
	// DeInit CAN pin function
}


/**
 *****************************************************************************
 ** \brief This function initializes EXTBUS
 **
 *****************************************************************************/
static void Iomux_EXTBUS_Init(void)
{
	// Init EXTBUS pin function
	SetPinFunc_MAD20_0();
	SetPinFunc_MAD19_0();
	SetPinFunc_MDQM1_0();
	SetPinFunc_MOEX_0();
	SetPinFunc_MADATA01_0();
	SetPinFunc_MADATA00_0();
	SetPinFunc_MADATA05_0();
	SetPinFunc_MADATA04_0();
	SetPinFunc_MADATA03_0();
	SetPinFunc_MADATA02_0();
	SetPinFunc_MADATA07_0();
	SetPinFunc_MADATA06_0();
	SetPinFunc_MADATA14_0();
	SetPinFunc_MADATA12_0();
	SetPinFunc_MADATA13_0();
	SetPinFunc_MADATA10_0();
	SetPinFunc_MADATA11_0();
	SetPinFunc_MADATA08_0();
	SetPinFunc_MADATA09_0();
	SetPinFunc_MDQM0_0();
	SetPinFunc_MWEX_0();
	SetPinFunc_MADATA15_0();
	SetPinFunc_MAD10_0();
	SetPinFunc_MAD07_0();
	SetPinFunc_MAD11_0();
	SetPinFunc_MAD06_0();
	SetPinFunc_MAD05_0();
	SetPinFunc_MAD12_0();
	SetPinFunc_MAD13_0();
	SetPinFunc_MAD08_0();
	SetPinFunc_MAD09_0();
	SetPinFunc_MAD01_0();
	SetPinFunc_MAD03_0();
	SetPinFunc_MAD02_0();
	SetPinFunc_MAD15_0();
	SetPinFunc_MAD16_0();
	SetPinFunc_MAD17_0();
	SetPinFunc_MAD18_0();
	SetPinFunc_MAD14_0();
	SetPinFunc_MAD04_0();
	SetPinFunc_MCSX0_0();
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes EXTBUS
 **
 *****************************************************************************/
static void Iomux_EXTBUS_DeInit(void)
{
	// DeInit EXTBUS pin function
}


/**
 *****************************************************************************
 ** \brief This function initializes USB
 **
 *****************************************************************************/
static void Iomux_USB_Init(void)
{
	// Init USB pin function
	SetPinFunc_UHCONX0();
	SetPinFunc_UDM0();
	SetPinFunc_UDP0();
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes USB
 **
 *****************************************************************************/
static void Iomux_USB_DeInit(void)
{
	// DeInit USB pin function
}


/**
 *****************************************************************************
 ** \brief This function initializes GPIO
 **
 *****************************************************************************/
static void Iomux_GPIO_Init(void)
{
	// Init GPIO pin function
	Gpio1pin_InitOut( GPIO1PIN_P1A, Gpio1pin_InitVal( 1u ) );
	Gpio1pin_InitOut( GPIO1PIN_P18, Gpio1pin_InitVal( 0u ) );
	Gpio1pin_InitOut( GPIO1PIN_PB2, Gpio1pin_InitVal( 0u ) );
}

/**
 *****************************************************************************
 ** \brief This function DeInitializes GPIO
 **
 *****************************************************************************/
static void Iomux_GPIO_DeInit(void)
{
	// DeInit GPIO pin function
}

/**
 *****************************************************************************
 ** \brief This function initializes the GPIO ports and peripheral pin
 **        functions according to the user settings of the Pin Wizard.
 **
 *****************************************************************************/
void Iomux_Init(void)
{
	Iomux_CLOCK_Init();

	Iomux_DEBUG_Init();

	Iomux_CAN_Init();

	Iomux_EXTBUS_Init();

	Iomux_USB_Init();

	Iomux_GPIO_Init();
}

/**
 *****************************************************************************
 ** \brief This function de-initializes the GPIO ports and peripheral pin
 **        functions according to the user settings of the Pin Wizard to the
 **        default values.
 **
 *****************************************************************************/
void Iomux_DeInit(void)
{
	Iomux_CLOCK_DeInit();

	Iomux_DEBUG_DeInit();

	Iomux_CAN_DeInit();

	Iomux_EXTBUS_DeInit();

	Iomux_USB_DeInit();

	Iomux_GPIO_DeInit();
}

//@} // IomuxGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
