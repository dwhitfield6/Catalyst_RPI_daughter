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
/* User Global Variable Declaration                                           */
/******************************************************************************/
extern unsigned short Red_Duty;
extern unsigned short Green_Duty;
extern unsigned short Blue_Duty;

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

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
void PWM_SetColor(unsigned short Color);

#endif	/* PWM_H */