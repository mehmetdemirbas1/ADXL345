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


ADXL345_ReadStatus_t ADXL345_ReadRegister(uint16_t registerAddr, uint16_t sizeOfData, uint8_t *pdata)
{
	if(HAL_I2C_Mem_Read(&hi2c1, ADXL345_DEVICE_ADDR, registerAddr, 1, pdata, sizeOfData, TIMEOUT)==HAL_OK){
		return READ_OK;
	}
	return READ_FAIL;
}

ADXL345_WriteStatus_t ADXL345_WriteRegister(uint16_t registerAddr, uint16_t Value)
{
	uint8_t data[2]={0};
	data[0] = registerAddr;
	data[1] = Value;

	if(HAL_I2C_Master_Transmit(&hi2c1, ADXL345_DEVICE_ADDR, data, sizeof(data), TIMEOUT)== HAL_OK)
		return WRITE_OK;

	return WRITE_FAIL;
}

ADXL345_InitStatus_t ADXL345_Init(void)
{
	uint8_t deviceId = 0;
	ADXL345_ReadRegister(DEVID, sizeof(uint8_t),&deviceId);
	if(0xE5 != deviceId)
		return INIT_FAIL;

	uint8_t temp = 0;
	ADXL345_PowerControlRegister_t powerControl = {0};

	powerControl.wakeUp=WAKEUP_8HZ;
	powerControl.sleep= MODE_OFF;
	powerControl.mesaureBit = MODE_ON;
	powerControl.autoSleep = MODE_OFF;
	powerControl.linkBit = MODE_OFF;

	temp = *((uint8_t*)&powerControl);

	ADXL345_WriteRegister(POWER_CTL, temp);

	return INIT_OK;
}











