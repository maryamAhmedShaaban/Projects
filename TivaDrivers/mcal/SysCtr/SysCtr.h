/*
 * SysCtr.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_
#define E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_

#include "../../utils/Std_Types.h"

#define SYSCTL_RCC             (*((volatile uint32 *)(0x400FE060)))  /* Run-Mode Clock Configuration*/
#define SYSCTL_RCC2             (*((volatile uint32 *)(0x400FE070)))  /* Run-Mode Clock Configuration 2*/

void SysCtr_init(void);
uint32 SysCtr_getSysClockFreq(void);



#endif /* E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_ */
