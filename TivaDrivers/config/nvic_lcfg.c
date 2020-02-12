/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"



const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]={

   /*TODO Configure each Enabled Interrupt */
   {INT_GPIOA_TM4C123, 2, 0, ENABLE},
   {INT_GPIOB_TM4C123, 0, 1, ENABLE},
   {INT_GPIOC_TM4C123, 3, 0, ENABLE},
   {INT_GPIOD_TM4C123, 1, 1, ENABLE},
   {INT_GPIOE_TM4C123, 1, 0, ENABLE}

};
