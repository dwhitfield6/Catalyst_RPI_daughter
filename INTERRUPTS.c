/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 07/28/15     1.0_DW0a    Initial project make.                          
/******************************************************************************/

/******************************************************************************/
/* Interrupt Vector Options
 *
 * VECTOR NAMES:
 *
 * _CORE_TIMER_VECTOR          _COMPARATOR_2_VECTOR
 * _CORE_SOFTWARE_0_VECTOR     _UART_2A_VECTOR
 * _CORE_SOFTWARE_1_VECTOR     _I2C_2A_VECTOR
 * _EXTERNAL_0_VECTOR          _SPI_2_VECTOR
 * _TIMER_1_VECTOR             _SPI_2A_VECTOR
 * _INPUT_CAPTURE_1_VECTOR     _I2C_4_VECTOR
 * _OUTPUT_COMPARE_1_VECTOR    _UART_3_VECTOR
 * _EXTERNAL_1_VECTOR          _UART_2_VECTOR
 * _TIMER_2_VECTOR             _SPI_3A_VECTOR
 * _INPUT_CAPTURE_2_VECTOR     _I2C_3A_VECTOR
 * _OUTPUT_COMPARE_2_VECTOR    _UART_3A_VECTOR
 * _EXTERNAL_2_VECTOR          _SPI_4_VECTOR
 * _TIMER_3_VECTOR             _I2C_5_VECTOR
 * _INPUT_CAPTURE_3_VECTOR     _I2C_2_VECTOR
 * _OUTPUT_COMPARE_3_VECTOR    _FAIL_SAFE_MONITOR_VECTOR
 * _EXTERNAL_3_VECTOR          _RTCC_VECTOR
 * _TIMER_4_VECTOR             _DMA_0_VECTOR
 * _INPUT_CAPTURE_4_VECTOR     _DMA_1_VECTOR
 * _OUTPUT_COMPARE_4_VECTOR    _DMA_2_VECTOR
 * _EXTERNAL_4_VECTOR          _DMA_3_VECTOR
 * _TIMER_5_VECTOR             _DMA_4_VECTOR
 * _INPUT_CAPTURE_5_VECTOR     _DMA_5_VECTOR
 * _OUTPUT_COMPARE_5_VECTOR    _DMA_6_VECTOR
 * _SPI_1_VECTOR               _DMA_7_VECTOR
 * _I2C_3_VECTOR               _FCE_VECTOR
 * _UART_1A_VECTOR             _USB_1_VECTOR
 * _UART_1_VECTOR              _CAN_1_VECTOR
 * _SPI_1A_VECTOR              _CAN_2_VECTOR
 * _I2C_1A_VECTOR              _ETH_VECTOR
 * _SPI_3_VECTOR               _UART_4_VECTOR
 * _I2C_1_VECTOR               _UART_1B_VECTOR
 * _CHANGE_NOTICE_VECTOR       _UART_6_VECTOR
 * _ADC_VECTOR                 _UART_2B_VECTOR
 * _PMP_VECTOR                 _UART_5_VECTOR
 * _COMPARATOR_1_VECTOR        _UART_3B_VECTOR
 *
 * Refer to the device specific .h file in the C32 Compiler
 * pic32mx\include\proc directory for a complete Vector and IRQ mnemonic
 * listings for the PIC32 device.
 *
 * PRIORITY OPTIONS:
 *
 * (default) IPL0AUTO, IPL1, IPL2, ... IPL7 (highest)
 *
 * Example Shorthand Syntax
 *
 * void __ISR(<Vector Name>,<PRIORITY>) user_interrupt_routine_name(void)
 * {
 *     <Clear Interrupt Flag>
 * }
 *
 * For more interrupt macro examples refer to the C compiler User Guide in
 * the C compiler /doc directory.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>        /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <sys/attribs.h>     /* For __ISR definition */

#include "PWM.h"
#include "UART.h"
#include "RDI.h"
#include "RTCC.h"
#include "TIMERS.h"

