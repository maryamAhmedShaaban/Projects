/*
 * Dio.h
 * Date: Feb 20, 2020
 * Author: Maryam
 * Version : 1
 * Description : The prototypes of the DIO module in Autosar
 */

#ifndef DIO_H_
#define DIO_H_

/**************************************************************INCLUDES*********************************************************/
#include "Dio_Types.h"
#include "Dio_Cfg.h"
/**************************************************************CONSTANTS********************************************************/
#define PERIPHERAL_BASE_ADDR 0x40000000
#define PERIPHERAL_ALIAS_BASE_ADDR 0x42000000

/********************************************************PRIMITIVE TYPES********************************************************/

/********************************************************EXTERN VARIABLES*******************************************************/
extern const Dio_ChannelGroupType ChannelGroupId;
/******************************************************************ENUMS*********************************************************/

/*******************************************************STRUCTS AND UNIONS*******************************************************/

/*****************************************************FUNCTION-LIKE-MACROS*******************************************************/

/*********************************************************FUNCTION PROTOTYPES*****************************************************/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr );
void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );
Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId );
void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );
#endif /* DIO_H_ */
