/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 08/21/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Contains functions for Analog to Digital converter.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "ADC.h"
#include "SUPERCAP.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* ADC_ModuleOFF
 *
 * The function turns off the ADC module.
/******************************************************************************/
inline void ADC_ModuleOFF(void)
{
#ifdef ON
    #undef ON
    AD1CON1bits.ON = 0;
    #define ON 1
#else
    AD1CON1bits.ON = 0;
#endif
}

/******************************************************************************/
/* ADC_ModuleON
 *
 * The function turns on the ADC module.
/******************************************************************************/
inline void ADC_ModuleON(void)
{
#ifdef ON
    #undef ON
    AD1CON1bits.ON = 1;
    #define ON 1
#else
    AD1CON1bits.ON = 1;
#endif
}


/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitADC
 *
 * The function initializes the analog to digital converter.
/******************************************************************************/
void InitADC(void)
{
    ADC_ModuleOFF();
    AD1CON2bits.VCFG = 0x001; // reference voltage is VREF+ and AVSS
    AD1CON3bits.ADCS = 0b00111111; // 64 * TCY ~1.6uS
    ADC_ModuleON();
}

/******************************************************************************/
/* ADC_ReadVIN
 *
 * The function reads the input voltage.
/******************************************************************************/
void ADC_ReadVIN(void)
{
    int RawCounts = 0;
    double Voltage = 0.0;

    AD1CHSbits.CH0SB = ADC_VIN_AN;
    AD1CHSbits.CH0SA = ADC_VIN_AN;
    AD1CON1bits.SAMP = TRUE; // sample the input
    MSC_DelayUS(1000);
    AD1CON1bits.SAMP = FALSE; // sample the input
    AD1CON1bits.DONE = 0;
    while(!AD1CON1bits.DONE);
    RawCounts = ADC1BUF0;
    Voltage = ((double) RawCounts * VREF) / (1<<ADC_BITS);
    RailStatus.VIN = (Voltage * (R28 + R29)) / R29;
}

/******************************************************************************/
/* ADC_ReadVolt3_3
 *
 * The function reads the 3.3 volt rail.
/******************************************************************************/
void ADC_ReadVolt3_3(void)
{
    int RawCounts = 0;
    double Voltage = 0.0;

    AD1CHSbits.CH0SB = ADC_Volt3_3_AN;
    AD1CHSbits.CH0SA = ADC_Volt3_3_AN;
    AD1CON1bits.SAMP = TRUE; // sample the input
    MSC_DelayUS(1000);
    AD1CON1bits.SAMP = FALSE; // sample the input
    AD1CON1bits.DONE = 0;
    while(!AD1CON1bits.DONE);
    RawCounts = ADC1BUF0;
    Voltage = ((double) RawCounts * VREF) / (1<<ADC_BITS);
    RailStatus.Volt3_3 = (Voltage * (R30 + R31)) / R31;
}

/******************************************************************************/
/* ADC_ReadRails
 *
 * The function reads the 5 voltage rails.
/******************************************************************************/
void ADC_ReadRails(void)
{
    ADC_ReadVIN();
    ADC_ReadVolt3_3();
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/