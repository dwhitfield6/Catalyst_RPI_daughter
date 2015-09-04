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
/* Contains functions for Universal asynchronous receiver/transmitter.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "UART.h"
#include "SYSTEM.h"
#include "MISC.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* UART_Module1
 *
 * The function controls the UART module 1.
/******************************************************************************/
inline void UART_Module1(unsigned char state)
{
#ifdef ON
    #undef ON
    if(state)
    {
        U1MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U1MODEbits.ON = 0; // Turn off the UART module
    }
    #define ON 1
#else
    if(state)
    {
        U1MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U1MODEbits.ON = 0; // Turn off the UART module
    }
#endif
}

/******************************************************************************/
/* UART_Module2
 *
 * The function controls the UART module 2.
/******************************************************************************/
inline void UART_Module2(unsigned char state)
{
#ifdef ON
    #undef ON
    if(state)
    {
        U2MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U2MODEbits.ON = 0; // Turn off the UART module
    }
    #define ON 1
#else
    if(state)
    {
        U2MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U2MODEbits.ON = 0; // Turn off the UART module
    }
#endif    
}

/******************************************************************************/
/* UART_Module3
 *
 * The function controls the UART module 3.
/******************************************************************************/
inline void UART_Module3(unsigned char state)
{
#ifdef ON
    #undef ON    
    if(state)
    {
        U3MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U3MODEbits.ON = 0; // Turn off the UART module
    }
    #define ON 1
#else
    if(state)
    {
        U3MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U3MODEbits.ON = 0; // Turn off the UART module
    }
#endif    
}

/******************************************************************************/
/* UART_Module4
 *
 * The function controls the UART module 4.
/******************************************************************************/
inline void UART_Module4(unsigned char state)
{
#ifdef ON
    #undef ON    
    if(state)
    {
        U4MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U4MODEbits.ON = 0; // Turn off the UART module
    }
    #define ON 1
#else
    if(state)
    {
        U4MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U4MODEbits.ON = 0; // Turn off the UART module
    }
#endif    
}

/******************************************************************************/
/* UART_Module5
 *
 * The function controls the UART module 5.
/******************************************************************************/
inline void UART_Module5(unsigned char state)
{
#ifdef ON
    #undef ON    
    if(state)
    {
        U5MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U5MODEbits.ON = 0; // Turn off the UART module
    }
    #define ON 1
#else
    if(state)
    {
        U5MODEbits.ON = 1; // Turn on the UART module
    }
    else
    {
        U5MODEbits.ON = 0; // Turn off the UART module
    }
#endif    
}

/******************************************************************************/
/* UART_SendCharacter1
 *
 * The function sends a character over the UART module 1.
/******************************************************************************/
inline void UART_SendCharacter1(unsigned char data)
{
    U1TXREG = data;
}

/******************************************************************************/
/* UART_SendCharacter2
 *
 * The function sends a character over the UART module 2.
/******************************************************************************/
inline void UART_SendCharacter2(unsigned char data)
{
    U2TXREG = data;
}

/******************************************************************************/
/* UART_SendCharacter3
 *
 * The function sends a character over the UART module 3.
/******************************************************************************/
inline void UART_SendCharacter3(unsigned char data)
{
    U3TXREG = data;
}

/******************************************************************************/
/* UART_SendCharacter4
 *
 * The function sends a character over the UART module 4.
/******************************************************************************/
inline void UART_SendCharacter4(unsigned char data)
{
    U4TXREG = data;
}

