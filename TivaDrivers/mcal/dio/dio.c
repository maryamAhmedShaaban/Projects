
/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */


#include "Bit_Math.h"
#include "STD_types.h"
/*TODO: include the header file that contains register definitions */
#include "mcu_hw.h"

#include "dio.h"


#define MAX_NUM_OF_PORTS            6

/*Macro Like Function to add the offset to the base and dereference the resulting address*/
#define MEM_REG(BASE_ADDR, OFFSET) *((volatile uint32*)(BASE_ADDR + OFFSET))


/*Base addresses of GPIO Registers*/

static uint32 BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};

/*The implementations of the functions are specific to Port F*/


Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    /*Dio_PortType PortId = ChannelId / 8;*/
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the level value of given Channel */
    ret = MEM_REG(BaseAddrArr[5],GPIODATA) & ChannelPos;
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    /*Dio_PortType PortId = ChannelId / 8;*/
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Write the input value in the corresponding ChannelId */
    if(STD_low == Level)
    {
        CLR_BIT(MEM_REG(BaseAddrArr[5],GPIODATA), ChannelPos);
    }
    else
    {
        SET_BIT(MEM_REG(BaseAddrArr[5],GPIODATA), ChannelPos);
    }

}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    ret = (uint8)(MEM_REG(BaseAddrArr[5],GPIODATA) & (0x000000FF));

    /*TODO: Return the Port Value*/

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*TODO: Write the input value in the corresponding PortId */
    MEM_REG(BaseAddrArr[5],GPIODATA) = value;

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* TODO: toggle the corresponding ChannelId */
    /*Dio_PortType PortId = ChannelId / 8;*/
    Dio_ChannelType ChannelPos = ChannelId % 8;

    TOGGLE_BIT(MEM_REG(BaseAddrArr[5],GPIODATA), ChannelPos);

}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */
    MEM_REG(BaseAddrArr[5],GPIODATA) = ((~(MEM_REG(BaseAddrArr[5],GPIODATA)))&(0x000000FF));
}



