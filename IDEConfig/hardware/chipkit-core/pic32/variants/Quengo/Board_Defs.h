/************************************************************************/
/*																		*/
/*	Board_Defs.h --	CmodCK1 Board Customization Declarations			*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with a CmodCK1 board using a	*/
/* PIC32 part in a 44-pin package.										*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	10/07/2011(GeneA): Created											*/
/*	11/28/2011(GeneA): Moved data definitions and configuration			*/
/*		functions to Board_Data.c										*/
/*	11/29/2011(GeneA): Moved int priority definitions to System_Defs.h	*/
/*  01/23/2013(KeithV): Modified for CK1 board                          */
/*  03/26/2013(KeithV): Modified for DP32 board                         */
/*	05/27/2013(ClaudiaGoga): Fixed MISO, MOSI definitions.       		*/
/*							Added definitions to support PPS for SPI1	*/
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define _BOARD_NAME_ "Quengo"

// Definitions for old chipKIT core
// #define CDCACM_MAN "Undefined"
// #define CDCACM_PROD "Quengo"
// #define CDCACM_AUTOSERIAL 1

/* Define the peripherals available on the board.*/
#define NUM_DIGITAL_PINS 31 // Ao invés de 30
#define NUM_ANALOG_PINS 1   // Existem configurações que não estão definidos para 0
#define NUM_OC_PINS 5       // Precisaremos deste tipo de pino
#define NUM_IC_PINS 5       // Precisaremos deste tipo de pino
#define NUM_TCK_PINS 5      // Precisaremos deste tipo de pino
#define NUM_INT_PINS 5      // Precisaremos deste tipo de pino

#define NUM_SERIAL_PORTS 2 // see comment on serial Port 2 below
#define NUM_SPI_PORTS 1    // Precisaremos de 1 para o sensor de fluxo ótico
#define NUM_I2C_PORTS 1

#define NUM_DSPI_PORTS 2
#define NUM_DTWI_PORTS 2

/* Define I/O devices on the board.
 */
// Nessa placa não precisa
#define NUM_LED 2
#define NUM_BTN 1
#define NUM_SWT 0
#define NUM_SERVO 0

// Set the default SPI port to the 6 pin header
#define _SPI_PORT 1

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
 */
#define PIN_LED1 12 // RA7
#define PIN_LED2 16 // RA10

// #define PIN_LED_TX  23
// #define PIN_LED_RX  24

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* One button (PRG) for this board
 */
#define PIN_BTN1 17 // 17  RB13.

/* Also define the virutal program button for soft reset */
#define USE_VIRTUAL_PROGRAM_BUTTON 1
#define VIRTUAL_PROGRAM_BUTTON_TRIS TRISBbits.TRISB13
#define VIRTUAL_PROGRAM_BUTTON LATBbits.LATB13

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
 */

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
 */

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1 27 // RPC7
#define PIN_OC2 19 // RPB8
#define PIN_OC3 25 // RPB9
#define PIN_OC4 8  // RPC3
#define PIN_OC5 10

#define PIN_IC1 4
#define PIN_IC2 14 // RPB10 (IC2R = 3)
#define PIN_IC3 7  // RPA9 (IC3R = 7)
#define PIN_IC4 5  // RPB4 (IC4R = 2)
#define PIN_IC5 11

#define PIN_TCK1 6  // RA4
#define PIN_TCK2 20 // RPC0 (T1CKR = 6)
#define PIN_TCK3 4  // RPA8 (T1CKR = 5)
#define PIN_TCK4 6
#define PIN_TCK5 9 // RC4

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define PIN_INT0 18 // RB7 RB7 fixed not a pps pin
#define PIN_INT1 22 // RPC9
#define PIN_INT2 26 // RPC6
#define PIN_INT3 30 // RPA1
#define PIN_INT4 10 // RC5

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h.
*/
static const uint8_t SS = 2;    // RB15 SS1
static const uint8_t MISO = 15; // RB11 SDI1
static const uint8_t MOSI = 13; // RC8 SDO1
static const uint8_t SCK = 3;   // RB14 SCK1 //   Não é PPS

/* The Digilent DSPI library uses these ports.
 */