/******************************************************************************/
/* UART_SendCharacter5
 *
 * The function sends a character over the UART module 5.
/******************************************************************************/
inline void UART_SendCharacter5(unsigned char data)
{
    U5TXREG = data;
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitUART
 *
 * The function initializes the UART module.
/******************************************************************************/
void InitUART(void)
{
    U1MODE = 0;
    U2MODE = 0;
    U3MODE = 0;
    U4MODE = 0;
    U5MODE = 0;
    U1STA  = 0;
    U2STA  = 0;
    U3STA  = 0;
    U4STA  = 0;
    U5STA  = 0;
    
    /* Set remappable output */
    RPC4R = RASP_UART_TX_Module;        // U1TX
    RPF5R = RS232_MALE_TX_Module;       // U2TX
    RPF5R = RS232_MALE_RTS_Module;      // U3TX
    RPF12R = RS232_FEMALE_TX_Module;    // U4TX
    RPF8R = RS232_FEMALE_RTS_Module;    // U5TX
    
    /* Set remappable input */
    U1RXR = RASP_UART_RX_Pin;           // U1RX
    U2RXR = RS232_MALE_RX_Pin;          // U2RX
    U3RXR = RS232_MALE_CTS_Pin;         // U3RX
    U4RXR = RS232_FEMALE_RX_Pin;        // U4RX
    U5RXR = RS232_FEMALE_CTS_Pin;       // U5RX
    
    UART_RS232_MaleParameters(115200, NO, 1);
    UART_RS232_Male(ON, ON, ON);

}

/******************************************************************************/
/* UART_PrintBanner
 *
 * The function prints the banner on the female rs232 port.
/******************************************************************************/
void UART_PrintBanner(void)
{
    UART_RS232_FemaleSendStringCRLN("\r\nCatalys PIC Board");
    UART_RS232_FemaleSendStringCRLN("RD Instruments (c) 2015");
    UART_RS232_FemaleSendStringCRLN("All rights reserved.");
    UART_RS232_FemaleSendString("Version: ");
    if(Version[0]!= 0)
    {
        UART_RS232_FemaleSendConstString(Version);
    }
    if(Revision[0]!= 0)
    {
        UART_RS232_FemaleSendConstChar('.');
        UART_RS232_FemaleSendConstString(Revision);
    }
    if(Alpha[0]!= 0)
    {
        UART_RS232_FemaleSendConstString(Alpha);
    }
    if(Branch_Version[0]!= 0)
    {
        UART_RS232_FemaleSendConstChar('_');
        UART_RS232_FemaleSendConstString(Branch_Version);
    }
}

/******************************************************************************/
/* UART_RS232_FemaleSendChar
 *
 * The function sends a character over the Female rs232 port.
/******************************************************************************/
void UART_RS232_FemaleSendChar(unsigned char data)
{
    while(U3STAbits.UTXBF)
    {
        /* transmit buffer has room */
        UART_SendCharacter3(data);
    }
}

/******************************************************************************/
/* UART_RS232_MaleSendChar
 *
 * The function sends a character over the Male rs232 port.
/******************************************************************************/
void UART_RS232_MaleSendChar(unsigned char data)
{
    while(U1STAbits.UTXBF)
    {
        /* transmit buffer has room */
        UART_SendCharacter1(data);
    }
}

/******************************************************************************/
/* UART_RS232_FemaleSendConstChar
 *
 * The function sends a constant character over the Female rs232 port.
/******************************************************************************/
void UART_RS232_FemaleSendConstChar(const unsigned char data)
{
    while(U3STAbits.UTXBF)
    {
        /* transmit buffer has room */
        UART_SendCharacter3((unsigned char)data);
    }
}

/******************************************************************************/
/* UART_RS232_MaleSendConstChar
 *
 * The function sends a constant character over the Male rs232 port.
/******************************************************************************/
void UART_RS232_MaleSendConstChar(const unsigned char data)
{
    while(U1STAbits.UTXBF)
    {
        /* transmit buffer has room */
        UART_SendCharacter1((unsigned char)data);
    }
}

/******************************************************************************/
/* UART_RS232_MaleSendString
 *
 * The function sends a string over the Male rs232 port.
/******************************************************************************/
void UART_RS232_MaleSendString(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_MaleSendChar(*data);
        data++;
    }
}

/******************************************************************************/
/* UART_RS232_FemaleSendString
 *
 * The function sends a string over the Female rs232 port.
/******************************************************************************/
void UART_RS232_FemaleSendString(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_FemaleSendChar(*data);
        data++;
    }
}

/******************************************************************************/
/* UART_RS232_MaleSendConstString
 *
 * The function sends a constant string over the Male rs232 port.
/******************************************************************************/
void UART_RS232_MaleSendConstString(const unsigned char* data)
{
    while(*data)
    {
        UART_RS232_MaleSendChar(*data);
        data++;
    }
}

/******************************************************************************/
/* UART_RS232_FemaleSendConstString
 *
 * The function sends a constant string over the Female rs232 port.
/******************************************************************************/
void UART_RS232_FemaleSendConstString(const unsigned char* data)
{
    while(*data)
    {
        UART_RS232_FemaleSendChar(*data);
        data++;
    }
}

