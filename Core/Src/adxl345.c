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


ADXL345_RegisterStatus_t ADXL345_ReadRegister(uint16_t registerAddr, uint16_t sizeOfData, uint8_t *pdata)
{
	if(HAL_I2C_Mem_Read(&hi2c1, ADXL345_DEVICE_ADDR, registerAddr, 1, pdata, sizeOfData, TIMEOUT)==HAL_OK){
		return READ_SUCCESS;
	}
	return READ_FAIL;
}

ADXL345_InitStatus_t ADXL345_Init(void)
{
	uint8_t deviceId = 0;
	ADXL345_ReadRegister(DEVID, sizeof(uint8_t),&deviceId);
	if(0xE5 != deviceId)
		return INIT_FAIL;




	return INIT_OK;
}











