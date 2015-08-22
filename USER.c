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
    
    RedLEDTris          = OUTPUT;
    
    MSC_RGBRedLEDOFF();
    MSC_RGBGreenLEDOFF();
    MSC_RGBBlueLEDOFF();
    RGB_RedLEDTris      = OUTPUT;
    RGB_GreenLEDTris    = OUTPUT;
    RGB_BlueLEDTris     = OUTPUT;
    
    /* SuperCap */
    ChargeCapTris       = OUTPUT;
    SCP_Charge(TRUE);   // charge the capacitor
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
    
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/