/******************************************************************************/
/* UART_RS232_MaleSendStringCRLN
 *
 * The function sends a string followed by a carriage return over the Male 
 *  rs232 port. 
/******************************************************************************/
void UART_RS232_MaleSendStringCRLN(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_MaleSendChar(*data);
        data++;
    }
    UART_RS232_MaleSendConstString("\r\n");
}

/******************************************************************************/
/* UART_RS232_FemaleSendStringCRLN
 *
 * The function sends a string followed by a carriage return over the Female 
 *  rs232 port. 
/******************************************************************************/
void UART_RS232_FemaleSendStringCRLN(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_FemaleSendChar(*data);
        data++;
    }
    UART_RS232_FemaleSendConstString("\r\n");
}

/******************************************************************************/
/* UART_RS232_MaleSendConstStringCRLN
 *
 * The function sends a constant string followed by a carriage return over the 
 *  Male rs232 port. 
/******************************************************************************/
void UART_RS232_MaleSendConstStringCRLN(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_MaleSendConstChar(*data);
        data++;
    }
    UART_RS232_MaleSendConstString("\r\n");
}

/******************************************************************************/
/* UART_RS232_FemaleSendConstStringCRLN
 *
 * The function sends a constant string followed by a carriage return over the 
 *  Female rs232 port. 
/******************************************************************************/
void UART_RS232_FemaleSendConstStringCRLN(unsigned char* data)
{
    while(*data)
    {
        UART_RS232_FemaleSendConstChar(*data);
        data++;
    }
    UART_RS232_FemaleSendConstString("\r\n");
}

/******************************************************************************/
/* UART_Rasp_Comm
 *
 * The function controls the UART port connected to the raspberry pi.
/******************************************************************************/
void UART_Rasp(unsigned char module, unsigned char transmit, unsigned char receive)
{
    UART_Module1(module);
    UART_Receiver1(receive);
    UART_Transmitter1(transmit);
}

/******************************************************************************/
/* UART_Rasp_Comm
 *
 * The function controls the UART port connected to the raspberry pi.
/******************************************************************************/
void UART_RS232_Male(unsigned char module, unsigned char transmit, unsigned char receive)
{
    UART_RS232_MaleDriver(module);
    UART_Module2(module);
    UART_Receiver2(receive);
    UART_Transmitter2(transmit);
}

/******************************************************************************/
/* UART_Rasp_Comm
 *
 * The function controls the UART port connected to the raspberry pi.
/******************************************************************************/
void UART_RS232_MaleParameters(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    UART_SetParameters2(Baud, Parity, Stop);
}

/******************************************************************************/
/* UART_Rasp_Comm
 *
 * The function controls the UART port connected to the raspberry pi.
/******************************************************************************/
void UART_RS232_Female(unsigned char module, unsigned char transmit, unsigned char receive)
{
    UART_RS232_FemaleDriver(module);
    UART_Module4(module);
    UART_Receiver4(receive);
    UART_Transmitter4(transmit);
}

/******************************************************************************/
/* UART_SetParameters1
 *
 * The function initializes the UART module 1.
/******************************************************************************/
void UART_SetParameters1(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    /* Set parity option */
    if(Parity == ODD)
    {
        /* Odd parity bit */
        U1MODEbits.PDSEL = 0b10;        
    }
    else if(Parity == EVEN)
    {
        /* Even Parity bit */
        U1MODEbits.PDSEL = 0b01;  
    }
    else
    {
        /* No parity bit */
        U1MODEbits.PDSEL = 0b00;
    }
    
    /* Set stop option */
    if(Stop == 1)
    {
        /* One stop bit */
        U1MODEbits.STSEL = 0;       
    }
    else
    {
        /* Two stop bits */
        U1MODEbits.STSEL = 1;  
    }
    
    /* Set Baud clock */
    U1MODEbits.BRGH = 0; // High speed mode
    U1BRG = (unsigned long) MSC_DB_Round(((double)PBCLK/(4.0* (double)Baud)) - 1.0);
}

