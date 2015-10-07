/*
 * MCP9700A_temp_sensor.c
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */


#include "MCP9700A_temp_sensor.h"
#include <driverlib/MSP430FR57xx/adc10_b.h>

uint16_t measureMCP9700aTemp (void){
	uint16_t temperature;
	ADC10_B_configureMemory(ADC10_B_BASE,ADC10_B_INPUT_A1,ADC10_B_VREFPOS_INT,ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion(ADC10_B_BASE,ADC10_B_SINGLECHANNEL);
	while(ADC10_B_isBusy(ADC10_B_BASE)==ADC10_B_BUSY);
	temperature = ADC10_B_getResults(ADC10_B_BASE);
	return temperature;
}

float calculateMCP9700aTemp (uint16_t temperatureBytes){
	uint16_t 	temperatureVolts;
	float 		temperature;

	temperatureVolts = LSB * temperatureBytes;
	temperature = temperatureVolts * 1000 * (1/MCP9700A_SENSITIVITY) - 50;

	return temperature;
}
