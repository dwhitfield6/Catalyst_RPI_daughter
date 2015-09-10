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
#ifndef UART_H
#define	UART_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "USER.h"

/******************************************************************************/
/* LONG_BREAK_US
 *
 * This is microseconds that a long break holds the line high.
/******************************************************************************/
#define LONG_BREAK_US 250000

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define NO      0
#define ODD     1
#define EVEN    2

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
inline void UART_Module1(unsigned char state);
inline void UART_Module2(unsigned char state);
inline void UART_Module3(unsigned char state);
inline void UART_Module4(unsigned char state);
inline void UART_Module5(unsigned char state);
inline void UART_SendCharacter1(unsigned char data);
inline void UART_SendCharacter2(unsigned char data);
inline void UART_SendCharacter3(unsigned char data);
inline void UART_SendCharacter4(unsigned char data);
inline void UART_SendCharacter5(unsigned char data);
void InitUART(void);
void UART_PrintBanner(void);
void UART_RS232_FemaleSendChar(unsigned char data);
void UART_RS232_MaleSendChar(unsigned char data);
void UART_RS232_FemaleSendConstChar(const unsigned char data);
void UART_RS232_MaleSendConstChar(const unsigned char data);
void UART_RS232_MaleSendString(unsigned char* data);
void UART_RS232_FemaleSendString(unsigned char* data);
void UART_RS232_MaleSendConstString(const unsigned char* data);
void UART_RS232_FemaleSendConstString(const unsigned char* data);
void UART_RS232_MaleSendStringCRLN(unsigned char* data);
void UART_RS232_FemaleSendStringCRLN(unsigned char* data);
void UART_RS232_MaleSendConstStringCRLN(unsigned char* data);
void UART_RS232_FemaleSendConstStringCRLN(unsigned char* data);
void UART_Rasp(unsigned char module, unsigned char transmit, unsigned char receive);
void UART_RS232_Male(unsigned char module, unsigned char transmit, unsigned char receive);
void UART_RS232_MaleParameters(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_RS232_FemaleParameters(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_RS232_Female(unsigned char module, unsigned char transmit, unsigned char receive);
void UART_SetParameters1(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_SetParameters2(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_SetParameters3(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_SetParameters4(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_SetParameters5(unsigned long Baud,unsigned char Parity, unsigned char Stop);
void UART_Receiver1(unsigned char state);
void UART_Receiver2(unsigned char state);
void UART_Receiver3(unsigned char state);
void UART_Receiver4(unsigned char state);
void UART_Receiver5(unsigned char state);
void UART_Transmitter1(unsigned char state);
void UART_Transmitter2(unsigned char state);
void UART_Transmitter3(unsigned char state);
void UART_Transmitter4(unsigned char state);
void UART_Transmitter5(unsigned char state);
void UART_SendShortBreak1(void);
void UART_SendShortBreak2(void);
void UART_SendShortBreak3(void);
void UART_SendShortBreak4(void);
void UART_SendShortBreak5(void);
void UART_SendLongBreak1(void);
void UART_SendLongBreak2(void);
void UART_SendLongBreak3(void);
void UART_SendLongBreak4(void);
void UART_SendLongBreak5(void);
void UART_RS232_MaleDriver(unsigned char state);
void UART_RS232_FemaleDriver(unsigned char state);

#endif	/* UART_H */