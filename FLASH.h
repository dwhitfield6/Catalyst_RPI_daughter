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
#ifndef FLASH_H
#define	FLASH_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "USER.h"

/******************************************************************************/
/* Structures                                                                 */
/******************************************************************************/
typedef struct id
{
    unsigned char ManuCode;
    unsigned char Device;
    unsigned char ChipNum;
    unsigned char CellType;
    unsigned char SimProgPages;
    unsigned char Interleave;
    unsigned char CacheProgram;
    unsigned char PageSize;
    unsigned short BlockSize;
    unsigned char SpareSize;
    unsigned char SerialAccessTime;
    unsigned char Organization;
    unsigned char Density;
    unsigned char Valid;
    unsigned long PlaneSize;
    unsigned char NumPlanes;
}ID;

typedef struct __attribute__((packed)) onfi
{
    unsigned char Signature[4];
    unsigned short Revision;
    unsigned short Features;
    unsigned short Commands;
    unsigned char reserved1[22];
    unsigned char Manufacturer[12];
    unsigned char Model[20];
    unsigned char JEDEC;
    unsigned short Code;
    unsigned char reserved2[12];
    unsigned long BytesPerPage;
    unsigned short SpareBytesPerPage;
    unsigned long DataBytesPerPartialPage;
    unsigned short SpareBytesPerPartialPage;
    unsigned long PagesPerBlock;
    unsigned long BlocksPerLUN;
    unsigned char reserved3;
    unsigned char LUNS;
    unsigned char AddressCycles;
    unsigned char BitsPerCell;
    unsigned short badBlocksMaxPerLUN;
    unsigned short BlockEndurance;
    unsigned char ValidBlocksAtBeginning;
    unsigned short BlockEnduranceForGuarBlocks;
    unsigned char ProgramsPerPage;
    unsigned char PartialProgrammingAttributes;
    unsigned char ECCcorrectibility;
    unsigned char InterleavedAddress;
    unsigned char OperationalAttributes;
    unsigned char reserved4[13];
    unsigned char IOcapacitance;
    unsigned short TimingModeSupport;
    unsigned short CachrTimingModeSupport;
    unsigned short PageProgramTime;
    unsigned short BlockEraseTime;
    unsigned short PageReadTime;
    unsigned short ChangeColumnSetupTime;
    unsigned char reserved5[22];
    unsigned short RevisionNumber;
    unsigned char VendorSpecific[88];
    unsigned short CRC;
}ONFI;

/******************************************************************************/
/* Delays
 *
 * This defines the delays in microseconds to delay for each state.
/******************************************************************************/
#define WRITE_DELAY     10
#define READ_DELAY      10
        
/******************************************************************************/
/* Chip states
 *
 * This defines the states that the Flash IC and be in.
/******************************************************************************/
#define COMMAND     0
#define ADDRESS     1
#define STANDBY     2
#define DATA        3
#define INPUT       1
#define OUTPUT      0

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
ID FlashID;
ONFI FlashONFI;

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
void InitExtFlash(void);
void FLH_EXT_ChipSelect(unsigned char state);
void FLH_EXT_WriteProtect(unsigned char state);
void FLH_EXT_WriteEnable(void);
void FLH_EXT_ReadEnable(void);
void FLH_EXT_AddressLatchEnable(unsigned char state);
void FLH_EXT_CommandLatchEnable(unsigned char state);
unsigned char FLH_EXT_ChipBusy(void);
void FLH_EXT_ChipState(unsigned char operation, unsigned char direction);
void FLH_EXT_Write(unsigned char command);
void FLH_EXT_WriteBuffer(unsigned long bytes, unsigned char* buffer);
unsigned char FLH_EXT_Read(void);
void FLH_EXT_ReadBuffer(unsigned long bytes, void* buffer);
void FLH_EXT_ReadID(void);
void FLH_EXT_ReadONFI(void);
void FLH_EXT_ReadPage(unsigned short ColumnAddress, unsigned short PageAddress, unsigned short BlockAddress);
#endif	/* FLASH_H */