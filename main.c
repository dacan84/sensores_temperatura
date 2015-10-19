#include <msp430.h> 
#include <ti/mcu/msp430/Grace.h>
#include <driverlib/MSP430FR57xx/driverlib.h>
#include <driverlib/MSP430FR57xx/inc/hw_memmap.h>
#include "TMP112_I2C_temperature_sensor.h"

/*
 * main.c
 */
int main(void) {

	Grace_init();
	configTMP112();
	while(1){
		measureTMP112();
	}

}