/******************************************************************************/
/* UART_SetParameters2
 *
 * The function initializes the UART module 2.
/******************************************************************************/
void UART_SetParameters2(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    /* Set parity option */
    if(Parity == ODD)
    {
        /* Odd parity bit */
        U2MODEbits.PDSEL = 0b10;        
    }
    else if(Parity == EVEN)
    {
        /* Even Parity bit */
        U2MODEbits.PDSEL = 0b01;  
    }
    else
    {
        /* No parity bit */
        U2MODEbits.PDSEL = 0b00;
    }
    
    /* Set stop option */
    if(Stop == 1)
    {
        /* One stop bit */
        U2MODEbits.STSEL = 0;       
    }
    else
    {
        /* Two stop bits */
        U2MODEbits.STSEL = 1;  
    }
    
    /* Set Baud clock */
    U2MODEbits.BRGH = 0; // High speed mode
    U2BRG = (unsigned long) MSC_DB_Round(((double)PBCLK/(4.0 * (double) Baud)) - 1.0);
}

/******************************************************************************/
/* UART_SetParameters3
 *
 * The function initializes the UART module 3.
/******************************************************************************/
void UART_SetParameters3(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    /* Set parity option */
    if(Parity == ODD)
    {
        /* Odd parity bit */
        U3MODEbits.PDSEL = 0b10;        
    }
    else if(Parity == EVEN)
    {
        /* Even Parity bit */
        U3MODEbits.PDSEL = 0b01;  
    }
    else
    {
        /* No parity bit */
        U3MODEbits.PDSEL = 0b00;
    }
    
    /* Set stop option */
    if(Stop == 1)
    {
        /* One stop bit */
        U3MODEbits.STSEL = 0;       
    }
    else
    {
        /* Two stop bits */
        U3MODEbits.STSEL = 1;  
    }
    
    /* Set Baud clock */
    U3MODEbits.BRGH = 0; // High speed mode
    U3BRG = (unsigned long) MSC_DB_Round(((double)PBCLK/(4.0 * (double) Baud)) - 1.0);
}

/******************************************************************************/
/* UART_SetParameters4
 *
 * The function initializes the UART module 4.
/******************************************************************************/
void UART_SetParameters4(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    /* Set parity option */
    if(Parity == ODD)
    {
        /* Odd parity bit */
        U4MODEbits.PDSEL = 0b10;        
    }
    else if(Parity == EVEN)
    {
        /* Even Parity bit */
        U4MODEbits.PDSEL = 0b01;  
    }
    else
    {
        /* No parity bit */
        U4MODEbits.PDSEL = 0b00;
    }
    
    /* Set stop option */
    if(Stop == 1)
    {
        /* One stop bit */
        U4MODEbits.STSEL = 0;       
    }
    else
    {
        /* Two stop bits */
        U4MODEbits.STSEL = 1;  
    }
    
    /* Set Baud clock */
    U4MODEbits.BRGH = 0; // High speed mode
    U4BRG = (unsigned long) MSC_DB_Round(((double)PBCLK/(4.0 * (double) Baud)) - 1.0);
}

/******************************************************************************/
/* UART_SetParameters5
 *
 * The function initializes the UART module 5.
/******************************************************************************/
void UART_SetParameters5(unsigned long Baud,unsigned char Parity, unsigned char Stop)
{
    /* Set parity option */
    if(Parity == ODD)
    {
        /* Odd parity bit */
        U5MODEbits.PDSEL = 0b10;        
    }
    else if(Parity == EVEN)
    {
        /* Even Parity bit */
        U5MODEbits.PDSEL = 0b01;  
    }
    else
    {
        /* No parity bit */
        U5MODEbits.PDSEL = 0b00;
    }
    
    /* Set stop option */
    if(Stop == 1)
    {
        /* One stop bit */
        U5MODEbits.STSEL = 0;       
    }
    else
    {
        /* Two stop bits */
        U5MODEbits.STSEL = 1;  
    }
    
    /* Set Baud clock */
    U5MODEbits.BRGH = 0; // High speed mode
    U5BRG = (unsigned long) MSC_DB_Round(((double)PBCLK/(4.0 * (double) Baud)) - 1.0);
}

/******************************************************************************/
/* UART_Receiver1
 *
 * The function controls the UART module 1 receiver.
/******************************************************************************/
void UART_Receiver1(unsigned char state)
{
    if(state)
    {
        U1STAbits.URXEN = 1; // Turn on the UART module receiver
    }
    else
    {
        U1STAbits.URXEN = 0; // Turn off the UART module receiver
    }
}