// #define	PIN_DSPI0_SS	10
// #define	PIN_DSPI1_SS	 9
/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
// #define	A0		1 // RA0
// #define	A1		27 // RA1
// #define A4		28 // RB2
// #define A5		29 // RB3
// #define A9      2 // RB15
// #define A10     3 // RB14
// #define A11     0 // RC1

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
// ???
#define PIN_CN0 0   //  0   J4-1    RB5     TMS/RPB5/USBID/RB5
#define PIN_CN1 1   //  1   J4-2    RB7     TDI/RPB7/CTED3/PMD5/INT0/RB7
#define PIN_CN2 2   //  2   J4-3    RB8     TCK/RPB8/SCL1/CTED10/PMD4/RB8
#define PIN_CN3 3   //  3   J4-4    RB9     TDO/RPB9/SDA1/CTED4/PMD3/RB9
#define PIN_CN4 4   //  4   J4-5    RB10    PGED2/RPB10/D+/CTED11/RB10
#define PIN_CN5 5   //  5   J4-6    RB11    PGEC2/RPB11/D-/RB11
#define PIN_CN6 6   //  6   J4-7    RB13    AN11/RPB13/CTPLS/PMRD/RB13
#define PIN_CN7 7   //  7   J4-8    RB14    CVREF/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14
#define PIN_CN8 8   //  8   J4-9    RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
#define PIN_CN9 9   //  9   J3-1    RA0     PGED3/VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/PMD7/RA0
#define PIN_CN10 10 // 10   J3-2    RA1     PGEC3/VREF-/CVREF-/AN1/RPA1/CTED2/PMD6/RA1
#define PIN_CN11 11 // 11   J3-3    RB0     PGED1/AN2/C1IND/C2INB/C3IND/RPB0/PMD0/RB0
#define PIN_CN12 12 // 12   J3-4    RB1     PGEC1/AN3/C1INC/C2INA/RPB1/CTED12/PMD1/RB1
#define PIN_CN13 13 // 13   J3-5    RB2     AN4/C1INB/C2IND/RPB2/SDA2/CTED13/PMD2/RB2
#define PIN_CN14 14 // 14   J3-6    RB3     AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/RB3
#define PIN_CN15 15 // 15   J3-7    RA2     OSC1/CLKI/RPA2/RA2
#define PIN_CN16 16 // 16   J3-8    RA3     OSC2/CLKO/RPA3/PMA0/RA3
#define PIN_CN17 17 // 17   J3-9    RB4     SOSCI/RPB4/RB4
#define PIN_CN18 18 // 18   J3-10   RA4     SOSCO/RPA4/T1CK/CTED9/PMA1/RA4

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#undef digitalPinToAnalog
#define digitalPinToAnalog(P) ((P) < 6 ? digital_pin_to_analog_PGM[14 + P] : digital_pin_to_analog_PGM[P])
extern const uint8_t digital_pin_to_analog_PGM[];

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])

/* ------------------------------------------------------------ */
/*					Data Definitions							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t port_to_tris_PGM[];
extern const uint8_t digital_pin_to_port_PGM[];
extern const uint16_t digital_pin_to_bit_mask_PGM[];
extern const uint16_t digital_pin_to_timer_PGM[];
extern const uint8_t digital_pin_to_pps_out_PGM[];
extern const uint8_t digital_pin_to_pps_in_PGM[];
extern const uint8_t analog_pin_to_channel_PGM[];

extern const uint8_t output_compare_to_digital_pin_PGM[];
extern const uint8_t external_int_to_digital_pin_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define OPT_BOARD_INIT 1         // board needs special init code
#define OPT_BOARD_DIGITAL_IO 0   // board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ 0  // board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE 0 // board does not extend analogWrite

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

#define       _SER0_BASE           _UART1_BASE_ADDRESS
#define       _SER0_IRQ            _UART1_ERR_IRQ
#define       _SER0_VECTOR         _UART_1_VECTOR
#define       _SER0_IPL_ISR        IPL2SOFT
#define       _SER0_IPL            2
#define       _SER0_SPL            0
#define       _SER0_TX_OUT         PPS_OUT_U1TX     // RPB3R = U1TX = 1   
#define       _SER0_TX_PIN         1                // RB4
#define       _SER0_RX_IN          PPS_IN_U1RX      // U1RXR = RA4 = 0
#define       _SER0_RX_PIN         0                // RA4 


/* Serial port 1 uses UART2
*/
#define       _SER1_BASE           _UART2_BASE_ADDRESS
#define       _SER1_IRQ            _UART2_ERR_IRQ
#define       _SER1_VECTOR         _UART_2_VECTOR
#define       _SER1_IPL_ISR        IPL2SOFT
#define       _SER1_IPL            2
#define       _SER1_SPL            0
#define       _SER1_TX_OUT         PPS_OUT_U2TX     // RPB0R = U2TX = 5
#define       _SER1_TX_PIN         23                // RB0
#define       _SER1_RX_IN          PPS_IN_U2RX      // U2RXR = RPB1 = 4
#define       _SER1_RX_PIN         24                // RB1

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The default SPI port uses SPI1.
 */
