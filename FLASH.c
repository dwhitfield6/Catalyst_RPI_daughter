/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/16/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Contains functions for the Flash IC. The IC part number is S34ML01G100TFI004.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "USER.h"
#include "FLASH.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Functions
/******************************************************************************/

/******************************************************************************/
/* InitExtFlash
 *
 * The function initializes the external flash IC S34ML01G100TFI004.
/******************************************************************************/
void InitExtFlash(void)
{
    FLH_EXT_ChipSelect(OFF);
    FLH_EXT_WriteProtect(ON);    
    FLH_EXT_CommandLatchEnable(OFF);
    FLH_EXT_AddressLatchEnable(OFF);
    FLH_EXT_WriteEnable();
    FLH_EXT_ReadEnable();
    FLH_EXT_ReadID();
    FLH_EXT_ReadONFI();
}

/******************************************************************************/
/* FLH_EXT_ChipSelect
 *
 * The function allows/protects from the chip to be read/written.
/******************************************************************************/
void FLH_EXT_ChipSelect(unsigned char state)
{
    if(state)
    {
        LATD &= ~ExtFlash_CE;
    }
    else
    {
        LATD |= ExtFlash_CE;
    }
}

/******************************************************************************/
/* FLH_EXT_WriteProtect
 *
 * The function protects from being written to.
/******************************************************************************/
void FLH_EXT_WriteProtect(unsigned char state)
{
    if(state)
    {
        LATG &= ~ExtFlash_WP;
    }
    else
    {
        LATG |= ExtFlash_WP;
    }
}

/******************************************************************************/
/* FLH_EXT_WriteEnable
 *
 * The function twitches the write enable pin.
/******************************************************************************/
void FLH_EXT_WriteEnable(void)
{
    LATD &= ~ExtFlash_WE; 
    MSC_DelayUS(WRITE_DELAY);
    LATD |= ExtFlash_WE;         
}

/******************************************************************************/
/* FLH_EXT_ReadEnable
 *
 * The function twitches the read enable pin.
/******************************************************************************/
void FLH_EXT_ReadEnable(void)
{
        LATD &= ~ExtFlash_RE;
        MSC_DelayUS(READ_DELAY);
        LATD |= ExtFlash_RE;
}

/******************************************************************************/
/* FLH_EXT_AddressLatchEnable
 *
 * The function twitches the address latch enable pin.
/******************************************************************************/
void FLH_EXT_AddressLatchEnable(unsigned char state)
{
    if(state)
    {
        LATB |= ExtFlash_ALE;
    }
    else
    {
        LATB &= ~ExtFlash_ALE;
    }      
}

/******************************************************************************/
/* FLH_EXT_CommandLatchEnable
 *
 * The function twitches the Command latch enable pin.
/******************************************************************************/
void FLH_EXT_CommandLatchEnable(unsigned char state)
{
    if(state)
    {
        LATB |= ExtFlash_CLE;
    }
    else
    {
        LATB &= ~ExtFlash_CLE;
    }      
}

/******************************************************************************/
/* FLH_EXT_ChipBusy
 *
 * The function returns the status of the flash IC.
/******************************************************************************/
unsigned char FLH_EXT_ChipBusy(void)
{
    if(PORTG & ExtFlash_RB)
    {
        return 0;
    }
    return 1;
}

/******************************************************************************/
/* FLH_EXT_ChipState
 *
 * The function controls the Flash IC state.
/******************************************************************************/
void FLH_EXT_ChipState(unsigned char operation, unsigned char direction)
{
    if(operation == COMMAND)
    {
        if(direction == INPUT)
        {
            FLH_EXT_CommandLatchEnable(ON);
            FLH_EXT_AddressLatchEnable(OFF);
            FLH_EXT_WriteProtect(OFF);     // don't allow the flash IC to be written to
            FLH_EXT_ChipSelect(ON);        // select the device
        }
    }
    else if(operation == ADDRESS)
    {
        if(direction == INPUT)
        {
            FLH_EXT_CommandLatchEnable(OFF);
            FLH_EXT_AddressLatchEnable(ON);
            FLH_EXT_WriteProtect(OFF);     // don't allow the flash IC to be written to
            FLH_EXT_ChipSelect(ON);        // select the device
        }
    }
    else if(operation == DATA)
    {
        FLH_EXT_CommandLatchEnable(OFF);
        FLH_EXT_AddressLatchEnable(OFF);
        FLH_EXT_WriteProtect(OFF);     // don't allow the flash IC to be written to
        FLH_EXT_ChipSelect(ON);        // select the device
    }
    else
    {
        /* Standby mode */
        FLH_EXT_WriteProtect(ON);
        FLH_EXT_ChipSelect(OFF);        // select the device
    }
}

