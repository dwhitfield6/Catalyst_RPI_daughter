/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 09/15/15     1.0_DW0a    Initial project make.
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#ifndef I2C_H
#define	I2C_H

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "USER.h"

/******************************************************************************/
/* I2C timeouts
 *
 * This is the amount of loops to wait before we timeout for each state.
/******************************************************************************/
#define I2C_ACK_TIMEOUT 100000
#define I2C_SEND_TIMEOUT 100000
#define I2C_RECEIVE_TIMEOUT 100000

/******************************************************************************/
/* EEPROM address driver install I2C bus
 *
 * This is the address of the EEPROM IC connected to the driver install I2C
 *  bus.
/******************************************************************************/
#define I2C_RASP_DRV_EEPROM_ADDRESS 0b1010000

/******************************************************************************/
/* EEPROM address general purpose I2C bus
 *
 * This is the address of the EEPROM IC connected to the general purpose I2C
 *  bus.
/******************************************************************************/
#define I2C_RASP_GEN_EEPROM_ADDRESS 0b1010000

/******************************************************************************/
/* TPGD
 *
 * This is the Pulse Gobbler Delay (PGD) and is usually around 104 ns. Refer
 *  to the specific device data sheet for more information.
/******************************************************************************/
#define TPGD 0.000000104

/******************************************************************************/
/* I2C speeds
 *
 * This is the I2C bus speeds.
/******************************************************************************/
#define _100kHz     100000
#define _400kHz     400000
#define _1MHz       1000000

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define ACK     0
#define NACK    1
#define WRITE   2
#define READ    3

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
extern unsigned char I2C_1_ACK;

/******************************************************************************/
/* Macro Functions                                                            */
/******************************************************************************/

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/
inline void I2C_RASP_DRV_Start(void);
inline void I2C_RASP_GEN_Start(void);
inline void I2C_RASP_DRV_Stop(void);
inline void I2C_RASP_GEN_Stop(void);
inline void I2C_RASP_DRV_Restart(void);
inline void I2C_RASP_GEN_Restart(void);
inline void I2C_RASP_DRV_Ack(unsigned char state);
inline void I2C_RASP_GEN_Ack(unsigned char state);
inline unsigned char I2C_RASP_DRV_Address(unsigned char address, unsigned char Read_Write);
inline unsigned char I2C_RASP_GEN_Address(unsigned char address, unsigned char Read_Write);
void InitI2C(void);
void I2C_RASP_DRV_CTP(void);
void I2C_RASP_DRV_Interrupt(unsigned char master, unsigned char slave, unsigned char bus);
void I2C_RASP_GEN_Interrupt(unsigned char master, unsigned char slave, unsigned char bus);
unsigned char I2C_RASP_DRV_Module(unsigned char state);
unsigned char I2C_RASP_GEN_Module(unsigned char state);
void I2C_RASP_DRV_SetParameters(unsigned long Clock);
void I2C_RASP_GEN_SetParameters(unsigned long Clock);
unsigned char I2C_RASP_DRV_Write(unsigned char data);
unsigned char I2C_RASP_DRV_Read(unsigned char* data);
unsigned char I2C_RASP_DRV_EEPROMWrite(unsigned short DataAddress, unsigned char data);
unsigned char I2C_RASP_DRV_EEPROMRead(unsigned short DataAddress, unsigned char* data);

#endif	/* I2C_H */