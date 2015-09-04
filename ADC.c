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
#include "POWER.h"

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
    AD1CON2bits.VCFG = 0x000; // reference voltage is AVDD and AVSS
    AD1CON3bits.ADCS = 0b00111111; // 64 * TCY ~1.6uS
    ADC_ModuleON();
}

/******************************************************************************/
/* ADC_ReadChannel
 *
 * The function reads an ADC channel and returns the voltage.
/******************************************************************************/
double ADC_ReadChannel(unsigned char channel)
{
    int RawCounts = 0;
    double Voltage = 0.0;

    AD1CHSbits.CH0SB = channel;
    AD1CHSbits.CH0SA = channel;
    AD1CON1bits.SAMP = TRUE; // sample the input
    MSC_DelayUS(1000);
    AD1CON1bits.SAMP = FALSE; // sample the input
    AD1CON1bits.DONE = 0;
    while(!AD1CON1bits.DONE);
    RawCounts = ADC1BUF0;
    Voltage = ((double) RawCounts * VREF) / (1<<ADC_BITS);
    
    return Voltage;
}
/******************************************************************************/
/* ADC_ReadVIN
 *
 * The function reads the input voltage.
/******************************************************************************/
void ADC_ReadVIN(void)
{
    RailStatus.VIN = (ADC_ReadChannel(ADC_VIN_AN) * (R28 + R29)) / R29;
}

/******************************************************************************/
/* ADC_ReadVolt5_0
 *
 * The function reads the 5.0 volt rail.
/******************************************************************************/
void ADC_ReadVolt5_0(void)
{
    RailStatus.Volt5_0 = (ADC_ReadChannel(ADC_Volt5_0_AN) * (R26 + R27)) / R27;
}

/******************************************************************************/
/* ADC_ReadVolt3_3
 *
 * The function reads the 3.3 volt rail.
/******************************************************************************/
void ADC_ReadVolt3_3(void)
{
    RailStatus.Volt3_3 = (ADC_ReadChannel(ADC_Volt3_3_AN) * (R30 + R31)) / R31;
}

/******************************************************************************/
/* ADC_ReadVolt4_1
 *
 * The function reads the 4.1 volt rail.
/******************************************************************************/
void ADC_ReadVolt4_1(void)
{
    RailStatus.Volt4_1 = (ADC_ReadChannel(ADC_Volt4_1_AN) * (R32 + R33)) / R33;
}

/******************************************************************************/
/* ADC_ReadVCAP
 *
 * The function reads the VCAP volt rail which is the voltage of the capacitor.
/******************************************************************************/
void ADC_ReadVCAP(void)
{
    RailStatus.VCAP = (ADC_ReadChannel(ADC_VCAP_AN) * (R34 + R35)) / R35;
}

/******************************************************************************/
/* ADC_ReadRails
 *
 * The function reads the 5 voltage rails.
/******************************************************************************/
void ADC_ReadRails(void)
{
    ADC_ReadVIN();
    ADC_ReadVCAP();
    ADC_ReadVolt3_3();
    ADC_ReadVolt4_1();
    ADC_ReadVolt5_0();
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/