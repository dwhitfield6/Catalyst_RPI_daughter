/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 08/21/15     1.0_DW0a    Initial project make.
 *                          Derived from project 'PIC_Sitcom_Generator'.
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#ifndef MISC_H
#define	MISC_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "SYSTEM.h"

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define Even        2
#define Odd         3
#define NOCOMMA     1
#define DOUBLECOMMA 2
#define NOVALUE     3
#define TOOBIG      4
#define NEGATIVE    5
#define NoError     0

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/*~~~~~~~~~~~~~~~~~~~~~~~~~ RED LED ~~~~~~~~~~~~~~~~~~~~~~~~~*/
/******************************************************************************/
/* MSC_RedLEDON
 *
 * The function turns on the Red LED.
/******************************************************************************/
#define MSC_RedLEDON()  (LATD |= RedLED)

/******************************************************************************/
/* MSC_RedLEDOFF
 *
 * The function turns off the Red LED.
/******************************************************************************/
#define MSC_RedLEDOFF()  (LATD &= ~RedLED)

/******************************************************************************/
/* MSC_RedLEDTOGGLE
 *
 * The function toggles the Red LED.
/******************************************************************************/
#define MSC_RedLEDTOGGLE()  (LATD ^= RedLED)

/*~~~~~~~~~~~~~~~~~~~~~~~~~ RGB LED ~~~~~~~~~~~~~~~~~~~~~~~~~*/
/******************************************************************************/
/* MSC_RGBRedLEDON
 *
 * The function turns on the RGB Red LED.
/******************************************************************************/
#define MSC_RGBRedLEDON()  (LATD |= RGB_RedLED)

/******************************************************************************/
/* MSC_RGBGreenLEDON
 *
 * The function turns on the RGB Green LED.
/******************************************************************************/
#define MSC_RGBGreenLEDON()  (LATB |= RGB_GreenLED)

/******************************************************************************/
/* MSC_RGBBlueLEDON
 *
 * The function turns on the RGB Blue LED.
/******************************************************************************/
#define MSC_RGBBlueLEDON()  (LATD |= RGB_BlueLED)

/******************************************************************************/
/* MSC_RGBRedLEDOFF
 *
 * The function turns off the RGB Red LED.
/******************************************************************************/
#define MSC_RGBRedLEDOFF()  (LATD &= ~RGB_RedLED)

/******************************************************************************/
/* MSC_RGBGreenLEDOFF
 *
 * The function turns off the RGB Green LED.
/******************************************************************************/
#define MSC_RGBGreenLEDOFF()  (LATB &= ~RGB_GreenLED)

/******************************************************************************/
/* MSC_RGBBlueLEDOFF
 *
 * The function turns off the RGB Blue LED.
/******************************************************************************/
#define MSC_RGBBlueLEDOFF()  (LATD &= ~RGB_BlueLED)

/******************************************************************************/
/* MSC_RGBRedLEDTOGGLE
 *
 * The function toggles the RGB Red LED.
/******************************************************************************/
#define MSC_RGBRedLEDTOGGLE()  (LATD ^= RGB_RedLED)

/******************************************************************************/
/* MSC_RGBGreenLEDTOGGLE
 *
 * The function toggles the RGB Green LED.
/******************************************************************************/
#define MSC_RGBGreenLEDTOGGLE()  (LATB ^= RGB_GreenLED)

/******************************************************************************/
/* MSC_RGBBlueLEDTOGGLE
 *
 * The function toggles the RGB Blue LED.
/******************************************************************************/
#define MSC_RGBBlueLEDTOGGLE()  (LATD ^= RGB_BlueLED)

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
inline void MSC_Relay(unsigned char state);
void MSC_DelayUS(long US);
unsigned char MSC_IsCharacter(unsigned char data);
void MSC_CleanBuffer(void* data, unsigned short bytes);
void MSC_CleanBufferChar(unsigned char* data, unsigned short count);
void MSC_CleanBufferInt(unsigned int* data, unsigned short count);
double MSC_Round(double input);
void MSC_StringCopy(unsigned char* from,unsigned char* to);
void MSC_BufferCopy(unsigned char* from,unsigned char* to, unsigned short count, unsigned short shift);
unsigned char MSC_StringMatch(void* This, void* That);
unsigned char MSC_StringMatchCaseInsensitive(const unsigned char* This, const unsigned char* That);
unsigned char MSC_StringContains(const unsigned char* This, const unsigned char* That);
unsigned char MSC_StringContainsCaseInsensitive(const unsigned char* This, const unsigned char* That);
void MSC_LowercaseChar(unsigned char* Input);
void MSC_LowercaseString(unsigned char* Input);
void MSC_DelayNOP(unsigned char NOPs);
unsigned char MSC_ReverseByte(unsigned char This);
unsigned short MSC_ReverseInt(unsigned short This);
unsigned long MSC_ReverseLong(unsigned long This);
unsigned char MSC_GetNumber(unsigned char* This, unsigned char CommaNumber, long* result);
unsigned char MSC_StringAddEqual(unsigned char* Input);
unsigned char MSC_GetStringAfterComma(unsigned char* This, unsigned char CommaNumber, unsigned char* result);
unsigned char MSC_GetNumberUnsigned(unsigned char* This, unsigned char CommaNumber, unsigned long* result);
unsigned char MSC_IsAlphaNumericString(unsigned char* data);
unsigned char MSC_IsAlphaNumeric(unsigned char data);
unsigned char MSC_IsNumber(unsigned char data);
double MSC_DB_Round(double Input);
long MSC_Scale(long Input, long InputRangeLow, long InputRangeHigh, long OutputRangeLow, long OutputRangeHigh);
unsigned short MSC_BCDtoHEX(unsigned short input);
unsigned short MSC_HEXtoBCD(unsigned short input);
unsigned char MSC_BufferMatch(unsigned char* This, unsigned char* That, unsigned short size);
long MSC_LG_Round(long Input,unsigned char places);
void MSC_TestFunctionPointer(void);
unsigned short MSC_EndianInt(unsigned short number);
unsigned short MSC_EndianIntArray(unsigned char* buffer);
unsigned long MSC_EndianLong(unsigned long number);
unsigned long MSC_EndianLongArray(unsigned char* buffer);

#endif	/* MISC_H */