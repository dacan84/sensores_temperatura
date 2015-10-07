/*
 * TMP112_I2C_temperature_sensor.c
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */
#include "TMP112_I2C_temperature_sensor.h"
// Esta funcion no va a valer para nada es para generar una ISR si se excede una determinada temperature

bool temperatureStatus (void){
	if (GPIO_INPUT_PIN_HIGH==GPIO_getInputPinValue(ALERT_PORT,ALERT_PIN)){
		return true;
	} else {
		return false;
	}
}

void configTMP112(void){

	EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE,TMP112_SLV_ADDR0);

	EUSCI_B_I2C_enable(EUSCI_B0_BASE);

	EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE,TMP112_CONFIG_ADDR);
	EUSCI_B_I2C_masterReceiveStart(EUSCI_B0_BASE);
	EUSCI_B_I2C_masterSendMultiByteNext(EUSCI_B0_BASE,BYTE1_INIT_CFG);
	EUSCI_B_I2C_masterSendMultiByteFinish(EUSCI_B0_BASE,BYTE2_INIT_CFG);
	EUSCI_B_I2C_masterSendMultiByteStop(EUSCI_B0_BASE);

	EUSCI_B_I2C_disable(EUSCI_B0_BASE);

}

float measureTMP112(void){
		uint8_t byte1, byte2;


		EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE,TMP112_SLV_ADDR0);

		EUSCI_B_I2C_enable(EUSCI_B0_BASE);

		EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE,TMP112_CONFIG_ADDR);
		EUSCI_B_I2C_masterSendMultiByteNext(EUSCI_B0_BASE,SHOOT_CONVERSION1);
		EUSCI_B_I2C_masterSendMultiByteFinish(EUSCI_B0_BASE,SHOOT_CONVERSION2);
		EUSCI_B_I2C_masterSendMultiByteStop(EUSCI_B0_BASE);

		EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE,TMP112_TEMPERATURE_ADDR);
		EUSCI_B_I2C_masterReceiveStart(EUSCI_B0_BASE);
		byte1 = EUSCI_B_I2C_masterReceiveMultiByteNext(EUSCI_B0_BASE);
		byte2 = EUSCI_B_I2C_masterReceiveMultiByteFinish(EUSCI_B0_BASE);
		EUSCI_B_I2C_masterSendMultiByteStop(EUSCI_B0_BASE);

		EUSCI_B_I2C_disable(EUSCI_B0_BASE);

}
