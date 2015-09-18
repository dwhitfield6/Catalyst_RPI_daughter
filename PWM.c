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
/* Contains functions for pulse width modulation controller.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "PWM.h"
#include "TIMERS.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
unsigned short Red_Duty = 0;
unsigned short Green_Duty = 0;
unsigned short Blue_Duty = 0;
unsigned char PWM_Action = FADEUP;
unsigned long PWM_Speed = PWM_SLOW;
unsigned long PWM_TIMER = 0;
unsigned char PWM_Direction = UP;
unsigned long PWM_Steps = 0;

/******************************************************************************/
/* Inline Functions                                                           */
/******************************************************************************/

/******************************************************************************/
/* PWM_SetRed
 *
 * Sets the duty cycle for the Red LED.
/******************************************************************************/
inline void PWM_SetRed(unsigned short Value)
{
    Red_Duty = Value;
}

/******************************************************************************/
/* PWM_SetGreen
 *
 * Sets the duty cycle for the Green LED.
/******************************************************************************/
inline void PWM_SetGreen(unsigned short Value)
{
    Green_Duty = Value;
}

/******************************************************************************/
/* PWM_SetBlue
 *
 * Sets the duty cycle for the Blue LED.
/******************************************************************************/
inline void PWM_SetBlue(unsigned short Value)
{
    Blue_Duty = Value;
}

/******************************************************************************/
/* PWM_SetRGB
 *
 * Sets the LED Color via 3 color maps.
/******************************************************************************/
inline void PWM_SetRGB(unsigned short Red, unsigned short Green, unsigned short Blue)
{
    PWM_SetRed(Red);
    PWM_SetGreen(Green);
    PWM_SetBlue(Blue);
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitPIR
 *
 * The function initializes the 3 PWM channels. This must be called after a
 * a call to initialize the timers.
/******************************************************************************/
void InitPWM(void)
{
    /* Map the remappable pins */
    /* Red led is OC3 */
    /* Green led is OC2 */
    /* Blue led is OC1 */      
    RPD2R    = 0b1011;    // RD2 = OC3 aka Red on RGB LED
    RPB6R    = 0b1011;    // RB6 = OC2 aka Green on RGB LED
    RPD1R    = 0b1100;    // RD1 = OC1 aka Blue on RGB LED
    
    // Initialize Output Compare Module
#ifdef ON
    #undef ON
    OC1CONbits.ON = TRUE;    // Turn off output compare peripheral
    OC2CONbits.ON = TRUE;    // Turn off output compare peripheral
    OC3CONbits.ON = TRUE;    // Turn off output compare peripheral
    #define ON 1
#else
    OC1CONbits.ON = TRUE;    // Turn off output compare peripheral
    OC2CONbits.ON = TRUE;    // Turn off output compare peripheral
    OC3CONbits.ON = TRUE;    // Turn off output compare peripheral
#endif
    
    OC1CONbits.OCM = 0b110; // PWM mode on OC1; Fault pin disabled
    OC2CONbits.OCM = 0b110; // PWM mode on OC2; Fault pin disabled
    OC3CONbits.OCM = 0b110; // PWM mode on OC3; Fault pin disabled
    
    OC1R = 0; // Write the duty cycle for the first PWM pulse of Blue LED
    OC2R = 0; // Write the duty cycle for the first PWM pulse of Green LED
    OC3R = 0; // Write the duty cycle for the first PWM pulse of Red LED
    OC1RS = 0; // Write the duty cycle for the second PWM pulse
    OC2RS = 0; // Write the duty cycle for the second PWM pulse
    OC3RS = 0; // Write the duty cycle for the second PWM pulse
    
    OC1CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC2CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC3CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    
    TMR_ResetTimer2();
    TMR_InterruptTimer2(ON);
}

/******************************************************************************/
/* PWM_SetAction
 *
 * Sets the LED action like fade or blink and sets the speed.
/******************************************************************************/
void PWM_SetAction(unsigned char type, unsigned long speed)
{
    PWM_Action = type;
    PWM_Speed = speed;
}

/******************************************************************************/
/* PWM_SetColor
 *
 * Sets the LED Color by name.
/******************************************************************************/
void PWM_SetColor(unsigned short Color, unsigned char type, unsigned long speed)
{
    switch (Color)
    {
        case RED:
            PWM_SetRGB(32,0,0);
            break;
        case GREEN:
            PWM_SetRGB(0,16,0);
            break;
        case BLUE:
            PWM_SetRGB(0,0,8);
            break;
        case PURPLE:
            PWM_SetRGB(32,0,8);
            break;
        case YELLOW:
            PWM_SetRGB(16,16,0);
            break;
         case WHITE:
            PWM_SetRGB(16,16,8);
            break;
        case TURQUOISE:
            PWM_SetRGB(0,16,8);
            break;
        default:
            PWM_SetRGB(0,0,0);
            break;
    }
    if(type)
    {
        PWM_TIMER = speed + 1;
        PWM_Steps = 0;
        PWM_Direction = UP;
        if(Red_Duty != 0)
        {
            if(type == FADEDOWN)
            {
                Red_Duty = 241;
            }
            else
            {
                Red_Duty = 1;
            }       
        }
        if(Green_Duty != 0)
        {
            if(type == FADEDOWN)
            {
                Green_Duty = 241;
            }
            else
            {
                Green_Duty = 1;
            }  
        }
        if(Blue_Duty != 0)
        {
            if(type == FADEDOWN)
            {
                Blue_Duty = 241;
            }
            else
            {
                Blue_Duty = 1;
            }  
        }
    }
    PWM_SetAction(type, speed);
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/