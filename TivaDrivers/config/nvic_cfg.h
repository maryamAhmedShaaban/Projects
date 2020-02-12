/*
 * nvic_cfg.h
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#ifndef E15_ARM_REPO_CONFIG_NVIC_CFG_H_
#define E15_ARM_REPO_CONFIG_NVIC_CFG_H_

#include "../utils/Std_Types.h"

/*TODO Configure Number of Enabled Interrupts*/
#define NVIC_NUM_OF_ENABLED_INT                     5

/*Mine*/
/*Registers of NVIC*/
#define NVIC_INT_CTRL           (*((volatile uint32 *)(0xE000ED04)))  /* Interrupt Control and State */
#define NVIC_VTABLE             (*((volatile uint32 *)(0xE000ED08)))  /* Vector Table Offset */
#define NVIC_APINT              (*((volatile uint32 *)(0xE000ED0C)))  /* Application Interrupt and Reset Control */

#define NVIC_EN0                0xE000E100  /* Interrupt 0-31 Set Enable*/
#define NVIC_EN1                0xE000E104  /* Interrupt 32-63 Set Enable*/
#define NVIC_EN2                0xE000E108  /* Interrupt 64-95 Set Enable*/
#define NVIC_EN3                0xE000E10C  /* Interrupt 96-127 Set Enable*/
#define NVIC_EN4                0xE000E110  /* Interrupt 128-159 Set Enable*/

#define NVIC_DIS0               0xE000E180  /* Interrupt 0-31 Clear Enable*/
#define NVIC_DIS1               0xE000E184  /* Interrupt 32-63 Clear Enable*/
#define NVIC_DIS2               0xE000E188  /* Interrupt 64-95 Clear Enable*/
#define NVIC_DIS3               0xE000E18C  /* Interrupt 96-127 Clear Enable*/
#define NVIC_DIS4               0xE000E190  /* Interrupt 128-159 Clear Enable*/

#define NVIC_PRI0               0xE000E400  // Interrupt 0-3 Priority
#define NVIC_PRI1               0xE000E404  // Interrupt 4-7 Priority
#define NVIC_PRI2               0xE000E408  // Interrupt 8-11 Priority
#define NVIC_PRI3               0xE000E40C  // Interrupt 12-15 Priority
#define NVIC_PRI4               0xE000E410  // Interrupt 16-19 Priority
#define NVIC_PRI5               0xE000E414  // Interrupt 20-23 Priority
#define NVIC_PRI6               0xE000E418  // Interrupt 24-27 Priority
#define NVIC_PRI7               0xE000E41C  // Interrupt 28-31 Priority
#define NVIC_PRI8               0xE000E420  // Interrupt 32-35 Priority
#define NVIC_PRI9               0xE000E424  // Interrupt 36-39 Priority
#define NVIC_PRI10              0xE000E428  // Interrupt 40-43 Priority
#define NVIC_PRI11              0xE000E42C  // Interrupt 44-47 Priority
#define NVIC_PRI12              0xE000E430  // Interrupt 48-51 Priority
#define NVIC_PRI13              0xE000E434  // Interrupt 52-55 Priority
#define NVIC_PRI14              0xE000E438  // Interrupt 56-59 Priority
#define NVIC_PRI15              0xE000E43C  // Interrupt 60-63 Priority
#define NVIC_PRI16              0xE000E440  // Interrupt 64-67 Priority
#define NVIC_PRI17              0xE000E444  // Interrupt 68-71 Priority
#define NVIC_PRI18              0xE000E448  // Interrupt 72-75 Priority
#define NVIC_PRI19              0xE000E44C  // Interrupt 76-79 Priority
#define NVIC_PRI20              0xE000E450  // Interrupt 80-83 Priority
#define NVIC_PRI21              0xE000E454  // Interrupt 84-87 Priority
#define NVIC_PRI22              0xE000E458  // Interrupt 88-91 Priority
#define NVIC_PRI23              0xE000E45C  // Interrupt 92-95 Priority
#define NVIC_PRI24              0xE000E460  // Interrupt 96-99 Priority
#define NVIC_PRI25              0xE000E464  // Interrupt 100-103 Priority
#define NVIC_PRI26              0xE000E468  // Interrupt 104-107 Priority
#define NVIC_PRI27              0xE000E46C  // Interrupt 108-111 Priority
#define NVIC_PRI28              0xE000E470  // Interrupt 112-115 Priority
#define NVIC_PRI29              0xE000E474  // Interrupt 116-119 Priority
#define NVIC_PRI30              0xE000E478  // Interrupt 120-123 Priority
#define NVIC_PRI31              0xE000E47C  // Interrupt 124-127 Priority
#define NVIC_PRI32              0xE000E480  // Interrupt 128-131 Priority
#define NVIC_PRI33              0xE000E484  // Interrupt 132-135 Priority
#define NVIC_PRI34              0xE000E488  // Interrupt 136-139 Priority


