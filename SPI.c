/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/12/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Contains functions for the SPI controller.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "SPI.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Inline Functions
/******************************************************************************/

/******************************************************************************/
/* SPI_Module
 *
 * The function controls the SPI module 2.
/******************************************************************************/
inline void SPI_Module(unsigned char state)
{

#ifdef ON
    #undef ON
    if(state)
    {
        SPI2CONbits.ON = 1; // Turn on the SPI module
    }
    else
    {
        SPI2CONbits.ON = 0; // Turn off the SPI module
    }
    #define ON 1
#else
    if(state)
    {
        SPI2CONbits.ON = 1; // Turn on the SPI module
    }
    else
    {
        SPI2CONbits.ON = 0; // Turn off the SPI module
    }
#endif    
}

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitSPI
 *
 * The function initializes the SPI module.
/******************************************************************************/
void InitSPI(void)
{
    SPI2CONbits.DISSDO = 0; // SDO pin is controlled by the module
    SPI2CONbits.DISSDI = 0; // SDI pin is controlled by the module
    SPI_Mode(MASTER, BITS8, 0);
}

/******************************************************************************/
/* SPI_Mode
 *
 * The function configures the SPI module.
/******************************************************************************/
void SPI_Mode(unsigned char master_slave, unsigned char bits, unsigned char mode)
{
    if(master_slave == MASTER)
    {
        SPI2CONbits.MSTEN = 1; // master mode
    }
    else
    {
        SPI2CONbits.MSTEN = 0; // slave mode   
    }
    
    if(bits == 8)
    {
        SPI2CONbits.MODE16 = 0;
        SPI2CONbits.MODE32 = 0;
    }
    else if(bits == 16)
    {
        SPI2CONbits.MODE16 = 1;
        SPI2CONbits.MODE32 = 0;
    }
    else
    {
        SPI2CONbits.MODE16 = 1;
        SPI2CONbits.MODE32 = 1;
    }
    
    if(mode == 0)
    {
        
    }
    else if(mode == 1)
    {
        
    }
    else if(mode == 2)
    {
        
    }
    else
    {
        
    }
    
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/