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
/* Files to Include                                                           */
/******************************************************************************/
#ifndef PWM_H
#define	PWM_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "USER.h"

/******************************************************************************/
/* COLORS
 *
 * This is the available Colors to set the LED.
/******************************************************************************/
#define NONE        0
#define RED         1
#define YELLOW      2
#define GREEN       3
#define BLUE        4
#define PURPLE      5
#define WHITE       6
#define TURQUOISE   7

/******************************************************************************/
/* Actions
 *
 * This is the available actions to set the LED.
/******************************************************************************/
#define NOTHING     0
#define FADEUP      1
#define FADEDOWN    2
#define FADEUPDOWN  3
#define BLINK       4

/******************************************************************************/
/* Speeds
 *
 * This is the available speeds for each action to set the LED.
/******************************************************************************/
#define PWM_SLOW      200
#define PWM_MEDIUM    75
#define PWM_FAST      20

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
extern unsigned short Red_Duty;
extern unsigned short Green_Duty;
extern unsigned short Blue_Duty;
extern unsigned char PWM_Action;
extern unsigned long PWM_Speed;
extern unsigned long PWM_TIMER;
extern unsigned char PWM_Direction;
extern unsigned long PWM_Steps;

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define UP      1
#define DOWN    0

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void InitPWM(void);
inline void PWM_SetRed(unsigned short Value);
inline void PWM_SetGreen(unsigned short Value);
inline void PWM_SetBlue(unsigned short Value);
inline void PWM_SetRGB(unsigned short Red, unsigned short Green, unsigned short Blue);
void PWM_SetColor(unsigned short Color, unsigned char type, unsigned long speed);
void PWM_SetAction(unsigned char type, unsigned long speed);

#endif	/* PWM_H */