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
#define k 1000.0

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

/************* DCDC *************/
/* Connected to the DC to DC converters inhibit pin */
#define InhibitTris	TRISDbits.TRISD0
#define Inhibit 0x00000001 //RD0

/************* Raspberry pi *************/
/* Connected to the power switch that controls the raspberry pi */
#define RASP_ONTris	TRISAbits.TRISA5
#define RASP_ON 0x00000020 //RA5

#define RASP_ON2Tris	TRISAbits.TRISA14
#define RASP_ON2 0x00004000 //RA14

/* Connected to a pull up pin to detect if a raspberry pi is mounted */
#define RASP_ConnectedTris	TRISGbits.TRISG7
#define RASP_Connected 0x00000080 //RG7

/************* Voltage rails for ADC read *************/
/* Connected to the voltage divider to read the 5 volt rail */
#define ADC_Volt5Tris	TRISBbits.TRISB5
#define ADC_Volt5 0x00000020    //RB5 used as AN5
#define ADC_Volt5_AN 5          //AN5

/* Connected to the voltage divider to read the VIN rail */
#define ADC_VINTris	TRISBbits.TRISB4
#define ADC_VIN 0x00000010    //RB4 used as AN4
#define ADC_VIN_AN 4          //AN4

/* Connected to the voltage divider to read the 3.3 volt rail */
#define ADC_Volt3_3Tris	TRISBbits.TRISB3
#define ADC_Volt3_3 0x00000008    //RB3 used as AN3
#define ADC_Volt3_3_AN 3          //AN3

/* Connected to the voltage divider to read the 4.1 volt rail */
#define ADC_Volt4_1Tris	TRISBbits.TRISB2
#define ADC_Volt4_1 0x00000004    //RB2 used as AN2
#define ADC_Volt4_1_AN 2          //AN2

/* Connected to the voltage divider to read the VCAP rail */
#define ADC_VCAPTris	TRISBbits.TRISB7
#define ADC_VCAP 0x00000080    //RB7 used as AN7
#define ADC_VCAP_AN 7          //AN7

/* Connected to the positive reference voltage */
#define ADC_VREF_posTris	TRISAbits.TRISA10
#define ADC_VREF_pos 0x00000400    //RA10 used as VREF+

/* Connected to the negative reference voltage */
#define ADC_VREF_negTris	TRISAbits.TRISA9
#define ADC_VREF_neg 0x00000200    //RA9 used as VREF-

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void Init_App(void);        
void Init_System (void);

#endif	/* USER_H */