/******************************************************************************/
/* FLH_EXT_Write
 *
 * The function writes to the command register.
/******************************************************************************/
void FLH_EXT_Write(unsigned char command)
{ 
    if(TRISE & 0x00FF)
    {
        TRISE &= ~0x00FF; // turn all Flash IO pins to OUTPUT
    }
    LATE &= ~ 0x00FF;
    LATE |= command;
    FLH_EXT_WriteEnable();
}

/******************************************************************************/
/* FLH_EXT_WriteBuffer
 *
 * The function writes a buffer to the flash IC.
/******************************************************************************/
void FLH_EXT_WriteBuffer(unsigned long bytes, unsigned char* buffer)
{
    unsigned long i;
    
    for(i=0;i<bytes;i++)
    {
        FLH_EXT_Write(*buffer);
        buffer++;
    }
}

/******************************************************************************/
/* FLH_EXT_Read
 *
 * The function writes to the command register.
/******************************************************************************/
unsigned char FLH_EXT_Read(void)
{
    unsigned char temp;
    if((TRISE & 0x00FF) == 0)
    {
        TRISE |= 0x00FF; // turn all Flash IO pins to INPUT
    }

    MSC_DelayUS(READ_DELAY);
    while(FLH_EXT_ChipBusy());
    FLH_EXT_ReadEnable();
    temp = PORTE & 0x00FF;
    return temp;
}

/******************************************************************************/
/* FLH_EXT_ReadBuffer
 *
 * The function reads the flash IC and fills a buffer.
/******************************************************************************/
void FLH_EXT_ReadBuffer(unsigned long bytes, void* buffer)
{
    unsigned long i;
    unsigned char temp;
    
    for(i=0;i<bytes;i++)
    {
        temp = FLH_EXT_Read();
        *(unsigned char*)buffer = temp;
        buffer++;
    }
}

