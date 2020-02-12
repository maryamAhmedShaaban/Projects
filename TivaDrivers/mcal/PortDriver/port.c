
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

/*Macro Like Function to add the offset to the base and dereference the resulting address*/
#define MEM_REG(BASE_ADDR, OFFSET) *((volatile uint32*)(BASE_ADDR + OFFSET))

#include "Std_Types.h"
#include "Bit_Math.h"
#include "port_cfg.h"
#include "mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

/*Base Addresses of Ports*/
static uint32 BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};

/*Mapping for the offsets of the Current Drive Registers*/
static uint32 CurrentDriveOffset[] = {GPIODR2R, GPIODR4R, GPIODR8R};

/*Mapping for the offsets of Attached Resistor*/
static uint32 InternalAttachOffset[] = {GPIOODR, GPIOPUR, GPIOPDR};

void PORT_init(void)
{
    uint8 CfgArrIndex;
 //   uint8 PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
//    uint32 BaseAddr;

    /*Configuring Port F*/
    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;
        if(ChannelId >= Port_Channel_F0)
        {
            /*get PORTId using ChannelId*/
            /*PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;*/

            /*get baseAddress using PortId*/
          /*  BaseAddr = BaseAddrArr[PortId];*/

            /*get Channel Position in PortGroup using ChannelId */
            ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;

            /*NOTE use channel position in Group to write in corresponding bit in Desired Register */

            /*Enable the Pin*/
            SET_BIT(MEM_REG(BaseAddrArr[5],GPIODEN), ChannelPosInPort);

            /*TODO: set channel direction */

            if(port_Dir_Output == PortCfgArr[CfgArrIndex].Dir)
            {
                SET_BIT(MEM_REG(BaseAddrArr[5],GPIODIR), ChannelPosInPort);
            }
            else
            {
                CLR_BIT(MEM_REG(BaseAddrArr[5],GPIODIR), ChannelPosInPort);
            }


            /*TODO: set channel mode */
            if(PORT_MODE_PIN_X_DIO == PortCfgArr[CfgArrIndex].Mode)
            {
                /*Enable GPIO function*/
                CLR_BIT(MEM_REG(BaseAddrArr[5],GPIOAFSEL), ChannelPosInPort);
            }

            /*TODO: set Interrupt configuration */
            if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
            {
                CLR_BIT(MEM_REG(BaseAddrArr[5],GPIOIM), ChannelPosInPort);
            }
            else
            {
                SET_BIT(MEM_REG(BaseAddrArr[5],GPIOIM), ChannelPosInPort);
            }

            /*TODO: set Internal Attachment configuration */
            if(Port_InternalAttach_NA != PortCfgArr[CfgArrIndex].AttachedRes)
            {
                SET_BIT(MEM_REG(BaseAddrArr[5],InternalAttachOffset[ (PortCfgArr[CfgArrIndex].AttachedRes)-1 ]), ChannelPosInPort);
            }


            /*TODO: set current strength configuration */
            SET_BIT(MEM_REG(BaseAddrArr[5],CurrentDriveOffset[PortCfgArr[CfgArrIndex].CurrentDrive]), ChannelPosInPort);

            /*Check if analog functionality is required*/
            if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
            {
                /*TODO: enable digital and disable ADC  */


            }
            else
            {
                /*TODO: disable digital and enable ADC */

            }

        }
    }
}

