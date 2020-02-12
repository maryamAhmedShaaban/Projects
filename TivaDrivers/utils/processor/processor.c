/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "processor.h"

PROCESSOR_ModeType gu8_PROCESSOR_Mode;

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    /* TODO use Svc assembly instruction to switch to handler mode*/

    gu8_PROCESSOR_Mode = Mode;
    __asm(" SVC #0x01\n");

}

/*TODO: Put the following function address in Vector table */

void PROCESSOR_SvcHandler(void)
{
    /*TODO use TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes.See page(88) */
    switch(gu8_PROCESSOR_Mode)
    {
        case PROCESSOR_ModePrivilege:
            __asm(" MOV R0, #0x00\n");
            __asm(" MSR CONTROL, R0\n");
            break;
        case PROCESSOR_ModeNonPrivilege:
            __asm(" MOV R0, #0x01 \n"
                    " MSR CONTROL, R0\n");
            break;
    }

}

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
