/*
 * adxl345.c
 *
 *  Created on: Nov 30, 2025
 *      Author: Mehmet Demirbaş
 */

#include "adxl345.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t ADXL345_ScanDeviceAddr(void)
{
	for(uint8_t devAddr=0; devAddr<255;devAddr++){
		if(HAL_I2C_IsDeviceReady(&hi2c1, devAddr, 1, TIMEOUT)== HAL_OK)
			return devAddr;
	}
	return -1;
}

