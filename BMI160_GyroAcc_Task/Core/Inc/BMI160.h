

#ifndef BMI160_H_
#define BMI160_H_
#include "I2C.h"
#include <stdint.h>

#define   CHIP_ID					(0x00)
#define   DATA_START_ADDR			(0x12)
#define   ACC_CONF_R                (0x40)
#define   ACC_RANGE_R   			(0x41)
#define   INT_EN_R                  (0x50)
#define   INT_MAP_R                 (0x56)
#define   DEVICE_ADDR    			(0x69)
#define   I2C_CTRL_R                (0x6B)
#define   CMD_R                     (0x7E)




/*
 * Selection of acc g-range
 * 0b0011 - 2g
 * 0b0101 - 4g
 * 0b1000 - 8g
 */
#define		EIGHT_G					(0x08)

#define		RESET_F					(0x00)

//set ord and bwp bit
#define     ACC_CONF_VALUE          (0x05)
//Set PMU mode of acc to normal
#define     CMD_CODE                (0x11)
#define     INT_EN_VALUE            (0x01)
#define     INT_MAP_VALUE           (0x01)




void bmi_init (void);
void bmi_read_values (uint8_t reg);

#endif /* BMI160_H_ */