/******************************************************************************/
/* Global Variables                                                           */
/******************************************************************************/

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/******************************************************************************/
/* PWM LED interrupt
/******************************************************************************/
void __ISR(_TIMER_2_VECTOR , IPL7AUTO) TMR2_IntHandler (void)
{
    if(PWM_Action)
    {
        if(PWM_Action == FADEUP)
        {
            if(PWM_TIMER > PWM_Speed)
            {
                if(Red_Duty != 0)
                {
                    Red_Duty += PWM_Steps*2;
                }
                if(Green_Duty != 0)
                {
                    Green_Duty += PWM_Steps*2;
                }
                if(Blue_Duty != 0)
                {
                    Blue_Duty += PWM_Steps*2; 
                }
                PWM_Steps++;
                if(PWM_Steps > 15)
                {
                    PWM_Steps = 0;
                    if(Red_Duty != 0)
                    {
                        Red_Duty = 1;
                    }
                    if(Green_Duty != 0)
                    {
                        Green_Duty = 1;
                    }
                    if(Blue_Duty != 0)
                    {
                        Blue_Duty = 1; 
                    }
                }
                PWM_TIMER = 0; 
            }            
            PWM_TIMER++;
        }
        else if(PWM_Action == FADEDOWN)
        {
            if(PWM_TIMER > PWM_Speed)
            {
                if(Red_Duty != 0)
                {
                    Red_Duty -= PWM_Steps*2;
                }
                if(Green_Duty != 0)
                {
                    Green_Duty -= PWM_Steps*2;
                }
                if(Blue_Duty != 0)
                {
                    Blue_Duty -= PWM_Steps*2; 
                }
                PWM_Steps++;
                if(PWM_Steps > 15)
                {
                    PWM_Steps = 0;
                    if(Red_Duty != 0)
                    {
                        Red_Duty = 241;
                    }
                    if(Green_Duty != 0)
                    {
                        Green_Duty = 241;
                    }
                    if(Blue_Duty != 0)
                    {
                        Blue_Duty = 241; 
                    }
                }
                PWM_TIMER = 0; 
            }            
            PWM_TIMER++;
        }
        else if(PWM_Action == FADEUPDOWN)
        {
            if(PWM_TIMER > PWM_Speed)
            {
                PWM_Steps++;
                if(PWM_Steps > 15)
                {
                    if(PWM_Direction == UP)
                    {
                        PWM_Direction = DOWN;
                    }
                    else
                    {
                        PWM_Direction = UP;
                    }
                    PWM_Steps = 0;
                }
                if(PWM_Direction == UP)
                {
                    if(Red_Duty != 0)
                    {
                        Red_Duty += PWM_Steps*2;
                    }
                    if(Green_Duty != 0)
                    {
                        Green_Duty += PWM_Steps*2;
                    }
                    if(Blue_Duty != 0)
                    {
                        Blue_Duty += PWM_Steps*2; 
                    }
                }
                else
                {
                    if(Red_Duty != 0)
                    {
                        Red_Duty -= PWM_Steps*2;
                    }
                    if(Green_Duty != 0)
                    {
                        Green_Duty -= PWM_Steps*2;
                    }
                    if(Blue_Duty != 0)
                    {
                        Blue_Duty -= PWM_Steps*2; 
                    }
                }   
                PWM_TIMER = 0;
            }
            PWM_TIMER++;
        }
        else if(PWM_Action == BLINK)
        {
            if(PWM_TIMER > PWM_Speed/2)
            {
                OC3RS = Red_Duty; // Write Duty Cycle value for next PWM cycle
                OC2RS = Green_Duty; // Write Duty Cycle value for next PWM cycle
                OC1RS = Blue_Duty; // Write Duty Cycle value for next PWM cycle
            }
            else
            {
                OC3RS = 0; // Write Duty Cycle value for next PWM cycle
                OC2RS = 0; // Write Duty Cycle value for next PWM cycle
                OC1RS = 0; // Write Duty Cycle value for next PWM cycle
            }
            if(PWM_TIMER > PWM_Speed)
            {
                PWM_TIMER = 0;
            }
            PWM_TIMER++;
        }
    }

    if(PWM_Action != BLINK)
    {
        OC3RS = Red_Duty; // Write Duty Cycle value for next PWM cycle
        OC2RS = Green_Duty; // Write Duty Cycle value for next PWM cycle
        OC1RS = Blue_Duty; // Write Duty Cycle value for next PWM cycle
    }
    IFS0bits.T2IF = 0; // Clear Timer 2 interrupt flag
}

/******************************************************************************/
/* SPI bus to raspberry pi interrupt
/******************************************************************************/
void __ISR(_SPI_2_VECTOR , IPL7AUTO) SPI2_IntHandler (void)
{
    if(IFS1bits.SPI2RXIF)
    {
        /* there are no more word in the receive buffer */
    }
    if(IFS1bits.SPI2TXIF)
    {
        /* there are no more word in the transmit buffer */
    }
    IFS1bits.SPI2RXIF = 0;            // clear interrupt
    IFS1bits.SPI2TXIF = 0;            // clear interrupt
}

