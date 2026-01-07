#include "BMI160.h"

uint8_t data;
 uint8_t Acc_Val[6];

void bmi_read_address (uint8_t reg)
{
	 I2C1_byteRead( DEVICE_ADDR, reg, &data);

}

void bmi_write (uint8_t reg, char value)
{
	char data[1];
	data[0] = value;

	I2C1_burstWrite( DEVICE_ADDR, reg,1, data) ;
}

void bmi_read_values (uint8_t reg)
{
	I2C1_burstRead(DEVICE_ADDR, reg, 6,(char *)Acc_Val);

}


void bmi_init (void)
{

	I2C1_init();

	/*Read the CHIP_ID, this should return 0xD1*/
	bmi_read_address(CHIP_ID);

	/*power mode control register to enable the acc*/
	bmi_write (CMD_R, CMD_CODE);

	/*To set the freq and bandwidth */
	bmi_write (ACC_CONF_R,ACC_CONF_VALUE);

	/*Set data format range to +-8g*/
	bmi_write (ACC_RANGE_R, EIGHT_G);

	bmi_write(INT_EN_R, INT_EN_VALUE);

	bmi_write(INT_MAP_R, INT_MAP_VALUE);






}

