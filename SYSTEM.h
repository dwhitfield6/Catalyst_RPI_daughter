/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 08/21/15     1.0_DW0a    Initial project make.
 *                          Derived from project 'PIC_PS2_to_UART'.
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "USER.h"

/******************************************************************************/
/* System frequency
 *
 * This is the CPU clock frequency.
 *
 * For this system the clock is 64MHz and the internal PLL is used.
 *
/******************************************************************************/
#define FOSC        96000000L

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define SYSCLK      FOSC
#define PBCLK       SYSCLK/2

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void SYS_ConfigureOscillator(void);
void SYS_SystemUnlock(void);
void SYS_SystemLock(void);
void SYS_Interrupts(unsigned char state);

#endif	/* SYSTEM_H */