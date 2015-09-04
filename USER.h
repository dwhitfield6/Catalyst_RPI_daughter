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
/* Firmware Version
/******************************************************************************/
#define CPU_VERSION    "63"
#define CPU_REVISION   "00"
#define CPU_ALPHA      ""                 /* use "" for no alpha.  */ 
#define CPU_BRANCH     "DW0a"                 /* use "" for no branch. */

/******************************************************************************/
/* PCB board
 *
 * This code is used with boards:
 * 1. Catalyst_PCB_revA             (use configuration "PCB_A__pic32MX350F128L")
/******************************************************************************/
#define Catalyst_PCB_revA

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

/* Connected to a UART RX on Rasberry pi */
#define RASP_UART_TXTris	TRISCbits.TRISC4
#define RASP_UART_TX 0x00000010        // RC4 used as U1TX
#define RASP_UART_TX_Module 0b0011     // RPnR Value for U1TX

#define RASP_UART_TX2Tris	TRISCbits.TRISC3
#define RASP_UART_TX2 0x00000008        // RC3

/* Connected to a UART TX on Rasberry pi */
#define RASP_UART_RXTris	TRISBbits.TRISB9
#define RASP_UART_RX 0x00000010        // RB9 used as U1RX
#define RASP_UART_RX_Pin 0b0101        // U1RX is pin RPB9

/************* Voltage rails for ADC read *************/
/* Connected to the voltage divider to read the 5 volt rail */
#define ADC_Volt5_0Tris	TRISBbits.TRISB5
#define ADC_Volt5_0 0x00000020    //RB5 used as AN5
#define ADC_Volt5_0_AN 5          //AN5

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

/************* RS-232 UART channels *************/
/* Connected to the rs232 driver shutdown for the male DB9 */
#define RS232_MALE_SHUTDOWNTris	TRISAbits.TRISA7
#define RS232_MALE_SHUTDOWN 0x00000080  // RA7

/* Connected to the rs232 driver enable for the male DB9 */
#define RS232_MALE_ENABLETris	TRISDbits.TRISD7
#define RS232_MALE_ENABLE 0x00000080  // RD7

/* Connected to the rs232 driver shutdown for the female DB9 */
#define RS232_FEMALE_SHUTDOWNTris	TRISDbits.TRISD13
#define RS232_FEMALE_SHUTDOWN 0x00000080  // RD13

/* Connected to the rs232 driver enable for the female DB9 */
#define RS232_FEMALE_ENABLETris	TRISDbits.TRISD6
#define RS232_FEMALE_ENABLE 0x00000040  // RD6

/* Connected to the transmit of the JP2 male DB9 */
#define RS232_MALE_TXTris	TRISFbits.TRISF5
#define RS232_MALE_TX 0x00000020        // RF5 used as U2TX
#define RS232_MALE_TX_Module 0b0001     // RPnR Value for U2TX

/* Connected to the receive of the JP2 male DB9 */
#define RS232_MALE_RXTris	TRISFbits.TRISF2
#define RS232_MALE_RX 0x00000004        // RF2 used as U2RX
#define RS232_MALE_RX_Pin 0b1111        // U2RX is pin RPF2

/* Connected to the RTS of the JP2 male DB9 used as second TX */
#define RS232_MALE_RTSTris	TRISDbits.TRISD14
#define RS232_MALE_RTS 0x00004000        // RD14 used as U3TX
#define RS232_MALE_RTS_Module 0b0001     // RPnR Value for U3TX

/* Connected to the RTS of the JP2 male DB9 used as second RX */
#define RS232_MALE_CTSTris	TRISFbits.TRISF7
#define RS232_MALE_CTS 0x00000080        // RF7 used as U3RX
#define RS232_MALE_CTS_Pin 0b1111        // U3RX is pin RPF7


/* Connected to the transmit of the JP1 female DB9 */
#define RS232_FEMALE_TXTris	TRISFbits.TRISF12
#define RS232_FEMALE_TX 0x00001000        // RF12 used as U4TX
#define RS232_FEMALE_TX_Module 0b0010     // RPnR Value for U4TX

#define RS232_FEMALE_TX2Tris	TRISBbits.TRISB12
#define RS232_FEMALE_TX2 0x00001000       // RB12

/* Connected to the receive of the JP1 female DB9 */
#define RS232_FEMALE_RXTris	TRISGbits.TRISG9
#define RS232_FEMALE_RX 0x00000200        // RG9 used as U4RX
#define RS232_FEMALE_RX_Pin 0b0001        // U4RX is pin RPG9

/* Connected to the RTS of the JP1 female DB9 used as second TX */
#define RS232_FEMALE_RTSTris	TRISFbits.TRISF8
#define RS232_FEMALE_RTS 0x00000100        // RF8 used as U5TX
#define RS232_FEMALE_RTS_Module 0b0100     // RPnR Value for U5TX

/* Connected to the RTS of the JP1 female DB9 used as second RX */
#define RS232_FEMALE_CTSTris	TRISCbits.TRISC2
#define RS232_FEMALE_CTS 0x00000004        // RC2 used as U5RX
#define RS232_FEMALE_CTS_Pin 0b1100        // U5RX is pin RPC2

#define RS232_FEMALE_CTS2Tris	TRISCbits.TRISC1
#define RS232_FEMALE_CTS2 0x00000002        // RC1

/******************************************************************************/
/* Version variables                                                          */
/******************************************************************************/
extern const unsigned char Version[];
extern const unsigned char Revision[];
extern const unsigned char Alpha[];
extern const unsigned char Branch_Version[];

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void Init_App(void);        
void Init_System (void);

#endif	/* USER_H */