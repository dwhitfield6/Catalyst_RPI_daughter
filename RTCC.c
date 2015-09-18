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
#include "EXCEPTIONS.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
TIMETYPE CurrentTime;
TIMETYPE SetTime;
TIMETYPE CurrentAlarm;
TIMETYPE SetAlarm;

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
    IPC6bits.RTCCIP= 6;  // interrupt priority is 6
    IPC6bits.RTCCIS = 3; // interrupt sub-priority is 3
    IFS0bits.RTCCIF = 0;            // clear interrupt 
    if(!RTCC_ConfigOscillator())
    {
        return;
    }
    RTCC_Access(YES);
    RTCC_Module(ON);
    RTCCONbits.RTSECSEL = 0; // RTCC Alarm Pulse is selected for the RTCC pin
    RTCC_SetDefaultTime();
    RTCC_SetDefaultAlarm();
    RTCC_Alarm(ON, TIME, YEAR);
    RTCC_Access(NO);
}

/******************************************************************************/
/* RTCC_ConfigOscillator
 *
 * The function configures the secondary oscillator used for the RTCC.
/******************************************************************************/
unsigned char RTCC_ConfigOscillator(void)
{
    unsigned long timer = 0;
    
    SYS_SystemUnlock();
    OSCCONbits.SOSCEN = 1; // Enable Secondary Oscillator
    SYS_SystemLock();
    while(OSCCONbits.SOSCRDY)
    {
        timer++;
        if(timer > RTCC_OSCILLATOR_TIMEROUT)
        {
            Fault.RTCC_Oscillator_Fail = TRUE;
            return FAIL;
        }
    }
    Fault.RTCC_Oscillator_Fail = FALSE;
    return PASS;
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
    Time->Hour_24 = 0;
    RTCC_CalculateHours(Time,MILITARY);
    Time->Minute = 0;
    Time->Second = 0;
}

/******************************************************************************/
/* RTCC_CalculateHours
 *
 * The function calculates the 12 hour time and AM or PM from military time.
/******************************************************************************/
void RTCC_CalculateHours(TIMETYPE* Time, unsigned char type)
{
    if(type == MILITARY)
    {
        if(Time->Hour_24 > 12)
        {
            Time->Hour_12 = Time->Hour_24 - 12;
        }
        else
        {
            if(Time->Hour_24 == 0)
            {
                Time->Hour_12 = 12;
            }
            else
            {
                Time->Hour_12 = Time->Hour_24;
            }
        }
        if(Time->Hour_24 >=12)
        {
            Time->PM_nAM = PM;
        }
        else
        {
            Time->PM_nAM = AM;
        }
    }
    else
    {
        if(Time->PM_nAM == AM)
        {
                Time->Hour_24 = Time->Hour_12;
        }
        else
        {
            if(Time->Hour_12 > 11)
            {
                Time->Hour_24 = 0;
            }
            else
            {
                Time->Hour_24 = Time->Hour_12 + 12;
            }
        }
    }
}

/******************************************************************************/
/* RTCC_SetDefaultTime
 *
 * The function sets the default time to the current time.
/******************************************************************************/
void RTCC_SetDefaultTime(void)
{
    SetTime.Year = 2015;
    SetTime.Month = September;
    SetTime.Date = 16;
    SetTime.Weekday = Wednesday;
    SetTime.Hour_12 = 10;
    SetTime.PM_nAM = AM;
    SetTime.Minute = 25;
    SetTime.Second = 0;
    RTCC_Write(&SetTime);
}

/******************************************************************************/
/* RTCC_SetDefaultAlarm
 *
 * The function sets the default alarm to the current alarm.
/******************************************************************************/
void RTCC_SetDefaultAlarm(void)
{
    SetAlarm.Year = 2015;
    SetAlarm.Month = September;
    SetAlarm.Date = 16;
    SetAlarm.Hour_12 = 10;
    SetAlarm.PM_nAM = AM;
    SetAlarm.Minute = 25;
    SetAlarm.Second = 18;
    RTCC_SetAlarm(&SetAlarm);
}

/******************************************************************************/
/* RTCC_Module
 *
 * The function controls the real time clock and calender.
/******************************************************************************/
unsigned char RTCC_Module(unsigned char state)
{
    unsigned char temp;
    unsigned char access;

    access = RTCC_Access(YES);
    
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
    if(!access)
    {
        RTCC_Access(NO);
    }
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
    
    if((temp && (Yes_No == YES)) || ((temp == 0) && (Yes_No == NO)))
    {
        return temp;
    }
    
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
    return temp;
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
    Time->Hour_24 = MSC_BCDtoHEX(((temp & 0x3F000000) >> 24));
    RTCC_CalculateHours(Time,MILITARY);
    
    temp = RTCDATE;
    Time->Weekday = MSC_BCDtoHEX(temp & 0x00000007);
    Time->Date = MSC_BCDtoHEX(((temp & 0x00003F00) >> 8));
    Time->Month = MSC_BCDtoHEX(((temp & 0x001F0000) >> 16));
    Time->Year = (MSC_BCDtoHEX(((temp & 0xFF000000) >> 24)) + 2000);           
}

