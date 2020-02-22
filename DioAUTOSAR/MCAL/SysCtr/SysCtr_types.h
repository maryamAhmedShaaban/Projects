/*
 * SysCtr_Types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_

typedef enum
{
    MOSC,
    PIOSC,
    PIOSC_DIV_4,
    LFIOSC
}genu_SysClkSource_Type;


typedef enum
{
    FREQ_4,
    FREQ_8,
    FREQ_16
}genu_SysFreq_Type;

typedef struct
{
    genu_SysClkSource_Type u8_ClkSource;
    genu_SysFreq_Type u8_ClkFreq;
}gstr_SysClkCfg_Type;



#endif /* TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_ */