/******************************************************************************/
/* UART_Receiver2
 *
 * The function controls the UART module 2 receiver.
/******************************************************************************/
void UART_Receiver2(unsigned char state)
{
    if(state)
    {
        U2STAbits.URXEN = 1; // Turn on the UART module receiver
    }
    else
    {
        U2STAbits.URXEN = 0; // Turn off the UART module receiver
    }
}

/******************************************************************************/
/* UART_Receiver3
 *
 * The function controls the UART module 3 receiver.
/******************************************************************************/
void UART_Receiver3(unsigned char state)
{
    if(state)
    {
        U3STAbits.URXEN = 1; // Turn on the UART module receiver
    }
    else
    {
        U3STAbits.URXEN = 0; // Turn off the UART module receiver
    }
}

/******************************************************************************/
/* UART_Receiver4
 *
 * The function controls the UART module 4 receiver.
/******************************************************************************/
void UART_Receiver4(unsigned char state)
{
    if(state)
    {
        U4STAbits.URXEN = 1; // Turn on the UART module receiver
    }
    else
    {
        U4STAbits.URXEN = 0; // Turn off the UART module receiver
    }
}

/******************************************************************************/
/* UART_Receiver5
 *
 * The function controls the UART module 5 receiver.
/******************************************************************************/
void UART_Receiver5(unsigned char state)
{
    if(state)
    {
        U5STAbits.URXEN = 1; // Turn on the UART module receiver
    }
    else
    {
        U5STAbits.URXEN = 0; // Turn off the UART module receiver
    }
}

/******************************************************************************/
/* UART_Transmitter1
 *
 * The function controls the UART module 1 transmitter.
/******************************************************************************/
void UART_Transmitter1(unsigned char state)
{
    if(state)
    {
        U1STAbits.UTXEN = 1; // Turn on the UART module transmitter
    }
    else
    {
        U1STAbits.UTXEN = 0; // Turn off the UART module transmitter
    }
}

/******************************************************************************/
/* UART_Transmitter2
 *
 * The function controls the UART module 2 transmitter.
/******************************************************************************/
void UART_Transmitter2(unsigned char state)
{
    if(state)
    {
        U2STAbits.UTXEN = 1; // Turn on the UART module transmitter
    }
    else
    {
        U2STAbits.UTXEN = 0; // Turn off the UART module transmitter
    }
}

/******************************************************************************/
/* UART_Transmitter3
 *
 * The function controls the UART module 3 transmitter.
/******************************************************************************/
void UART_Transmitter3(unsigned char state)
{
    if(state)
    {
        U3STAbits.UTXEN = 1; // Turn on the UART module transmitter
    }
    else
    {
        U3STAbits.UTXEN = 0; // Turn off the UART module transmitter
    }
}

/******************************************************************************/
/* UART_Transmitter4
 *
 * The function controls the UART module 4 transmitter.
/******************************************************************************/
void UART_Transmitter4(unsigned char state)
{
    if(state)
    {
        U4STAbits.UTXEN = 1; // Turn on the UART module transmitter
    }
    else
    {
        U4STAbits.UTXEN = 0; // Turn off the UART module transmitter
    }
}

/******************************************************************************/
/* UART_Transmitter5
 *
 * The function controls the UART module 5 transmitter.
/******************************************************************************/
void UART_Transmitter5(unsigned char state)
{
    if(state)
    {
        U5STAbits.UTXEN = 1; // Turn on the UART module transmitter
    }
    else
    {
        U5STAbits.UTXEN = 0; // Turn off the UART module transmitter
    }
}

/******************************************************************************/
/* UART_SendShortBreak1
 *
 * The function sends a short break on the next transmission.
/******************************************************************************/
void UART_SendShortBreak1(void)
{
    U1STAbits.UTXBRK = 1;
}

/******************************************************************************/
/* UART_SendShortBreak2
 *
 * The function sends a short break on the next transmission.
/******************************************************************************/
void UART_SendShortBreak2(void)
{
    U2STAbits.UTXBRK = 1;
}

/******************************************************************************/
/* UART_SendShortBreak3
 *
 * The function sends a short break on the next transmission.
/******************************************************************************/
void UART_SendShortBreak3(void)
{
    U3STAbits.UTXBRK = 1;
}

