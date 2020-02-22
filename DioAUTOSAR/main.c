

/**
 * main.c
 */

#include "dio.h"
#include "port.h"
#include "SysCtr.h"

int main(void)
{

    SysCtr_init();
    PORT_init();
    Dio_WritePort(DIO_PORT_F, 0x06);

    return 0;
}
