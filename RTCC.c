/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/15/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Contains functions for the Real time clock and calender.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "RTCC.h"
#include "SYSTEM.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
TIMETYPE CurrentTime;
TIMETYPE SetTime;

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitRTCC
 *
 * The function initializes the real time clock and calender.
/******************************************************************************/
void InitRTCC(void)
{
    RTCC_ClearTime(&CurrentTime);
    RTCC_ClearTime(&SetTime);
    RTCC_ConfigOscillator();
    RTCC_Access(YES);
    RTCC_Module(OFF);
    RTCCONbits.RTCWREN = 1; // RTC Value registers can be written to by the user
    RTCCONbits.RTSECSEL = 0; // RTCC Alarm Pulse is selected for the RTCC pin
    RTCC_SetDefaultTime();
    RTCC_Module(ON);
    RTCC_Access(NO);
}

/******************************************************************************/
/* RTCC_ConfigOscillator
 *
 * The function configures the secondary oscillator used for the RTCC.
/******************************************************************************/
void RTCC_ConfigOscillator(void)
{
    SYS_SystemUnlock();
    OSCCONbits.SOSCEN = 1; // Enable Secondary Oscillator
    SYS_SystemLock();
}

/******************************************************************************/
/* RTCC_ClearTime
 *
 * The function clears the struct TIMETYPE.
/******************************************************************************/
void RTCC_ClearTime(TIMETYPE* Time)
{
    Time->Year = 0;
    Time->Month = 0;
    Time->Date = 0;
    Time->Weekday = 0;
    Time->Hour = 0;
    Time->Minute = 0;
    Time->Second = 0;
}

/******************************************************************************/
/* SetTime
 *
 * The function sets the time to the current time.
/******************************************************************************/
void RTCC_SetDefaultTime(void)
{
    SetTime.Year = 2015;
    SetTime.Month = September;
    SetTime.Date = 16;
    SetTime.Weekday = Wednesday;
    SetTime.Hour = 17;
    SetTime.Minute = 25;
    SetTime.Second = 0;
    RTCC_Write(SetTime);
}

/******************************************************************************/
/* RTCC_Module
 *
 * The function controls the real time clock and calender.
/******************************************************************************/
unsigned char RTCC_Module(unsigned char state)
{
    unsigned char temp;
#ifdef ON
    #undef ON
    temp = RTCCONbits.ON;
    if(state)
    {
        RTCCONbits.ON = 1; // Turn on the RTCC module
    }
    else
    {
        RTCCONbits.ON = 0; // Turn off the RTCC module
    }
    #define ON 1
#else
    temp = RTCCONbits.ON;
    if(state)
    {
        RTCCONbits.ON = 1; // Turn on the RTCC module
    }
    else
    {
        RTCCONbits.ON = 0; // Turn off the RTCC module
    }
#endif
    return temp;
}

/******************************************************************************/
/* RTCC_Status
 *
 * The function returns the status of the RTCC clock.
/******************************************************************************/
unsigned char RTCC_Status(void)
{
    return RTCCONbits.RTCCLKON;
}

/******************************************************************************/
/* RTCC_Access
 *
 * The function allows the user to update the time and date by unlocking the
 *   RTC.
/******************************************************************************/
unsigned char RTCC_Access(unsigned char Yes_No)
{
    unsigned char temp;
    temp = RTCCONbits.RTCWREN;
    
    if(Yes_No == YES )
    {
        SYSKEY = 0xAA996655; // write first unlock key to SYSKEY
        SYSKEY = 0x556699AA; // write second unlock key to SYSKEY
        RTCCONSET = 0x0008; // set RTCWREN in RTCCONSET
    }
    else
    {
        RTCCONCLR = 0x0008;
    }
}

/******************************************************************************/
/* RTCC_Read
 *
 * The function reads the RTC.
/******************************************************************************/
void RTCC_Read(TIMETYPE* Time)
{
    unsigned long temp =0;

    temp = RTCTIME;
    Time->Second = MSC_BCDtoHEX(((temp & 0x00007F00) >> 8));
    Time->Minute = MSC_BCDtoHEX(((temp & 0x007F0000)>> 16));
    Time->Hour = MSC_BCDtoHEX(((temp & 0x3F000000) >> 24));
    temp = RTCDATE;
    Time->Weekday = MSC_BCDtoHEX(temp & 0x00000007);
    Time->Date = MSC_BCDtoHEX(((temp & 0x00003F00) >> 8));
    Time->Month = MSC_BCDtoHEX(((temp & 0x001F0000) >> 16));
    Time->Year = (MSC_BCDtoHEX(((temp & 0xFF000000) >> 24)) + 2000);           
}

/******************************************************************************/
/* RTCC_Write
 *
 * The function allows the user to update teh time and date by unlocking the
 *   RTC.
/******************************************************************************/
void RTCC_Write(TIMETYPE Time)
{
    unsigned int temp =0;
    unsigned char status;
    
    RTCC_Access(TRUE);
    status = RTCC_Module(OFF);
    while(RTCC_Status()); // wait till the clock stops
   
    temp = MSC_HEXtoBCD( Time.Year - 2000) << 24;
    temp |= MSC_HEXtoBCD( (unsigned int) Time.Month) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time.Date) << 8;
    temp |= MSC_HEXtoBCD( (unsigned int) Time.Weekday);
    RTCDATE = temp;
    
    temp = MSC_HEXtoBCD( (unsigned int) Time.Hour) << 24;
    temp |= MSC_HEXtoBCD( (unsigned int) Time.Minute) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time.Second) << 8;
    RTCTIME = temp;

    RTCC_Access(FALSE);
    if(status)
    {
        RTCC_Module(ON);
    }
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/