/******************************************************************************/
/* RTCC_Write
 *
 * The function allows the user to update the time and date by unlocking the
 *   RTC.
/******************************************************************************/
void RTCC_Write(TIMETYPE* Time)
{
    unsigned int temp =0;
    unsigned char status;
    
    RTCC_Access(TRUE);
    status = RTCC_Module(OFF);
    while(RTCC_Status()) // wait till the clock stops
    {
        RTCC_Module(OFF);
    }
   
    temp = MSC_HEXtoBCD( Time->Year - 2000) << 24;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Month) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Date) << 8;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Weekday);
    RTCDATE = temp;
    
    RTCC_CalculateHours(Time,CIVILIAN);
    temp = MSC_HEXtoBCD( (unsigned int) Time->Hour_24) << 24;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Minute) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Second) << 8;
    RTCTIME = temp;

    if(status)
    {
        RTCC_Module(ON);
    }
}

/******************************************************************************/
/* RTCC_SetAlarm
 *
 * The function sets the alarm time.
/******************************************************************************/
void RTCC_SetAlarm(TIMETYPE* Time)
{
    unsigned char status1, status2;
    unsigned int temp =0;
    
    status1 = RTCC_Alarm(OFF,NO_CHANGE ,NO_CHANGE);
    while(RTCALRMbits.ALRMSYNC);
   
    RTCC_CalculateHours(Time,CIVILIAN);
    temp = MSC_HEXtoBCD( (unsigned int) Time->Hour_24) << 24;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Minute) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Second) << 8;
    ALRMTIME = temp;
            
    temp = MSC_HEXtoBCD( (unsigned int) Time->Month) << 16;
    temp |= MSC_HEXtoBCD( (unsigned int) Time->Date) << 8;
    ALRMDATE = temp;
    
    Time->Year = SetAlarm.Year;
    
    if(status1)
    {
        RTCC_Alarm(ON, NO_CHANGE, NO_CHANGE);
    }
    if(status2)
    {
        RTCC_Module(ON);
    }
}

/******************************************************************************/
/* RTCC_SetAlarm
 *
 * The function sets the alarm time and alarm mode.
/******************************************************************************/
unsigned char RTCC_ReadAlarm(TIMETYPE* Time)
{
    unsigned int temp =0;
    
    temp = ALRMTIME;
    Time->Second = MSC_BCDtoHEX(((temp & 0x00007F00) >> 8));
    Time->Minute = MSC_BCDtoHEX(((temp & 0x007F0000)>> 16));
    Time->Hour_24 = MSC_BCDtoHEX(((temp & 0x3F000000) >> 24));
    RTCC_CalculateHours(Time,MILITARY);
    
    temp = ALRMDATE;
    Time->Weekday = MSC_BCDtoHEX(temp & 0x00000007);
    Time->Date = MSC_BCDtoHEX(((temp & 0x00003F00) >> 8));
    Time->Month = MSC_BCDtoHEX(((temp & 0x001F0000) >> 16));
    Time->Year = SetAlarm.Year;
    
    return RTCALRMbits.ALRMEN;
}

/******************************************************************************/
/* RTCC_Alarm
 *
 * The function controls the alarm.
/******************************************************************************/
unsigned char RTCC_Alarm(unsigned char state, unsigned char type, unsigned char resolution)
{
    unsigned char status;
    
    status = RTCALRMbits.ALRMEN;
    while(RTCALRMbits.ALRMSYNC);
    
    if(state)
    {
        RTCALRMbits.ALRMEN = 1; // Alarm is enabled
        RTCC_AlarmInterrupts(ON);
    }
    else
    {
        RTCALRMbits.ALRMEN = 0; // Alarm is disabled
        RTCC_AlarmInterrupts(OFF);
    }
    
    if(type == NO_CHANGE || resolution == NO_CHANGE)
    {
        return status;
    }
    if(type == TIME)
    {
        RTCALRMbits.CHIME = 0;
    }
    else
    {
        RTCALRMbits.CHIME = 1;
    }
        
    if(resolution == HALF_SECOND)
    {
        RTCALRMbits.AMASK = 0b0000;
    }
    else if(resolution == SECOND)
    {
        RTCALRMbits.AMASK = 0b0001;
    }
    else if(resolution == SECONDS_10)
    {
        RTCALRMbits.AMASK = 0b0010;
    }
    else if(resolution == MINUTE)
    {
        RTCALRMbits.AMASK = 0b0011;
    }
    else if(resolution == MINUTES_10)
    {
        RTCALRMbits.AMASK = 0b0100;
    }
    else if(resolution == HOUR)
    {
        RTCALRMbits.AMASK = 0b0101;
    }
    else if(resolution == DAY)
    {
        RTCALRMbits.AMASK = 0b0110;
    }
    else if(resolution == WEEK)
    {
        RTCALRMbits.AMASK = 0b0111;
    }
    else if(resolution == MONTH)
    {
        RTCALRMbits.AMASK = 0b1000;
    }
    else
    {
        RTCALRMbits.AMASK = 0b1001;
    }
    return status;
}

/******************************************************************************/
/* RTCC_Alarm
 *
 * The function controls the alarm.
/******************************************************************************/
unsigned char RTCC_AlarmInterrupts(unsigned char state)
{
    if(state)
    {
        IFS0bits.RTCCIF = 0;
        IEC0bits.RTCCIE = 1;
    }
    else
    {
        IEC0bits.RTCCIE = 0;
    }  
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/