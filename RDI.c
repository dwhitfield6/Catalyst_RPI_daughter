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
/* Contains all of the Teledyne RD Instruments specific functions.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "RDI.h"
#include "MISC.h"
#include "UART.h"

/******************************************************************************/
/* Workhorse Horizontal Broadband ADCP Banner
 *
 * This is the banner for the workhorse H-ADCP.
/******************************************************************************/
const unsigned char Workhorse_H_ADCP[] = "WorkHorse Horizontal Broadband ADCP";

/******************************************************************************/
/* Catalyst banner strings
 *
 * This is the banner extention string for a product banner
/******************************************************************************/
const unsigned char Catalyst_PIC_only_String[] = "with Catalyst PIC board only";
const unsigned char Catalyst_String[] = "with Catalyst";

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
unsigned short RDI_product;
unsigned short Banner_Buffer_Place = 0;
unsigned char Banner_Buffer[Banner_RECEIVE_SIZE];
unsigned char GetProduct = FALSE;
volatile unsigned char BannerFinished = FALSE;
volatile unsigned char Banner_Correct_place = 0;

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitRDI
 *
 * The function initializes the RDI specific functions.
/******************************************************************************/
void InitRDI(void)
{
    RDI_product = 0;
}

/******************************************************************************/
/* RDI_GetProduct
 *
 * The function sends a break to the instrument and parses the banner to
 *  determine which RDI product is connected.
/******************************************************************************/
void RDI_GetProduct(void)
{
    unsigned long timer = 0;
    
    GetProduct = TRUE;
    RDI_ClearProduct();
    timer = 0;
    BannerFinished = 0;
    UART_SendLongBreak2();
    while(!BannerFinished)
    {
        MSC_DelayUS(1000);
        timer++;
        if(timer > Banner_TIMEOUT)
        {
            break;
        }            
    }

    RDI_PrintBanner();
    GetProduct = FALSE;
}

/******************************************************************************/
/* RDI_ClearProduct
 *
 * The function clears the RDI product and erases the saved banner.
/******************************************************************************/
void RDI_ClearProduct(void)
{
    RDI_product = 0;
        
    /* Clean receive buffers */
    MSC_CleanBuffer(Banner_Buffer, Banner_RECEIVE_SIZE);
    Banner_Buffer_Place = 0;
    Banner_Correct_place = 0;
}

/******************************************************************************/
/* RDI_PrintBanner
 *
 * The function prints the banner on the female rs232 port.
/******************************************************************************/
void RDI_PrintBanner(void)
{    
    UART_RS232_FemaleSendConstStringCRLN(CRLN);
    if(RDI_product == 0)
    {
        if(PWR_RASP_Connected())
        {
            UART_RS232_FemaleSendConstStringCRLN("Catalyst");
        }
        else
        {
            UART_RS232_FemaleSendConstStringCRLN("Catalyst PIC board only");
        }
    }
    else 
    {
        /* prshort product specific banner */
        if(RDI_product == PROD_WORKHORSE_HADCP)
        {
            UART_RS232_FemaleSendConstString(Workhorse_H_ADCP);
        }
        RDI_PrintBannerExtention();
        UART_RS232_FemaleSendConstString(CRLN);
    }
    UART_RS232_FemaleSendConstStringCRLN("RD Instruments (c) 2015");
    UART_RS232_FemaleSendConstStringCRLN("All rights reserved.");
    UART_RS232_FemaleSendConstString("Catalyst PIC Firmware Version: ");
    if(Version[0]!= 0)
    {
        UART_RS232_FemaleSendConstString(Version);
    }
    if(Revision[0]!= 0)
    {
        UART_RS232_FemaleSendChar('.');
        UART_RS232_FemaleSendConstString(Revision);
    }
    if(Alpha[0]!= 0)
    {
        UART_RS232_FemaleSendConstString(Alpha);
    }
    if(Branch_Version[0]!= 0)
    {
        UART_RS232_FemaleSendChar('_');
        UART_RS232_FemaleSendConstString(Branch_Version);
    }
    UART_RS232_FemaleSendConstStringCRLN(CRLN);
    UART_RS232_FemaleSendChar('>');
}

/******************************************************************************/
/* RDI_PrintBannerExtention
 *
 * The function prints the banner extention ("with catalyst") within the
 *  original banner.
/******************************************************************************/
void RDI_PrintBannerExtention(void)
{  
    UART_RS232_FemaleSendChar(' ');
    if(PWR_RASP_Connected())
    {
        UART_RS232_FemaleSendConstString(Catalyst_String);
    }
    else
    {
        UART_RS232_FemaleSendConstString(Catalyst_PIC_only_String);
    }
}
/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/