/*
 * LM94022_temperature_sensor.c
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */

#include "LM94022_temperature_sensor.h"
#include <driverlib/MSP430FR57xx/gpio.h>
#include <driverlib/MSP430FR57xx/adc10_b.h>

void gainSelectorLM94022(uint8_t gain) {
	/* Con esto podrí hacer una rutina q midiera VCC y A partir de esto
	 * seleccionar la ganancia. */

	switch (gain) {
	case VCC_SENSOR_1V5:
		GPIO_setOutputLowOnPin(GS_PORT,GS0);
		GPIO_setOutputLowOnPin(GS_PORT,GS1);
		break;
	case VCC_SENSOR_2V3:
		GPIO_setOutputHighOnPin(GS_PORT,GS0);
		GPIO_setOutputLowOnPin(GS_PORT,GS1);
		break;
	case VCC_SENSOR_3V0:
		GPIO_setOutputLowOnPin(GS_PORT,GS0);
		GPIO_setOutputHighOnPin(GS_PORT,GS1);
		break;
	case VCC_SENSOR_3V6:
		GPIO_setOutputHighOnPin(GS_PORT,GS0);
		GPIO_setOutputHighOnPin(GS_PORT,GS1);
		break;
	default:
		break;
	}
}

uint16_t measureLM94022Temp(void) {
	uint16_t temperature;
	ADC10_B_configureMemory(ADC10_B_BASE, ADC10_B_INPUT_A2, ADC10_B_VREFPOS_INT,
			ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion(ADC10_B_BASE, ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE) == ADC10_B_BUSY);
	temperature = ADC10_B_getResults(ADC10_B_BASE);
	return temperature;

}

/*Ojo con el cambio a int16_t por un posible cambio de signo en el float.
 * (quiza cambio de tipo no necesario)*/
float calculateLM94022Temp(int16_t temperatureBytes, uint8_t gain) {
	int16_t temperatureVolts;
	float temperature;

	switch (gain) {
	case VCC_SENSOR_1V5:
		temperatureVolts = LSB * temperatureBytes;
		temperature = (float)((temperatureVolts - K1_1V5)/K2_1V5) - 20;
		break;
	case VCC_SENSOR_2V3:
		temperatureVolts = LSB * temperatureBytes;
		temperature = ((temperatureVolts -K1_2V3)/K2_2V3)-20;
		break;
	case VCC_SENSOR_3V0:
		temperatureVolts = LSB * temperatureBytes;
		temperature = ((temperatureVolts -K1_3V0)/K2_3V0)-20;
		break;
	case VCC_SENSOR_3V6:
		temperatureVolts = LSB * temperatureBytes;
		temperature = ((temperatureVolts -K1_3V6)/K2_3V6)-20;
		break;
	default:
		break;
	}

	return temperature;
}
