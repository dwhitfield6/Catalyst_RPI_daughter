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
/* Contains Functions for PIC initialization
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include <stdio.h>         /* For sprintf definition */

#include "USER.h"
#include "MISC.h"
#include "PWM.h"
#include "TIMERS.h"
#include "SUPERCAP.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* Init_App
 *
 * The function initializes the application. It sets the pins and pull-ups.
/******************************************************************************/
void Init_App(void)
{
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
    LATF = 0;
    LATG = 0;
    
    /* Set all pins as digital */
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    ANSELG = 0;
    
    /*~~~~~~~~~~~~~ Red LED ~~~~~~~~~~~~~~~~~*/
    RedLEDTris          = OUTPUT;
    
    /*~~~~~~~~~~~~~ RGB LED ~~~~~~~~~~~~~~~~~*/
    MSC_RGBRedLEDOFF();
    MSC_RGBGreenLEDOFF();
    MSC_RGBBlueLEDOFF();
    RGB_RedLEDTris      = OUTPUT;
    RGB_GreenLEDTris    = OUTPUT;
    RGB_BlueLEDTris     = OUTPUT;
    
    /*~~~~~~~~~~~~~ SuperCap ~~~~~~~~~~~~~~~~~*/
    SCP_Charge(TRUE);   // charge the capacitor
    ChargeCapTris       = OUTPUT;
    
    /*~~~~~~~~~~~~~ DCDC ~~~~~~~~~~~~~~~~~*/
    SCP_Volts5(ON);
    InhibitTris         = OUTPUT;
    
    /*~~~~~~~~~~~~~ Raspberry pi ~~~~~~~~~~~~~~~~~*/
    /* Raspberry pi rail */
    SCP_RASP_ON(OFF);
    RASP_ONTris         = OUTPUT;
    RASP_ON2Tris        = INPUT;
    
    /* Raspberry pi connected detector */
    RASP_ConnectedTris  = INPUT;
    SCP_RASP_Connected();
    
    /*~~~~~~~~~~~~~ Voltages rails for ADC ~~~~~~~~~~~~~~~~~*/
    ADC_Volt5Tris       = INPUT;
    ADC_Volt3_3Tris     = INPUT;
    ADC_Volt4_1Tris     = INPUT;
    ADC_VINTris         = INPUT;
    ADC_VCAPTris        = INPUT;
    ADC_VREF_posTris    = INPUT;
    ADC_VREF_negTris    = INPUT;
    
    /* select the ADC channels and references as analog */
    ANSELB              |= (ADC_Volt5 + ADC_Volt3_3 + ADC_Volt4_1 + ADC_VIN + ADC_VCAP);
    ANSELA              |= ADC_VREF_pos;
}

/******************************************************************************/
/* Init_System
 *
 * The function initializes the modules.
/******************************************************************************/
void Init_System(void)
{
    INTCONbits.MVEC = TRUE; // Multi-vectored interrupts
    __builtin_enable_interrupts();
    InitTIMERS();
    InitPWM();
    InitADC();
    
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/