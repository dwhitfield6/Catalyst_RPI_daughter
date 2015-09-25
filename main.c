/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/23/15     1.0_DW0a    Initial project make.
 *                          Added RGB LED functionality.
 *                          Added internal ADC read functionality.
 *                          Added UART functionality.
 *                          Fixed UART bugs.
 *                          Added UART TX software FIFOs.
 *                          Parse the RDI banner and input the catalyst 
 *                            extention.
 *                          Implement SPI mater and slave mode.
 *                          Added external Flash IC functionality.
 *                          Added RTCC functionality.
 *                          Added RGB LED fade and blink functionality.
 *                          Added RTC alarm capability.
 *                          Added I2C functionality.
 *                          Improved RGB LED functionality.
 *                          Added DMA framework.
 *                          Added Red, Green, Blue PWM channels DMA
 *                            functionality. This eases use of the CPU for
 *                            important things.
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
#include "RTCC.h"
#include "PWM.h"

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

short main (void)
{
    unsigned long i;
    
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
        PWM_SetColor(i/3, NOTHING,NOTHING);
    }
    MSC_RedLEDOFF();
    
    MSC_Relay(OFF);
    RTCC_ReadAlarm(&CurrentAlarm);
    
    PWM_SetColor(RED, FADEUP,PWM_MEDIUM);
    while(1)
    {
        MSC_RedLEDTOGGLE();
        MSC_DelayUS(50000);
    }
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/