/******************************************************************************/
/* FLH_EXT_ReadID
 *
 * The function reads the Flash IC's ID.
/******************************************************************************/
void FLH_EXT_ReadID(void)
{
    unsigned char temp;
    unsigned char Byte3;
    unsigned char Byte4;
    
    FlashID.Valid = FALSE;
    
    FLH_EXT_ChipState(COMMAND,INPUT);
    FLH_EXT_Write(0x90);
    
    FLH_EXT_ChipState(ADDRESS,INPUT);
    FLH_EXT_Write(0x00);
    
    /* first byte of ID */
    FlashID.ManuCode = FLH_EXT_Read(); 
    if(FlashID.ManuCode == 0)
    {
        return;
    }
    
    /* second byte of ID */
    FlashID.Device = FLH_EXT_Read();
    
    if(FlashID.Device == 0xF1 || FlashID.Device == 0xC1)
    {
        FlashID.Density = 1;
    }
    else if(FlashID.Device == 0xDA || FlashID.Device == 0xCA)
    {
        FlashID.Density = 2;
    }
    else if(FlashID.Device == 0xDC || FlashID.Device == 0xCC)
    {
        FlashID.Density = 4;
    }
    else
    {
        FlashID.ManuCode = 0;
        FlashID.Density = 0;
        return;
    }
    
    /* third byte of ID */
    Byte3 = FLH_EXT_Read();
    temp = Byte3 & 0x03; // bits 0 and 1 
    if(temp == 0b00)
    {
        FlashID.ChipNum = 1;       
    }
    else if(temp == 0b01)
    {
        FlashID.ChipNum = 2;
    }
    else if(temp == 0b10)
    {
        FlashID.ChipNum = 4;
    }
    else
    {
        FlashID.ChipNum = 8;
    }
    
    temp = (Byte3 & 0x0C) >> 2; // bits 2 and 3
    if(temp == 0b00)
    {
        FlashID.CellType = 2;       
    }
    else if(temp == 0b01)
    {
        FlashID.CellType = 4;
    }
    else if(temp == 0b10)
    {
        FlashID.CellType = 8;
    }
    else
    {
        FlashID.CellType = 16;
    }
    
    temp = (Byte3 & 0x30) >> 4; // bits 4 and 5
    if(temp == 0b00)
    {
        FlashID.SimProgPages = 1;       
    }
    else if(temp == 0b01)
    {
        FlashID.SimProgPages = 2;
    }
    else if(temp == 0b10)
    {
        FlashID.SimProgPages = 4;
    }
    else
    {
        FlashID.SimProgPages = 8;
    }
    
    temp = (Byte3 & 0x40) >> 6; // bit 6
    if(temp == 0)
    {
        FlashID.Interleave = FALSE;       
    }
    else
    {
        FlashID.Interleave = TRUE;
    }
    
    temp = (Byte3 & 0x80) >> 7; // bit 7
    if(temp == 0)
    {
        FlashID.CacheProgram = FALSE;       
    }
    else
    {
        FlashID.CacheProgram = TRUE;
    }
    
    /* forth byte of ID */
    Byte4 = FLH_EXT_Read();
    temp = Byte3 & 0x03; // bits 0 and 1
    if(temp == 0b00)
    {
        FlashID.PageSize = 1;       
    }
    else if(temp == 0b01)
    {
        FlashID.PageSize = 2;
    }
    else if(temp == 0b10)
    {
        FlashID.PageSize = 4;
    }
    else
    {
        FlashID.PageSize = 8;
    }
        
    temp = (Byte4 & 0x04) >> 3; // bit 2
    if(temp == 0)
    {
        FlashID.SpareSize = 8;       
    }
    else
    {
        FlashID.SpareSize = 16;
    }
    
    
    temp = (Byte4 & 0x88) >> 3; // bits 7 and 3
    if(temp == 0b0000)
    {
        FlashID.SerialAccessTime = 45;       
    }
    else if(temp == 0b0001)
    {
        FlashID.SerialAccessTime = 25;
    }
    else if(temp == 0b1000)
    {
        FlashID.SerialAccessTime = 0;
    }
    else
    {
        FlashID.SerialAccessTime = 0;
    }
    
    temp = (Byte4 & 0x30) >> 4; // bits 4 and 5
    if(temp == 0b00)
    {
        FlashID.BlockSize = 64;       
    }
    else if(temp == 0b01)
    {
        FlashID.BlockSize = 128;
    }
    else if(temp == 0b10)
    {
        FlashID.BlockSize = 256;
    }
    else
    {
        FlashID.BlockSize = 512;
    }
        
    temp = (Byte4 & 0x40) >> 6; // bit 6
    if(temp == 0)
    {
        FlashID.Organization = 8;       
    }
    else
    {
        FlashID.Organization = 16;
    }    
    
    if(FlashID.Density == 1)
    {
        FlashID.PlaneSize = (128 + 4) * 1024;
        FlashID.NumPlanes = 1;
    }
    else if(FlashID.Density == 2)
    {
        FlashID.PlaneSize = (128 + 4) * 1024;
        FlashID.NumPlanes = 2;
    }
    else
    {
        FlashID.PlaneSize = (128 + 4) * 2048;
        FlashID.NumPlanes = 2;
    }

    FlashID.Valid = TRUE;
    FLH_EXT_ChipState(STANDBY,INPUT);
}

/******************************************************************************/
/* FLH_EXT_ReadONFI
 *
 * The function reads the Flash IC's ONFI Read Parameter Page.
/******************************************************************************/
void FLH_EXT_ReadONFI(void)
{
    if(!FlashID.Valid)
    {
        return;
    }
    
    FLH_EXT_ChipState(COMMAND,INPUT);
    FLH_EXT_Write(0xEC);
    
    FLH_EXT_ChipState(ADDRESS,INPUT);
    FLH_EXT_Write(0x00);
    
    FLH_EXT_ReadBuffer(sizeof(FlashONFI),&FlashONFI);
    FLH_EXT_ChipState(STANDBY,INPUT);
}

/******************************************************************************/
/* FLH_EXT_ReadPage
 *
 * The function sends the sequence to Read a page.
/******************************************************************************/
void FLH_EXT_ReadPage(unsigned short ColumnAddress, unsigned short PageAddress, unsigned short BlockAddress)
{
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char forth;
    
    FLH_EXT_ChipState(COMMAND,INPUT);
    FLH_EXT_Write(0x00);
    
    FLH_EXT_ChipState(COMMAND,INPUT);
    FLH_EXT_Write(0x30);
    
    if(FlashID.Density == 1 && FlashID.Organization == 8)
    {
        first = ColumnAddress & 0x00FF;
        second = (ColumnAddress & 0x0F00) >> 8;
        third = (PageAddress & 0x003F);
        third |= (BlockAddress & 0x0003) << 6;
        forth = (BlockAddress & 0x03FC) >> 2;
        
        FLH_EXT_ChipState(ADDRESS,INPUT);
        FLH_EXT_Write(first);
        FLH_EXT_Write(second);
        FLH_EXT_Write(third);
        FLH_EXT_Write(forth);
    }
}

/*-----------------------------------------------------------------------------/
 End of File
/-----------------------------------------------------------------------------*/