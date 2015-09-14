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
/* PWM RED interrupt
/******************************************************************************/
void __ISR(_TIMER_2_VECTOR , IPL7AUTO) TMR2_IntHandler (void)
{
    OC1RS = Red_Duty; // Write Duty Cycle value for next PWM cycle
    OC2RS = Green_Duty; // Write Duty Cycle value for next PWM cycle
    OC3RS = Blue_Duty; // Write Duty Cycle value for next PWM cycle
    IFS0bits.T2IF = 0; // Clear Timer 2 interrupt flag
}

/******************************************************************************/
/* UART 2 Interrupt (Male rs232 DB9 connector)
/******************************************************************************/
void __ISR(_UART_2_VECTOR , IPL7AUTO) UART2_IntHandler (void)
{
    unsigned char data;
    
    data = U2RXREG;
    IFS1bits.U2RXIF = 0; // clear interrupt
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
            while(U4STAbits.URXDA)
            {
                /* 
                 * Receive error. This could be from a break or incorrect
                 *  baud rate 
                 */
                data = U4RXREG;
                if(!data)
                {
                    /* There was a break */
                    Nop();
                }
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
    IFS2bits.U4RXIF = 0; // clear interrupt
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/