// #define	_SPI_BASE		_SPI2_BASE_ADDRESS
// #define _SPI_ERR_IRQ	_SPI2_ERR_IRQ
// #define	_SPI_RX_IRQ		_SPI2_RX_IRQ
// #define	_SPI_TX_IRQ		_SPI2_TX_IRQ
// #define	_SPI_VECTOR		_SPI_2_VECTOR
// #define	_SPI_IPL_ISR	_SPI2_IPL_ISR
// #define	_SPI_IPL		_SPI2_IPL_IPC
// #define	_SPI_SPL		_SPI2_SPL_IPC

/* SPI pin declarations
 */
// #define _SPI_MISO_IN	PPS_IN_SDI2
// #define	_SPI_MISO_PIN	12
// #define _SPI_MOSI_OUT	PPS_OUT_SDO2
// #define	_SPI_MOSI_PIN	11

// /* SPI1
// */

// #define	_DSPI0_BASE			_SPI1_BASE_ADDRESS
// #define	_DSPI0_ERR_IRQ		_SPI1_ERR_IRQ
// #define	_DSPI0_RX_IRQ		_SPI1_RX_IRQ
// #define	_DSPI0_TX_IRQ		_SPI1_TX_IRQ
// #define	_DSPI0_VECTOR		_SPI_1_VECTOR
// #define	_DSPI0_IPL_ISR		_SPI1_IPL_ISR
// #define	_DSPI0_IPL			_SPI1_IPL_IPC
// #define	_DSPI0_SPL			_SPI1_SPL_IPC

// #define _DSPI0_MISO_IN		PPS_IN_SDI1
// #define _DSPI0_MISO_PIN		12
// #define _DSPI0_MOSI_OUT		PPS_OUT_SDO1
// #define _DSPI0_MOSI_PIN		11

// /* SPI2
// */
// #define	_DSPI1_BASE			_SPI2_BASE_ADDRESS
// #define	_DSPI1_ERR_IRQ		_SPI2_ERR_IRQ
// #define	_DSPI1_RX_IRQ		_SPI2_RX_IRQ
// #define	_DSPI1_TX_IRQ		_SPI2_TX_IRQ
// #define	_DSPI1_VECTOR		_SPI_2_VECTOR
// #define	_DSPI1_IPL_ISR		_SPI2_IPL_ISR
// #define	_DSPI1_IPL			_SPI2_IPL_IPC
// #define	_DSPI1_SPL			_SPI2_SPL_IPC

// #define _DSPI1_MISO_IN		PPS_IN_SDI2
// #define _DSPI1_MISO_PIN		25
// #define _DSPI1_MOSI_OUT		PPS_OUT_SDO2
// #define _DSPI1_MOSI_PIN		27

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C1 port uses I2C1 (SCL1/SDA1).
** RB8/RB9 pins 38/4
// */
// #define _TWI_BASE _I2C2_BASE_ADDRESS
// #define _TWI_BUS_IRQ _I2C2_BUS_IRQ
// #define _TWI_SLV_IRQ _I2C2_SLAVE_IRQ
// #define _TWI_MST_IRQ _I2C2_MASTER_IRQ
// #define _TWI_VECTOR _I2C_2_VECTOR
// #define _TWI_IPL_ISR _I2C2_IPL_ISR
// #define _TWI_IPL _I2C2_IPL_IPC
// #define _TWI_SPL _I2C2_SPL_IPC

// #define _DTWI1_BASE _I2C2_BASE_ADDRESS
// #define _DTWI1_BUS_IRQ _I2C2_BUS_IRQ
// #define _DTWI1_VECTOR _I2C_2_VECTOR
// #define _DTWI1_IPL_ISR IPL3SOFT
// #define _DTWI1_IPL 3
// #define _DTWI1_SPL 0
// #define _DTWI1_SCL_PIN A5
// #define _DTWI1_SDA_PIN A4

// #define _DTWI0_BASE _I2C1_BASE_ADDRESS
// #define _DTWI0_BUS_IRQ _I2C1_BUS_IRQ
// #define _DTWI0_VECTOR _I2C_1_VECTOR
// #define _DTWI0_IPL_ISR IPL3SOFT
// #define _DTWI0_IPL 3
// #define _DTWI0_SPL 0
// #define _DTWI0_SCL_PIN 29
// #define _DTWI0_SDA_PIN 28

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */

#endif // BOARD_DEFS_H

/************************************************************************/
