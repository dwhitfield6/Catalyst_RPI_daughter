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
/* Contains system functions.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "SYSTEM.h"

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* SYS_ConfigureOscillator
 *
 * The function waits for the high frequency oscillator to be working and stable.
/******************************************************************************/
void SYS_ConfigureOscillator(void)
{
    unsigned long temp;
    
    /* Clock configuration is done in configuration bits in Configuration.c */
    
    /* wait for PLL to be stable if it is used */
    if(OSCCONbits.COSC = 0b011)
    {
        /* Primary Oscillator with PLL module (XTPLL, HSPLL or ECPLL) */
        while(!OSCCONbits.SLOCK);        
        /* PLL module is in lock or PLL module start-up timer is satisfied */
    }
}

/******************************************************************************/
/* MSC_SystemUnlock
 *
 * The system will be unlocked so that sensitive registers can be modified like
 *  OSCCON.
/******************************************************************************/
void SYS_SystemUnlock(void)
{
    SYSKEY = 0;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
}

/******************************************************************************/
/* MSC_SystemLock
 *
 * The system will be locked so that sensitive registers can't be modified like
 *  OSCCON.
/******************************************************************************/
void SYS_SystemLock(void)
{
    SYSKEY = 0x33333333;
}

/******************************************************************************/
/* SYS_Interrupts
 *
 * The function controls the interrupts.
/******************************************************************************/
void SYS_Interrupts(unsigned char state)
{
    if(state)
    {
        __builtin_enable_interrupts();
    }
    else
    {
        __builtin_disable_interrupts();
    }
}

/******************************************************************************/
/* SYS_Sleep
 *
 * The function puts the system to sleep.
/******************************************************************************/
void SYS_Sleep(void)
{
    OSCCONbits.SLPEN = 1; // Device will enter Sleep mode when a WAIT instruction is executed
    _wait();
}

/******************************************************************************/
/* SYS_Idle
 *
 * The function puts the system in idle.
/******************************************************************************/
void SYS_Idle(void)
{
    OSCCONbits.SLPEN = 0; // Device will enter Idle mode when a WAIT instruction is executed
    _wait();
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/