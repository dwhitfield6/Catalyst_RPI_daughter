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
/* UART1_RECEIVE_SIZE
 *
 * This is the number of characters that fit in the UART 1 receive buffer.
/******************************************************************************/
#define UART1_RECEIVE_SIZE 250

/******************************************************************************/
/* UART2_RECEIVE_SIZE
 *
 * This is the number of characters that fit in the UART 2 receive buffer.
/******************************************************************************/
#define UART2_RECEIVE_SIZE 250

/******************************************************************************/
/* UART3_RECEIVE_SIZE
 *
 * This is the number of characters that fit in the UART 3 receive buffer.
/******************************************************************************/
#define UART3_RECEIVE_SIZE 250
/******************************************************************************/
/* UART4_RECEIVE_SIZE
 *
 * This is the number of characters that fit in the UART 4 receive buffer.
/******************************************************************************/
#define UART4_RECEIVE_SIZE 250

/******************************************************************************/
/* UART5_RECEIVE_SIZE
 *
 * This is the number of characters that fit in the UART 5 receive buffer.
/******************************************************************************/
#define UART5_RECEIVE_SIZE 250

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

#define CRLN    "\r\n"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
extern unsigned int RX1_Buffer_Place;
extern unsigned int RX2_Buffer_Place;
extern unsigned int RX3_Buffer_Place;
extern unsigned int RX4_Buffer_Place;
extern unsigned int RX5_Buffer_Place;
extern unsigned char RX1_Buffer[UART1_RECEIVE_SIZE];
extern unsigned char RX2_Buffer[UART2_RECEIVE_SIZE];
extern unsigned char RX3_Buffer[UART3_RECEIVE_SIZE];
extern unsigned char RX4_Buffer[UART4_RECEIVE_SIZE];
extern unsigned char RX5_Buffer[UART5_RECEIVE_SIZE];

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
void UART_ReceiverInterrupt1(unsigned char state);
void UART_ReceiverInterrupt2(unsigned char state);
void UART_ReceiverInterrupt3(unsigned char state);
void UART_ReceiverInterrupt4(unsigned char state);
void UART_ReceiverInterrupt5(unsigned char state);
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
void UART_CleanReceive1(void);
void UART_CleanReceive2(void);
void UART_CleanReceive3(void);
void UART_CleanReceive4(void);
void UART_CleanReceive5(void);

#endif	/* UART_H */