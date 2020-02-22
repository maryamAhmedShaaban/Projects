/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_


/*TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * */

/*Registers for enabling the clock of the peripherals*/
#define SYSCTL_RCGCGPIO         (*((volatile uint32 *)(0x400FE608)))



/*Clock Sources*/
#define SYS_CLK_MOSC            0x00000000
#define SYS_CLK_PIOSC           0x00000010
#define SYS_CLK_PIOSC_DIV_4     0x00000020
#define SYS_CLK_LFIOSC          0x00000030

/*Desired Clock Frequency*/
#define SYS_FREQ_4  0x00000180
#define SYS_FREQ_8  0x00000380
#define SYS_FREQ_16  0x00000540

#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
