/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "Std_Types.h"
#include "Bit_Math.h"

/*TODO include processor.h*/
#include "processor.h"

#include "nvic_cfg.h"
#include "mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"

/*Mapping the priority registers of the nvic*/
static const uint32 g_pui32Regs[] =
{
    NVIC_PRI0, NVIC_PRI1,NVIC_PRI2, NVIC_PRI3, NVIC_PRI4, NVIC_PRI5, NVIC_PRI6, NVIC_PRI7,
    NVIC_PRI8, NVIC_PRI9, NVIC_PRI10, NVIC_PRI11, NVIC_PRI12, NVIC_PRI13,
    NVIC_PRI14, NVIC_PRI15, NVIC_PRI16, NVIC_PRI17, NVIC_PRI18, NVIC_PRI19,
    NVIC_PRI20, NVIC_PRI21, NVIC_PRI22, NVIC_PRI23, NVIC_PRI24, NVIC_PRI25,
    NVIC_PRI26, NVIC_PRI27, NVIC_PRI28, NVIC_PRI29, NVIC_PRI30, NVIC_PRI31,
    NVIC_PRI32, NVIC_PRI33, NVIC_PRI34
};

/*Mapping the enable registers of the nvic*/
static const uint32 g_pui32EnRegs[] =
{
    NVIC_EN0, NVIC_EN1, NVIC_EN2, NVIC_EN3, NVIC_EN4
};

/*Mapping the disable registers of the nvic*/
static const uint32 g_pui32Dii16Regs[] =
{
    NVIC_DIS0, NVIC_DIS1, NVIC_DIS2, NVIC_DIS3, NVIC_DIS4
};

/*The configuration array*/
extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{
    uint8 NVIC_Counter;     /*Counter to loop on the interrupts*/
    uint8 NVIC_INT_NUM;     /*Number of the interrupt being processed in the for loop*/
    uint32 NVIC_Priority_Division = NVIC_APINT_XXY;  /*How group and sub group priorities are divided*/

    /*TODO : switch to privilege mode - use switch function in processor.h*/

    /*APINT*/
    /*Choosing the group-subGroup combination of the processor*/
    NVIC_APINT |= NVIC_APINT_VECTKEY|NVIC_APINT_XXY;

    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */
    for(NVIC_Counter = 0; NVIC_Counter<NVIC_NUM_OF_ENABLED_INT; NVIC_Counter++)
    {
        uint32 u32_Temp;
        uint8 u8_Priority = 0;

        NVIC_INT_NUM = NVIC_CfgArr[NVIC_Counter].Int_Num;

        /*Generating the 3 bits of the priority for each interrupt*/
        switch(NVIC_Priority_Division)
        {
            case NVIC_APINT_XXX :
                u8_Priority = NVIC_CfgArr[NVIC_Counter].Group_Priority;
                break;
            case NVIC_APINT_XXY :
                u8_Priority = (NVIC_CfgArr[NVIC_Counter].Group_Priority<<1)|(NVIC_CfgArr[NVIC_Counter].Sub_Group_Priority);
                break;
            case NVIC_APINT_XYY :
                u8_Priority = (NVIC_CfgArr[NVIC_Counter].Group_Priority<<2)|(NVIC_CfgArr[NVIC_Counter].Sub_Group_Priority);
                break;
            case NVIC_APINT_YYY :
                u8_Priority = NVIC_CfgArr[NVIC_Counter].Sub_Group_Priority;
                break;
        }

        /*Setting the priority*/

        u32_Temp = (*((volatile uint32 *)(g_pui32Regs[NVIC_INT_NUM >> 2])));
        u32_Temp &= ~(0xFF << (8 * (NVIC_INT_NUM & 3)));
        u32_Temp |= u8_Priority << (8 * (NVIC_INT_NUM & 3));
        (*((volatile uint32 *)(g_pui32Regs[NVIC_INT_NUM >> 2]))) = u32_Temp;

        /*Enabling or Disabling the interrupt based on the configuration array*/

        switch(NVIC_CfgArr[NVIC_Counter].Int_EN_State)
        {
            case ENABLE :
                (*((volatile uint32 *)(g_pui32EnRegs[(NVIC_INT_NUM - 16) / 32]))) = ( 1 << ((NVIC_INT_NUM - 16) & 31) );
                break;
            case DISABLE :
                (*((volatile uint32 *)(g_pui32Dii16Regs[(NVIC_INT_NUM - 16) / 32]))) = ( 1 << ((NVIC_INT_NUM - 16) & 31) );
                break;
        }

    }


    /*TODO : return to non-privilege mode */

}



