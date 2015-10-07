/*
 * MCP9700A_temp_sensor.h
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */

#ifndef MCP9700A_TEMP_SENSOR_H_
#define MCP9700A_TEMP_SENSOR_H_

#include <stdint.h>

#define VREF	 	1500
#define RESOLUTION 	1024
#define	LSB 		VREF/RESOLUTION
#define MCP9700A_SENSITIVITY 10

uint16_t measureMCP9700aTemp (void);
float calculateMCP9700aTemp (uint16_t temperatureBytes);

#endif /* MCP9700A_TEMP_SENSOR_H_ */