/******************************************************************************/
/* UART_SendShortBreak4
 *
 * The function sends a short break on the next transmission.
/******************************************************************************/
void UART_SendShortBreak4(void)
{
    U4STAbits.UTXBRK = 1;
}

/******************************************************************************/
/* UART_SendShortBreak5
 *
 * The function sends a short break on the next transmission.
/******************************************************************************/
void UART_SendShortBreak5(void)
{
    U5STAbits.UTXBRK = 1;
}

/******************************************************************************/
/* UART_SendLongBreak1
 *
 * The function sends a long break on the next transmission.
/******************************************************************************/
void UART_SendLongBreak1(void)
{
    LATC &= ~RASP_UART_TX;
    RPC4R = 0;        
    LATC |= RASP_UART_TX;
    MSC_DelayUS(LONG_BREAK_US);
    LATC &= ~RASP_UART_TX;
    RPC4R = RASP_UART_TX_Module;        // U1TX
}

/******************************************************************************/
/* UART_SendLongBreak2
 *
 * The function sends a long break on the next transmission.
/******************************************************************************/
void UART_SendLongBreak2(void)
{
    LATF &= ~RS232_MALE_TX;
    RPF5R = 0;        
    LATF |= RS232_MALE_TX;
    MSC_DelayUS(LONG_BREAK_US);
    LATF &= ~RS232_MALE_TX;
    RPF5R = RS232_MALE_TX_Module;       // U2TX
}

/******************************************************************************/
/* UART_SendLongBreak3
 *
 * The function sends a long break on the next transmission.
/******************************************************************************/
void UART_SendLongBreak3(void)
{
    LATD &= ~RS232_MALE_RTS;
    RPF5R = 0;        
    LATD |= RS232_MALE_RTS;
    MSC_DelayUS(LONG_BREAK_US);
    LATD &= ~RS232_MALE_TX;
    RPF5R = RS232_MALE_RTS_Module;      // U3TX
}

/******************************************************************************/
/* UART_SendLongBreak4
 *
 * The function sends a long break on the next transmission.
/******************************************************************************/
void UART_SendLongBreak4(void)
{
    LATF &= ~RS232_FEMALE_TX;
    RPF5R = 0;        
    LATF |= RS232_FEMALE_TX;
    MSC_DelayUS(LONG_BREAK_US);
    LATF &= ~RS232_FEMALE_TX;
    RPF12R = RS232_FEMALE_TX_Module;    // U4TX
}

/******************************************************************************/
/* UART_SendLongBreak5
 *
 * The function sends a long break on the next transmission.
/******************************************************************************/
void UART_SendLongBreak5(void)
{
    LATF &= ~RS232_FEMALE_RTS;
    RPF5R = 0;        
    LATF |= RS232_FEMALE_RTS;
    MSC_DelayUS(LONG_BREAK_US);
    LATF &= ~RS232_FEMALE_RTS;
    RPF8R = RS232_FEMALE_RTS_Module;    // U5TX
}

/******************************************************************************/
/* UART_RS232_Male
 *
 * The function controls the RS232 driver for the male DB9.
/******************************************************************************/
void UART_RS232_MaleDriver(unsigned char state)
{
    if(state)
    {
        LATA |= RS232_MALE_SHUTDOWN;    // take the driver out of shutdown
        LATD &= ~RS232_MALE_ENABLE;     // Enable the driver
    }
    else
    {
        LATD &= ~RS232_MALE_ENABLE;     // disable the driver
        LATA &= ~RS232_MALE_SHUTDOWN;    // shutdown the driver
    }
}

/******************************************************************************/
/* UART_RS232_Female
 *
 * The function controls the RS232 driver for the female DB9.
/******************************************************************************/
void UART_RS232_FemaleDriver(unsigned char state)
{
    if(state)
    {
        LATD |= RS232_FEMALE_SHUTDOWN;    // take the driver out of shutdown
        LATD &= ~RS232_FEMALE_ENABLE;     // Enable the driver
    }
    else
    {
        LATD &= ~RS232_FEMALE_ENABLE;     // disable the driver
        LATD &= ~RS232_FEMALE_SHUTDOWN;    // shutdown the driver
    }
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/