/*APINT Register Values*/
#define NVIC_APINT_VECTKEY      0x05FA0000  /* Vector key */
#define NVIC_APINT_XXX          0x00000400  /*8 Priority Groups and 1 Sub group*/
#define NVIC_APINT_XXY          0x00000500  /*4 Priority Groups and 2 Sub groups*/
#define NVIC_APINT_XYY          0x00000600  /*2 Priority Groups and 4 Sub groups*/
#define NVIC_APINT_YYY          0x00000700  /*1 Priority Group and 8 Sub groups*/



#define INT_GPIOA_TM4C123       0          // GPIO Port A
#define INT_GPIOB_TM4C123       1          // GPIO Port B
#define INT_GPIOC_TM4C123       2          // GPIO Port C
#define INT_GPIOD_TM4C123       3          // GPIO Port D
#define INT_GPIOE_TM4C123       4          // GPIO Port E
#define INT_UART0_TM4C123       5          // UART0
#define INT_UART1_TM4C123       6          // UART1
#define INT_SSI0_TM4C123        7          // SSI0
#define INT_I2C0_TM4C123        8          // I2C0
#define INT_PWM0_FAULT_TM4C123  9          // PWM0 Fault
#define INT_PWM0_0_TM4C123      10          // PWM0 Generator 0
#define INT_PWM0_1_TM4C123      11          // PWM0 Generator 1
#define INT_PWM0_2_TM4C123      12          // PWM0 Generator 2
#define INT_QEI0_TM4C123        13          // QEI0
#define INT_ADC0SS0_TM4C123     14          // ADC0 Sequence 0
#define INT_ADC0SS1_TM4C123     15          // ADC0 Sequence 1
#define INT_ADC0SS2_TM4C123     16          // ADC0 Sequence 2
#define INT_ADC0SS3_TM4C123     17          // ADC0 Sequence 3
#define INT_WATCHDOG_TM4C123    18          // Watchdog Timers 0 and 1
#define INT_TIMER0A_TM4C123     19          // 16/32-Bit Timer 0A
#define INT_TIMER0B_TM4C123     20          // 16/32-Bit Timer 0B
#define INT_TIMER1A_TM4C123     21          // 16/32-Bit Timer 1A
#define INT_TIMER1B_TM4C123     22          // 16/32-Bit Timer 1B
#define INT_TIMER2A_TM4C123     23          // 16/32-Bit Timer 2A
#define INT_TIMER2B_TM4C123     24          // 16/32-Bit Timer 2B
#define INT_COMP0_TM4C123       25          // Analog Comparator 0
#define INT_COMP1_TM4C123       26          // Analog Comparator 1
#define INT_COMP2_TM4C123       27          // Analog Comparator 2
#define INT_SYSCTL_TM4C123      28          // System Control
#define INT_FLASH_TM4C123       29          // Flash Memory Control and EEPROM



#endif /* E15_ARM_REPO_CONFIG_NVIC_CFG_H_ */
