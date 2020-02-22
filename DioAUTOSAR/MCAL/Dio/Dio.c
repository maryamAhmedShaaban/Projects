/*
 * Dio.c
 *
 *  Created on: Feb 21, 2020
 *      Author: TOSHIBA.SXO11
 */
/************************************************************INCLUDES*********************************************************/
#include "Dio.h"
#include "mcu_hw.h"

/************************************************************CONSTANTS*********************************************************/


/***********************************************************LOCAL MACROS*******************************************************/
/*Macro Like Function to add the offset to the base and dereference the resulting address*/
#define MEM_REG(BASE_ADDR, OFFSET) *((volatile uint32*)(BASE_ADDR + OFFSET))
/*Getting the base offset*/
#define REG_OFFSET(BASE_ADDR, OFFSET) ((BASE_ADDR) + (OFFSET) - PERIPHERAL_BASE_ADDR)
/*Macro to get the bit address in the bit band*/
#define BIT_BAND(REG_OFFSET,BIT_NO,ALIAS_BASE) (ALIAS_BASE) + ((REG_OFFSET)*32) + ((BIT_NO) * 4)
/*Macro to cast the bit band address from number to address*/
#define BIT_BAND_ADDRESS(ALIAS_ADDRESS) *((volatile uint32*)(ALIAS_ADDRESS))
/*Macro to get offset of bit masking for the given channel group*/
#define GROUP_OFFSET(GROUP_MASK,GROUP_OFFSET) (((GROUP_MASK)<<(GROUP_OFFSET)) * 4)
/*Macro to get offset of a given mask*/
#define MASK_OFFSET(MASK) ((MASK) * 4)

/****************************************************STATIC GLOBAL VARIABLES**************************************************/
/*Base addresses of GPIO Registers*/

static uint32 BaseAddrArr[6] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};

/*******************************************************GLOBAL VARIABLES*******************************************************/


/********************************************************APIS IMPLEMENTATION****************************************************/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
    Dio_LevelType u8_DioChannelRet;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the level value of given Channel */
    u8_DioChannelRet = (MEM_REG(BaseAddrArr[PortId],GPIODATA) & ChannelPos);
    return u8_DioChannelRet;
}
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    uint32 Base_Offset = REG_OFFSET(BaseAddrArr[PortId],GPIODATA);

    /*TODO: Write the input value in the corresponding ChannelId */
    BIT_BAND_ADDRESS(BIT_BAND(Base_Offset,ChannelPos,PERIPHERAL_ALIAS_BASE_ADDR)) = Level;
}
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )
{
    Dio_PortLevelType u8_DioPortRet;
    u8_DioPortRet = (uint8)(MEM_REG(BaseAddrArr[PortId],GPIODATA) & (0x000000FF));

    /*TODO: Return the Port Value*/

    return u8_DioPortRet;
}
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{
    MEM_REG(BaseAddrArr[5],GPIODATA) = Level;
}
Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    Dio_PortLevelType u8_DioGroupLevel;
    uint16 Offset_ReadValue = GROUP_OFFSET(ChannelGroupIdPtr->mask,ChannelGroupIdPtr->offset);
    /*To get the value in the channel group itself*/
    u8_DioGroupLevel = MEM_REG(BaseAddrArr[ChannelGroupIdPtr->port],Offset_ReadValue) >> ChannelGroupIdPtr->offset;
    return u8_DioGroupLevel;
}
void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
    uint16 Offset_Value = GROUP_OFFSET(ChannelGroupIdPtr->mask,ChannelGroupIdPtr->offset);
    /*Shift the level by the offset to get the value to put in the channel group*/
    MEM_REG(BaseAddrArr[ChannelGroupIdPtr->port], Offset_Value) = (Level<<ChannelGroupIdPtr->offset);
}
Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId )
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    Dio_LevelType u8_DioFlipRet;
    uint32 Base_Offset = REG_OFFSET(BaseAddrArr[PortId],GPIODATA);
    uint32 u32_DioBitLevel = BIT_BAND_ADDRESS(BIT_BAND(Base_Offset,ChannelPos,PERIPHERAL_ALIAS_BASE_ADDR));

    /*TODO: Write the input value in the corresponding ChannelId */
    BIT_BAND_ADDRESS(BIT_BAND(Base_Offset,ChannelPos,PERIPHERAL_ALIAS_BASE_ADDR)) = u32_DioBitLevel ^ 0x00000001;

    u8_DioFlipRet = BIT_BAND_ADDRESS(BIT_BAND(Base_Offset,ChannelPos,PERIPHERAL_ALIAS_BASE_ADDR));
    return u8_DioFlipRet;
}
void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask )
{
    MEM_REG(BaseAddrArr[PortId], MASK_OFFSET(Mask)) = Level;
}
