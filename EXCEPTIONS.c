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
/* Contains the exception handler.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>

#include "USER.h"
#include "EXCEPTIONS.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
static unsigned short _epc_code;
static unsigned short _excep_addr;

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* EXC_General_Exception_Handler
 *
 * This function overrides the normal _weak_ generic handler.
/******************************************************************************/
void EXC_General_Exception_Handler(void)
{
    asm volatile("mfc0 %0,$13" : "=r" (_excep_code));
    asm volatile("mfc0 %0,$14" : "=r" (_excep_addr));

    _excep_code = (_excep_code & 0x0000007C) >> 2;

    while (1)
    {
        // Examine _excep_code to identify the type of exception
        // Examine _excep_addr to find the address that caused the exception
    }
}
