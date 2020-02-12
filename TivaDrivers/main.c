
#include "dio.h"
#include "port.h"
#include "SysCtr.h"
#include "dio_types.h"
#include "processor.h"

int main(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
        SysCtr_init();
        PORT_init();
        /*Led On*/
        Dio_WritePort(Dio_Port_F, 0x0E);
        return 0;
}
