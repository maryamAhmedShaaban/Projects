/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "mcu_hw.h"
#include "STD_types.h"
#include "Bit_Math.h"

/*TODO include SysCtr_cfg.h*/
#include "SysCtr_cfg.h"
#include "SysCtr_types.h"
#include "SysCtr.h"

/*The required clock source*/
const uint8 SYS_CLK_Source =  SYS_CLK_MOSC;

static const gstr_SysClkCfg_Type str_SysClkCfg = {MOSC, FREQ_16};


static const uint32 SysClkSource_Arr[] = {SYS_CLK_MOSC,SYS_CLK_PIOSC,
                                         SYS_CLK_PIOSC_DIV_4,SYS_CLK_LFIOSC};

static const uint32 SysClkFreq_Arr[] = {SYS_FREQ_4, SYS_FREQ_8, SYS_FREQ_16};

void SysCtr_init(void)
{
    /*TODO Enable configured Peripherals CLock gates*/
    /*Enabling Port F*/
    SYSCTL_RCGCGPIO |= 0x00000020;

    /*TODO Set System CLock Source as configured*/


    switch(SysClkSource_Arr[str_SysClkCfg.u8_ClkSource])
    {
        case SYS_CLK_MOSC:
            /*For main clock source, Clear bits 4 and 5*/
            SYSCTL_RCC2 &= ~0x00000070;
            break;
        default:
            /*Otherwise, Set the bits according to the required source*/
            SYSCTL_RCC2 |= SysClkSource_Arr[str_SysClkCfg.u8_ClkSource];
            break;
    }

    /*TODO set CLock Frequency as configured -
     * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.
     * */

    /*RCC2 register override*/
    SYSCTL_RCC2 |= 0x80000000;
    SYSCTL_RCC2 |= 0x00000800;      /*Bypass PLL*/

    /*Activate PLL*/
    SYSCTL_RCC2 &= ~0x00002000;
    /*Use 400MHz*/
    SYSCTL_RCC2 |= 0x40000000;

    SYSCTL_RCC = (SYSCTL_RCC & ~0x000007C0) + SysClkFreq_Arr[str_SysClkCfg.u8_ClkFreq];

}

uint32 SysCtr_getSysClockFreq(void)
{
    uint32 ret;
    /*TODO return the current system clock frequency */
    switch(SysClkFreq_Arr[str_SysClkCfg.u8_ClkFreq])
    {
        case FREQ_4 :
            ret = (uint32)4;
            break;
        case FREQ_8 :
            ret = (uint32)8;
            break;
        case FREQ_16 :
            ret = (uint32)16;
            break;
    }
    return ret;
}

