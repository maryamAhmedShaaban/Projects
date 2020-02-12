/*
 * nvic_types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_

typedef struct
{
    /*TODO create types to contain Configuration parameters for each Interrupts
     * make sure the following parameters should be visible to static code
     * InterruptNum
     * ENable\Disable
     * Priority Group
     * Sub-priority Group
     * */

    uint8 Int_Num;
    uint8 Group_Priority;
    uint8 Sub_Group_Priority;
    Std_EnType Int_EN_State;

}NVIC_CfgType;



#endif /* TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_ */
