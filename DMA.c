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
/* Contains functions for direct memory access controller.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "DMA.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* DMA_Module
 *
 * The function enables/disables the DMA controller.
/******************************************************************************/
inline unsigned char DMA_Module(unsigned char state)
{
#ifdef ON
    #undef ON
    unsigned char status = DMACONbits.ON;
    if(state)
    {
        DMACONbits.ON = 1; // DMA module is enabled
    }
    else
    {
        DMACONbits.ON = 0; // DMA module is disabled
    }
    #define ON 1
#else
    unsigned char status = DMACONbits.ON;
    if(state)
    {
        DMACONbits.ON = 1; // DMA module is enabled
    }
    else
    {
        DMACONbits.ON = 0; // DMA module is disabled
    }
#endif    
    return status;
}

/******************************************************************************/
/* DMA_Suspend
 *
 * The function controls the DMA controller.
/******************************************************************************/
inline unsigned char DMA_Suspend(unsigned char state)
{
    unsigned char status = DMACONbits.SUSPEND;
    if(state)
    {
        DMACONbits.SUSPEND = 1; // DMA transfers are suspended to allow CPU uninterrupted access to data bus
    }
    else
    {
        DMACONbits.SUSPEND = 0; // DMA operates normally
    }
    return status;
}

/******************************************************************************/
/* DMA_Busy
 *
 * The function controls the DMA controller.
/******************************************************************************/
inline unsigned char DMA_Busy(void)
{
    return DMACONbits.DMABUSY;
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitI2C
 *
 * The function initializes the I2C module.
/******************************************************************************/
void InitDMA(void)
{
    IPC10bits.DMA0IP = 3; // interrupt priority is 3
    IPC10bits.DMA0IS = 1; // interrupt sub-priority is 1
    IPC10bits.DMA1IP = 3; // interrupt priority is 3
    IPC10bits.DMA1IS = 1; // interrupt sub-priority is 1
    IPC11bits.DMA2IP = 3; // interrupt priority is 3
    IPC11bits.DMA2IS = 1; // interrupt sub-priority is 1
    IPC11bits.DMA3IP = 3; // interrupt priority is 3
    IPC11bits.DMA3IS = 1; // interrupt sub-priority is 1
    DMA_RBG_Configure();
    DMA_Module(ON);
}

/******************************************************************************/
/* DMA_ChannelBusy
 *
 * The function returns the status of the DMA channel.
/******************************************************************************/
unsigned char DMA_ChannelBusy(unsigned char channel)
{
    if(channel == 0)
    {
        return DCH0CONbits.CHBUSY;
    }
    else if(channel == 1)
    {
        return DCH1CONbits.CHBUSY;
    }
    else if(channel == 2)
    {
        return DCH2CONbits.CHBUSY;
    }
    else
    {
        return DCH3CONbits.CHBUSY;
    }
}

/******************************************************************************/
/* DMA_ChannelEnable
 *
 * The function enables/disables a channel on the DMA module.
/******************************************************************************/
unsigned char DMA_ChannelEnable(unsigned char channel, unsigned char state)
{
    unsigned char status;
    
    if(channel == 0)
    {
        status = DCH0CONbits.CHEN;
        if(state)
        {
            DCH0CONbits.CHEN = 1; // Channel is enabled
        }
        else
        {
            DCH0CONbits.CHEN = 0; // Channel is disabled
        }
    }
    else if(channel == 1)
    {
        status = DCH1CONbits.CHEN;
        if(state)
        {
            DCH1CONbits.CHEN = 1; // Channel is enabled
        }
        else
        {
            DCH1CONbits.CHEN = 0; // Channel is disabled
        }
    }
    else if(channel == 2)
    {
        status = DCH2CONbits.CHEN;
        if(state)
        {
            DCH2CONbits.CHEN = 1; // Channel is enabled
        }
        else
        {
            DCH2CONbits.CHEN = 0; // Channel is disabled
        }
    }
    else
    {
        status = DCH3CONbits.CHEN;
        if(state)
        {
            DCH3CONbits.CHEN = 1; // Channel is enabled
        }
        else
        {
            DCH3CONbits.CHEN = 0; // Channel is disabled
        }  
    }
    return status;
}

/******************************************************************************/
/* DMA_ChannelEnable
 *
 * The function enables/disables the automatic enable for a channel.
/******************************************************************************/
unsigned char DMA_ChannelAutoEnable(unsigned char channel, unsigned char state)
{
    unsigned char status;
    
    if(channel == 0)
    {
        status = DCH0CONbits.CHAEN;
        if(state)
        {
            DCH0CONbits.CHAEN = 1; // Channel is continuously enabled, and not automatically disabled after a block transfer is complete
        }
        else
        {
            DCH0CONbits.CHAEN = 0; // Channel is disabled on block transfer complete
        }
    }
    else if(channel == 1)
    {
        status = DCH1CONbits.CHAEN;
        if(state)
        {
            DCH1CONbits.CHAEN = 1; // Channel is continuously enabled, and not automatically disabled after a block transfer is complete
        }
        else
        {
            DCH1CONbits.CHAEN = 0; // Channel is disabled on block transfer complete
        }
    }
    else if(channel == 2)
    {
        status = DCH2CONbits.CHAEN;
        if(state)
        {
            DCH2CONbits.CHAEN = 1; // Channel is continuously enabled, and not automatically disabled after a block transfer is complete
        }
        else
        {
            DCH2CONbits.CHAEN = 0; // Channel is disabled on block transfer complete
        }
    }
    else
    {
        status = DCH3CONbits.CHAEN;
        if(state)
        {
            DCH3CONbits.CHAEN = 1; // Channel is continuously enabled, and not automatically disabled after a block transfer is complete
        }
        else
        {
            DCH3CONbits.CHAEN = 0; // Channel is disabled on block transfer complete
        }
    }
    return status;
}

/******************************************************************************/
/* DMA_ChannelChain
 *
 * The function enables/disables the channel chaining feature.
/******************************************************************************/
unsigned char DMA_ChannelChain(unsigned char channel, unsigned char chained, unsigned char ChainPriority)
{
    unsigned char status;
    
    if(channel == 0)
    {
        status = DCH0CONbits.CHCHN;
        if(chained)
        {
            DCH0CONbits.CHCHN = 1; // Allow channel to be chained
        }
        else
        {
            DCH0CONbits.CHCHN = 0; // Do not allow channel to be chained
        }
        if(ChainPriority)
        {
            DCH0CONbits.CHCHNS = 1; // Chain to channel lower in natural priority (CH1 will be enabled by CH2 transfer complete)
        }
        else
        {
            DCH0CONbits.CHCHNS = 0; //Chain to channel higher in natural priority (CH1 will be enabled by CH0 transfer complete)
        }
    }
    else if(channel == 1)
    {
        status = DCH1CONbits.CHCHN;
        if(chained)
        {
            DCH1CONbits.CHCHN = 1; // Allow channel to be chained
        }
        else
        {
            DCH1CONbits.CHCHN = 0; // Do not allow channel to be chained
        }
        if(ChainPriority)
        {
            DCH1CONbits.CHCHNS = 1; // Chain to channel lower in natural priority (CH1 will be enabled by CH2 transfer complete)
        }
        else
        {
            DCH1CONbits.CHCHNS = 0; //Chain to channel higher in natural priority (CH1 will be enabled by CH0 transfer complete)
        }
    }
    else if(channel == 2)
    {
        status = DCH2CONbits.CHCHN;
        if(chained)
        {
            DCH2CONbits.CHCHN = 1; // Allow channel to be chained
        }
        else
        {
            DCH2CONbits.CHCHN = 0; // Do not allow channel to be chained
        }
        if(ChainPriority)
        {
            DCH2CONbits.CHCHNS = 1; // Chain to channel lower in natural priority (CH1 will be enabled by CH2 transfer complete)
        }
        else
        {
            DCH2CONbits.CHCHNS = 0; //Chain to channel higher in natural priority (CH1 will be enabled by CH0 transfer complete)
        }
    }
    else
    {
        status = DCH3CONbits.CHCHN;
        if(chained)
        {
            DCH3CONbits.CHCHN = 1; // Allow channel to be chained
        }
        else
        {
            DCH3CONbits.CHCHN = 0; // Do not allow channel to be chained
        }
        if(ChainPriority)
        {
            DCH3CONbits.CHCHNS = 1; // Chain to channel lower in natural priority (CH1 will be enabled by CH2 transfer complete)
        }
        else
        {
            DCH3CONbits.CHCHNS = 0; //Chain to channel higher in natural priority (CH1 will be enabled by CH0 transfer complete)
        }
    }
    return status;
}

/******************************************************************************/
/* DMA_ChannelPriority
 *
 * The function sets the channel priority.
/******************************************************************************/
unsigned char DMA_ChannelPriority(unsigned char channel, unsigned char priority)
{
    unsigned char status;
    if(priority > 3)
    {
       priority = 3;
    }
    
    if(channel == 0)
    {
        status = DCH0CONbits.CHPRI;
        DCH0CONbits.CHPRI = priority; // channel priority (3 is highest 0 is lowest)
    }
    else if(channel == 1)
    {
        status = DCH1CONbits.CHPRI;
        DCH1CONbits.CHPRI = priority; // channel priority (3 is highest 0 is lowest)
    }
    else if(channel == 2)
    {
        status = DCH2CONbits.CHPRI;
        DCH2CONbits.CHPRI = priority; // channel priority (3 is highest 0 is lowest)
    }
    else
    {
        status = DCH3CONbits.CHPRI;
        DCH3CONbits.CHPRI = priority; // channel priority (3 is highest 0 is lowest)
    }
    return status;    
}

/******************************************************************************/
/* DMA_ChannelTransferSource
 *
 * The function sets the channel transfer source.
/******************************************************************************/
unsigned char DMA_ChannelTransferSource(unsigned char channel, unsigned char source, unsigned char enable)
{
    unsigned char status;
    
    if(channel == 0)
    {
        status = DCH0ECONbits.SIRQEN;
        DCH0ECONbits.CHSIRQ = source;
        if(enable)
        {
            DCH0ECONbits.SIRQEN = 1; // Start channel cell transfer if an interrupt matching CHSIRQ occurs
        }
        else
        {
            DCH0ECONbits.SIRQEN = 0; // Interrupt number CHSIRQ is ignored and does not start a transfer
        }
    }
    else if(channel == 1)
    {
        status = DCH1ECONbits.SIRQEN;
        DCH1ECONbits.CHSIRQ = source;
        if(enable)
        {
            DCH1ECONbits.SIRQEN = 1; // Start channel cell transfer if an interrupt matching CHSIRQ occurs
        }
        else
        {
            DCH1ECONbits.SIRQEN = 0; // Interrupt number CHSIRQ is ignored and does not start a transfer
        }
    }
    else if(channel == 2)
    {
        status = DCH2ECONbits.SIRQEN;
        DCH2ECONbits.CHSIRQ = source;
        if(enable)
        {
            DCH2ECONbits.SIRQEN = 1; // Start channel cell transfer if an interrupt matching CHSIRQ occurs
        }
        else
        {
            DCH2ECONbits.SIRQEN = 0; // Interrupt number CHSIRQ is ignored and does not start a transfer
        }
    }
    else
    {
        status = DCH3ECONbits.SIRQEN;
        DCH3ECONbits.CHSIRQ = source;
        if(enable)
        {
            DCH3ECONbits.SIRQEN = 1; // Start channel cell transfer if an interrupt matching CHSIRQ occurs
        }
        else
        {
            DCH3ECONbits.SIRQEN = 0; // Interrupt number CHSIRQ is ignored and does not start a transfer
        }
    }
    return status;
}   

/******************************************************************************/
/* DMA_ChannelAbortSource
 *
 * The function sets the channel abort source.
/******************************************************************************/
unsigned char DMA_ChannelAbortSource(unsigned char channel, unsigned char source, unsigned char enable)
{
    unsigned char status;
    
    if(channel == 0)
    {
        status = DCH0ECONbits.AIRQEN;
        DCH0ECONbits.CHAIRQ = source;
        if(enable)
        {
            DCH0ECONbits.AIRQEN = 1; // Channel transfer is aborted if an interrupt matching CHAIRQ occurs
        }
        else
        {
            DCH0ECONbits.AIRQEN = 0; // Interrupt number CHAIRQ is ignored and does not terminate a transfer
        }
    }
    else if(channel == 1)
    {
        status = DCH1ECONbits.AIRQEN;
        DCH1ECONbits.CHAIRQ = source;
        if(enable)
        {
            DCH1ECONbits.AIRQEN = 1; // Channel transfer is aborted if an interrupt matching CHAIRQ occurs
        }
        else
        {
            DCH1ECONbits.AIRQEN = 0; // Interrupt number CHAIRQ is ignored and does not terminate a transfer
        }
    }
    else if(channel == 2)
    {
        status = DCH2ECONbits.AIRQEN;
        DCH2ECONbits.CHAIRQ = source;
        if(enable)
        {
            DCH2ECONbits.AIRQEN = 1; // Channel transfer is aborted if an interrupt matching CHAIRQ occurs
        }
        else
        {
            DCH2ECONbits.AIRQEN = 0; // Interrupt number CHAIRQ is ignored and does not terminate a transfer
        }
    }
    else
    {
        status = DCH3ECONbits.AIRQEN;
        DCH3ECONbits.CHAIRQ = source;
        if(enable)
        {
            DCH3ECONbits.AIRQEN = 1; // Channel transfer is aborted if an interrupt matching CHAIRQ occurs
        }
        else
        {
            DCH3ECONbits.AIRQEN = 0; // Interrupt number CHAIRQ is ignored and does not terminate a transfer
        }
    }
    return status;
} 

/******************************************************************************/
/* DMA_ChannelInterrupt
 *
 * The function sets up the DMA interrupt.
/******************************************************************************/
unsigned char DMA_ChannelInterrupt(unsigned char channel, unsigned char Interruptbits, unsigned char Enablebits, unsigned char MasterEnable)
{
    unsigned char status;
    
    if(channel == 0)
    {
        if(Interruptbits != DMA_INT_NoChange)
        {
            if(Enablebits)
            {
                DCH0INT |= Interruptbits; // enable the specific interrupt
            }
            else
            {
                DCH0INT &= ~Interruptbits; // disable the specific interrupt
            }
        }
        status = IEC2bits.DMA0IE; 
        if(MasterEnable)
        {
            IEC2bits.DMA0IE = 1; // enable interrupt
        }
        else
        {
            IEC2bits.DMA0IE = 0; // disable interrupt
        }
    }
    else if(channel == 1)
    {
        if(Interruptbits != DMA_INT_NoChange)
        {
            if(Enablebits)
            {
                DCH1INT |= Interruptbits; // enable the specific interrupt
            }
            else
            {
                DCH1INT &= ~Interruptbits; // disable the specific interrupt
            }
        }
        status = IEC2bits.DMA1IE; 
        if(MasterEnable)
        {
            IEC2bits.DMA1IE = 1; // enable interrupt
        }
        else
        {
            IEC2bits.DMA1IE = 0; // disable interrupt
        }
    }
    else if(channel == 2)
    {
        if(Interruptbits != DMA_INT_NoChange)
        {
            if(Enablebits)
            {
                DCH2INT |= Interruptbits; // enable the specific interrupt
            }
            else
            {
                DCH2INT &= ~Interruptbits; // disable the specific interrupt
            }
        }
        status = IEC2bits.DMA2IE; 
        if(MasterEnable)
        {
            IEC2bits.DMA2IE = 1; // enable interrupt
        }
        else
        {
            IEC2bits.DMA2IE = 0; // disable interrupt
        }
    }
    else
    {
        if(Interruptbits != DMA_INT_NoChange)
        {
            if(Enablebits)
            {
                DCH3INT |= Interruptbits; // enable the specific interrupt
            }
            else
            {
                DCH3INT &= ~Interruptbits; // disable the specific interrupt
            }
        }
        status = IEC2bits.DMA3IE; 
        if(MasterEnable)
        {
            IEC2bits.DMA3IE = 1; // enable interrupt
        }
        else
        {
            IEC2bits.DMA3IE = 0; // disable interrupt
        }
    }
    return status;
}

/******************************************************************************/
/* DMA_ChannelSource
 *
 * The function sets source address and size of the source.
/******************************************************************************/
void DMA_ChannelSource(unsigned char channel, unsigned short StartAddress, unsigned short size)
{
    if(channel == 0)
    {
        DCH0SSA = StartAddress;
        DCH0SSIZ = size;
    }
    else if(channel == 1)
    {
        DCH1SSA = StartAddress;
        DCH1SSIZ = size;
    }
    else if(channel == 2)
    {
        DCH2SSA = StartAddress;
        DCH2SSIZ = size;
    }
    else
    {
        DCH3SSA = StartAddress;
        DCH3SSIZ = size;
    }
}

/******************************************************************************/
/* DMA_ChannelDestination
 *
 * The function sets destination address and size of the destination.
/******************************************************************************/
void DMA_ChannelDestination(unsigned char channel, unsigned short StartAddress, unsigned short size)
{
    if(channel == 0)
    {
        DCH0DSA = StartAddress;
        DCH0DSIZ = size;
    }
    else if(channel == 1)
    {
        DCH1DSA = StartAddress;
        DCH1DSIZ = size;
    }
    else if(channel == 2)
    {
        DCH2DSA = StartAddress;
        DCH2DSIZ = size;
    }
    else
    {
        DCH3DSA = StartAddress;
        DCH3DSIZ = size;
    }
}

/******************************************************************************/
/* DMA_ChannelTransferSize
 *
 * The function sets the size of a transfer.
/******************************************************************************/
void DMA_ChannelTransferSize(unsigned char channel, unsigned short size)
{
    if(channel == 0)
    {
        DCH0CSIZ = size;
    }
    else if(channel == 1)
    {
        DCH1CSIZ = size;
    }
    else if(channel == 2)
    {
        DCH2CSIZ = size;
    }
    else
    {
        DCH3CSIZ = size;
    }   
}

/******************************************************************************/
/* DMA_RBG_Configure
 *
 * The function sets up DMA transfer of the PWM values for the RGB LED.
/******************************************************************************/
void DMA_RBG_Configure(void)
{
    /* set up DMA channel 0 for the Red LED */
    
    /* set up DMA channel 1 for the Green LED */
    
    /* set up DMA channel 2 for the Blue LED */
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/