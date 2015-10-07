/*
 * LM94022_temperature_sensor.h
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */

#ifndef LM94022_TEMPERATURE_SENSOR_H_
#define LM94022_TEMPERATURE_SENSOR_H_
/* El cálculo de la tempratura esta linealizado para todas las ganancias en el rango de temperaturas
 * de -20ºC a 75ºC.*/

#include <stdint.h>

#define GS_PORT GPIO_PORT_P2
#define GS0		GPIO_PIN0
#define GS1		GPIO_PIN1

#define VREF	 	1500
#define RESOLUTION 	1024
#define	LSB 		VREF/RESOLUTION

/* Aquí se definen los valores posibles de tensión de alimentación del sensor para
 * determinar la ganancia y optimizar las prestaciones del mismo.
 * Estos són los valores mínimos para un rango de -20ºC a 75ºC.*/
#define VCC_SENSOR_1V5	0
#define VCC_SENSOR_2V3	1
#define VCC_SENSOR_3V0	2
#define VCC_SENSOR_3V6	3

/* Dentro del rango de operación seleccionado se procede la linealización de las salidas.
 * Este proceso debe realizarse cuatro veces, una por ganancia. Le ecuacion de salida queda
 *  de la siguiente forma: T = (V-K1)/K2-20. */
#define K1_1V5	1141
#define K1_2V3	1727
#define K1_3V0	2313
#define K1_3V6	2899

#define K2_1V5	(619-1141)/(75+20)
#define K2_2V3	(949-1727)/(75+20)
#define K2_3V0	(1279-2313)/(75+20)
#define K2_3V6	(1609-2899)/(75+20)

uint16_t measureLM94022Temp (void);
void gainSelectorLM94022(uint8_t gain);
float calculateLM94022Temp (int16_t temperatureBytes, uint8_t gain);


#endif /* LM94022_TEMPERATURE_SENSOR_H_ */
