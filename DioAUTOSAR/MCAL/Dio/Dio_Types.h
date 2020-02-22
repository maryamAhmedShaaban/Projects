/*
 * Dio_Types.h
 *
 *  Created on: Feb 21, 2020
 *      Author: TOSHIBA.SXO11
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_


/****************************************************************INCLUDES********************************************************/
#include "STD_types.h"

/****************************************************************CONSTANTS*******************************************************/
/* Dio Channels */

#define DIO_CHANNEL_A0  0
#define DIO_CHANNEL_A1  1
#define DIO_CHANNEL_A2  2
#define DIO_CHANNEL_A3  3
#define DIO_CHANNEL_A4  4
#define DIO_CHANNEL_A5  5
#define DIO_CHANNEL_A6  6
#define DIO_CHANNEL_A7  7

#define DIO_CHANNEL_B0  8
#define DIO_CHANNEL_B1  9
#define DIO_CHANNEL_B2  10
#define DIO_CHANNEL_B3  11
#define DIO_CHANNEL_B4  12
#define DIO_CHANNEL_B5  13
#define DIO_CHANNEL_B6  14
#define DIO_CHANNEL_B7  15

#define DIO_CHANNEL_C0  16
#define DIO_CHANNEL_C1  17
#define DIO_CHANNEL_C2  18
#define DIO_CHANNEL_C3  19
#define DIO_CHANNEL_C4  20
#define DIO_CHANNEL_C5  21
#define DIO_CHANNEL_C6  22
#define DIO_CHANNEL_C7  23

#define DIO_CHANNEL_D0  24
#define DIO_CHANNEL_D1  25
#define DIO_CHANNEL_D2  26
#define DIO_CHANNEL_D3  27
#define DIO_CHANNEL_D4  28
#define DIO_CHANNEL_D5  29
#define DIO_CHANNEL_D6  30
#define DIO_CHANNEL_D7  31

#define DIO_CHANNEL_E0  32
#define DIO_CHANNEL_E1  33
#define DIO_CHANNEL_E2  34
#define DIO_CHANNEL_E3  35
#define DIO_CHANNEL_E4  36
#define DIO_CHANNEL_E5  37
#define DIO_CHANNEL_E6  38
#define DIO_CHANNEL_E7  39

#define DIO_CHANNEL_F0  40
#define DIO_CHANNEL_F1  41
#define DIO_CHANNEL_F2  42
#define DIO_CHANNEL_F3  43
#define DIO_CHANNEL_F4  44

/*Dio Port Values*/
#define DIO_PORT_A  0
#define DIO_PORT_B  1
#define DIO_PORT_C  2
#define DIO_PORT_D  3
#define DIO_PORT_E  4
#define DIO_PORT_F  5

/*Dio Channel Levels*/
#define STD_LOW    0x00
#define STD_HIGH   0x01

/************************************************************PRIMITIVE TYPES*****************************************************/
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef struct Dio_ChannelGroupType
{
    uint8 mask;
    uint8 offset;
    Dio_PortType port;
}Dio_ChannelGroupType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;

#endif /* DIO_TYPES_H_ */
