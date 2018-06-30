#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include "driver/i2c.h"

/**
 *    GPIO18 is assigned as the data signal of i2c master port
 *    GPIO19 is assigned as the clock signal of i2c master port
 *
 * Connection:
 * - connect sda/scl of sensor with GPIO18/GPIO19
 * - no need to add external pull-up resistors, driver will enable internal pull-up resistors.
 */

#define I2C_EXAMPLE_MASTER_SCL_IO          19               /*!< gpio number for I2C master clock */
#define I2C_EXAMPLE_MASTER_SDA_IO          18               /*!< gpio number for I2C master data  */
#define I2C_EXAMPLE_MASTER_NUM             I2C_NUM_1        /*!< I2C port number for master dev */
#define I2C_EXAMPLE_MASTER_TX_BUF_DISABLE  0                /*!< I2C master do not need buffer */
#define I2C_EXAMPLE_MASTER_RX_BUF_DISABLE  0                /*!< I2C master do not need buffer */
#define I2C_EXAMPLE_MASTER_FREQ_HZ         100000           /*!< I2C master clock frequency */

#define PCA9685_SENSOR_ADDR                0x23             /*!< slave address for i2c to PWM */

#define ACK_CHECK_EN                       0x1              /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS                      0x0              /*!< I2C master will not check ack from slave */
#define ACK_VAL                            0x0              /*!< I2C ack value */
#define NACK_VAL                           0x1              /*!< I2C nack value */


esp_err_t i2c_master_read_slave(i2c_port_t i2c_num, uint8_t* data_rd, size_t size);
esp_err_t i2c_master_write_slave(i2c_port_t i2c_num, uint8_t* data_wr, size_t size);
void i2c_master_init(void);

#endif
