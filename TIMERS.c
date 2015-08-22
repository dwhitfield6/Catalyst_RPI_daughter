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
/* Contains functions for timers.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "TIMERS.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions                                                           */
/******************************************************************************/

/******************************************************************************/
/* TMR_EnableTimer2
 *
 * Controls the Timer2 module.
/******************************************************************************/
inline void TMR_EnableTimer2(unsigned char action)
{
#ifdef ON
    #undef ON
    if (action)
    {
        T2CONbits.ON = 1; // Enable Timer
    }
    else
    {
        T2CONbits.ON = 0; // Disable Timer
    }
    #define ON 1
#else
    if (action)
    {
        T2CONbits.ON = 1; // Enable Timer
    }
    else
    {
        T2CONbits.ON = 0; // Disable Timer
    }
#endif

}

/******************************************************************************/
/* TMR_InterruptTimer2
 *
 * Controls the Timer2 interrupt.
/******************************************************************************/
inline void TMR_InterruptTimer2(unsigned char action)
{
    if (action)
    {
        IEC0bits.T2IE = 1; // Enable Timer 2 interrupt
    }
    else
    {
        IEC0bits.T2IE = 0; // disenable Timer 2 interrupt
    }
}

/******************************************************************************/
/* TMR_ResetTimer2
 *
 * Restarts Timer 2.
/******************************************************************************/
inline void TMR_ResetTimer2(void)
{
    TMR2 = 0;
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitTIMERS
 *
 * The function initializes the timers.
/******************************************************************************/
void InitTIMERS(void)
{
    InitTIMER2();
}

/******************************************************************************/
/* InitTIMER2
 *
 * The function initializes timer 2 which is used for the PWM module.
/******************************************************************************/
void InitTIMER2(void)
{
    TMR_EnableTimer2(OFF);
    TMR_InterruptTimer2(OFF);
    IPC2bits.T2IP = 0b111; // Highest priority
    IPC2bits.T2IS = 0b11; // Highest priority
    T2CONbits.TCS = 0; // Select internal instruction cycle clock
    T2CONbits.TGATE = 0; // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b110; // Select 1:64 Prescaler
    TMR2 = 0x00; // Clear timer register
    PR2 = 1000; // Load the period value
    IFS0bits.T2IF = 0; // Clear Timer 2 Interrupt Flag
    TMR_EnableTimer2(ON);
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/