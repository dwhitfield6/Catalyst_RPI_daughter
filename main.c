/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/14/15     1.0_DW0a    Initial project make.
 *                          Added RGB LED functionality.
 *                          Added internal ADC read functionality.
 *                          Added UART functionality.
 *                          Fixed UART bugs.
 *                          Added UART TX software FIFOs.
 *                          Parse the RDI banner and input the catalyst 
 *                            extention.
 *                          Implement SPI mater and slave mode.
/******************************************************************************/

/******************************************************************************/
/* Contains main function.
 *
/******************************************************************************/


/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        
#include <stdbool.h>       
#include <stdio.h>         
#include <string.h>

#include "SYSTEM.h"
#include "USER.h"
#include "MISC.h"
#include "ADC.h"
#include "SPI.h"

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int main (void)
{
    unsigned long i;
    unsigned char value;
    
    /* Initialize */
    SYS_ConfigureOscillator();
    Init_App();
    Init_System();
    PWR_StatusUpdate();        
    RDI_GetProduct();

    MSC_Relay(ON);
    
    /* Flash LEDs */
    for (i=0;i<24;i++)
    {
        MSC_RedLEDTOGGLE();
        MSC_DelayUS(100000);
        PWM_SetColor(i/3);
    }
    MSC_RedLEDOFF();
    
    MSC_Relay(OFF);
    
    while(1)
    {
        SPI_WriteRead('D', &value);
        MSC_DelayUS(1000);
    }
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/
