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
/* Contains functions for the Supercap including reading the voltage comparator
 * and voltages from the ADC.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "SUPERCAP.h"
#include "ADC.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions                                                           */
/******************************************************************************/

/******************************************************************************/
/* SCP_Charge
 *
 * Controls the charging of the SuperCap.
/******************************************************************************/
inline void SCP_Charge(unsigned char action)
{
    if (action)
    {
        LATD |= ChargeCap;
        RailStatus.Supercap_state = CHARGING;
    }
    else
    {
        LATD &= ~ChargeCap;
        RailStatus.Supercap_state = DISCHARGING;
    }
}

/******************************************************************************/
/* SCP_Volts5
 *
 * Controls the 5 volt DCDC converter.
/******************************************************************************/
inline void SCP_Volts5(unsigned char action)
{
    if (action)
    {       
        LATD &= ~Inhibit;
        RailStatus.DCDC_state = ON;
    }
    else
    {
        LATD |= Inhibit;
        RailStatus.DCDC_state = OFF;
    }
}

/******************************************************************************/
/* SCP_RASP_ON
 *
 * Controls the 5 volt rail to the raspberry pi.
/******************************************************************************/
inline void SCP_RASP_ON(unsigned char action)
{
    if (action)
    {       
        LATA |= RASP_ON;
        RailStatus.Rasp_state = ON;
    }
    else
    {
        LATA &= ~RASP_ON;
        RailStatus.Rasp_state = OFF;
    }
}

/******************************************************************************/
/* SCP_RASP_Read
 *
 * Reads the state of the raspberry pi voltage rail.
/******************************************************************************/
inline unsigned char SCP_RASP_Read(void)
{
    if (PORTA & RASP_ON2)
    {       
        RailStatus.Rasp_state = ON;
        return ON;
    }
    RailStatus.Rasp_state = OFF;
    return OFF;
}

/******************************************************************************/
/* SCP_RASP_Connected
 *
 * Detects if a raspberry pi is present or not.
/******************************************************************************/
inline unsigned char SCP_RASP_Connected(void)
{
    if (PORTG & RASP_Connected)
    {       
        RailStatus.Rasp_connected = FALSE;
        return OFF;
    }
    RailStatus.Rasp_connected = TRUE;
    return ON;
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* SCP_StatusUpdate
 *
 * The function reads the voltage rails and rail states.
/******************************************************************************/
void SCP_StatusUpdate(void)
{
    SCP_RASP_Read();
    SCP_RASP_Connected();
    ADC_ReadRails();
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/