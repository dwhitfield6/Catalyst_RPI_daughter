/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 07/28/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#ifndef USER_H
#define	USER_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

/******************************************************************************/
/* PCB board
 *
 * This code is used with boards:
 * 1. Catalyst_PCB_revA             (use configuration "PCB_A__pic32MX350F128L")
/******************************************************************************/
#define Catalyst_PCB_revA

/******************************************************************************/
/* Version
 *
 * This defines the Firmware version.
/******************************************************************************/
#define Version "1.0_DW0a"

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
#define INPUT 1
#define OUTPUT 0
#define PASS 1
#define FAIL 0
#define YES 1
#define NO 0

/******************************************************************************/
/* Pin Defines                                                                */
/******************************************************************************/

/************* Oscillator *************/
/* Connected to the secondary oscillator */
#define SOSCOTris	TRISBbits.TRISB4

/* Connected to the secondary oscillator */
#define SOSCITris	TRISAbits.TRISA4

/************* Red LED *************/
/* Connected to the red LED indicator */
#define RedLEDTris	TRISDbits.TRISD3
#define RedLED 0x00000008 //RD3

/************* RGB LED *************/
/* Connected to the RGB red LED indicator */
#define RGB_RedLEDTris	TRISDbits.TRISD2
#define RGB_RedLED 0x00000004 //RD2 used as OC3

/* Connected to the RGB Green LED indicator */
#define RGB_GreenLEDTris	TRISBbits.TRISB6
#define RGB_GreenLED 0x00000040 //RB6 used as OC2

/* Connected to the RGB Blue LED indicator */
#define RGB_BlueLEDTris	TRISDbits.TRISD1
#define RGB_BlueLED 0x00000002 //RD1 used as OC1

/************* Super Cap *************/
/* Connected to the power switch that charges the super capacitor */
#define ChargeCapTris	TRISDbits.TRISD9
#define ChargeCap 0x00000200 //RD9

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void Init_App(void);        
void Init_System (void);

#endif	/* USER_H */