/******************************************************************************/
/* UART 2 Interrupt (Male rs232 DB9 connector)
/******************************************************************************/
void __ISR(_UART_2_VECTOR , IPL7AUTO) UART2_IntHandler (void)
{
    unsigned char data;
    
    if(IFS1bits.U2RXIF)
    {
        /* receive interrupt */        
        if(U2STAbits.FERR)
        {
            /* 
             * Receive error. This could be from a break or incorrect
             *  baud rate 
             */
            while(U2STAbits.URXDA)
            {
                data = U2RXREG;
                if(!data)
                {
                    /* There was a break */
                    Nop();
                }
            }
        }
        else
        {
            while(U2STAbits.URXDA)
            {
                /* receive buffer has data */
                if(!GetProduct)
                {
                    data = U2RXREG;
                    UART_RS232_FemaleSendChar(data);
                    if(RX2_Buffer_Place < UART2_RECEIVE_SIZE)
                    {
                        RX2_Buffer[RX2_Buffer_Place] = data;
                        RX2_Buffer_Place++;
                    }
                    else
                    {
                        /* Overflow */
                        UART_CleanReceive2();
                    }    
                    if(UserSentBreak && RDI_product)
                    {
                        /* 
                         * The user sent a break and we have a valid product
                         *  so insert the extra catalyst message in the banner 
                         */
                        if(data == Workhorse_H_ADCP[Banner_Correct_place])
                        {  
                            Banner_Correct_place++;
                            if(Workhorse_H_ADCP[Banner_Correct_place] == 0)
                            {
                                /* banner match for Workhorse HADCP */
                                RDI_PrintBannerExtention();
                                UserSentBreak = FALSE;
                            }
                        }   
                    }                
                }
                else
                {
                    data = U2RXREG;
                    if(Banner_Buffer_Place < Banner_RECEIVE_SIZE)
                    {
                        Banner_Buffer[Banner_Buffer_Place] = data;
                        Banner_Buffer_Place++;
                        if(data == Workhorse_H_ADCP[Banner_Correct_place])
                        {  
                            Banner_Correct_place++;
                            if(Workhorse_H_ADCP[Banner_Correct_place] == 0)
                            {
                                RDI_product = PROD_WORKHORSE_HADCP;
                            }
                        }
                        else
                        {
                            Banner_Correct_place = 0;
                        }                        
                    }
                    if(data == '>')
                    {
                        BannerFinished = TRUE;
                    }
                }
            }
        }
    }
    if(IFS1bits.U2TXIF)
    {
        if(TX2_Buffer_REMOVE_Place != TX2_Buffer_ADD_Place)
        {
            U2TXREG = TX2_Buffer[TX2_Buffer_REMOVE_Place];
            TX2_Buffer_REMOVE_Place++;
            if(TX2_Buffer_REMOVE_Place >= UART2_TRANSMIT_SIZE)
            {
                TX2_Buffer_REMOVE_Place = 0;
            }
        }
        else
        {
            UART_TransmitterInterrupt2(OFF);
        }
    }
    IFS1bits.U2RXIF = 0;
    IFS1bits.U2TXIF = 0; 
}

/******************************************************************************/
/* UART 4 Interrupt (Female rs232 DB9 connector)
/******************************************************************************/
void __ISR(_UART_4_VECTOR , IPL7AUTO) UART4_IntHandler (void)
{
    unsigned char data;

    
    if(IFS2bits.U4RXIF)
    {
        /* receive interrupt */        
        if(U4STAbits.FERR)
        {
            /* 
             * Receive error. This could be from a break or incorrect
             *  baud rate 
             */
            while(U4STAbits.URXDA)
            {
                data = U4RXREG;
                if(!data)
                {
                    /* There was a break */
                    UserSentBreak = TRUE;
                    Banner_Correct_place = 0;
                }
            }
            if(UserSentBreak)
            {
                UART_SendLongBreak2();
            }
        }
        else
        {
            while(U4STAbits.URXDA)
            {
                /* receive buffer has data */
                data = U4RXREG;
                UART_RS232_MaleSendChar(data);
                if(RX4_Buffer_Place < UART4_RECEIVE_SIZE)
                {
                    RX4_Buffer[RX4_Buffer_Place] = data;
                    RX4_Buffer_Place++;
                }
                else
                {
                    /* Overflow */
                    UART_CleanReceive4();
                }
            }
        }
    }
    if(IFS2bits.U4TXIF)
    {
        if(TX4_Buffer_REMOVE_Place != TX4_Buffer_ADD_Place)
        {
            U4TXREG = TX4_Buffer[TX4_Buffer_REMOVE_Place];
            TX4_Buffer_REMOVE_Place++;
            if(TX4_Buffer_REMOVE_Place >= UART4_TRANSMIT_SIZE)
            {
                TX4_Buffer_REMOVE_Place = 0;
            }
        }
        else
        {
            UART_TransmitterInterrupt4(OFF);
        }
    }
    IFS2bits.U4RXIF = 0;
    IFS2bits.U4TXIF = 0;
}

/******************************************************************************/
/* Real Time Clock Alarm Interrupt
/******************************************************************************/
void __ISR(_RTCC_VECTOR , IPL7AUTO) RTCC_IntHandler (void)
{
    PWM_SetColor(PURPLE, FADEUPDOWN,PWM_MEDIUM);
    IFS0bits.RTCCIF = 0;
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/