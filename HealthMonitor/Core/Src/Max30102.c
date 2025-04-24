//#include "max30102.h"
//#include "stm32wbxx_hal.h"
//
//#define SLAVE_ADDR (0x57 << 1) // I2C address of the MAX30102 sensor
//
//// Resets the sensor by writing to the reset register
//int MAX30102_Reset(I2C_HandleTypeDef *i2c)
//{
//    uint8_t data[2] = {0x09, 0x40}; // Reset Register address and value
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, data, 2, 100); // Send reset command to the sensor
//    return 0;
//}
//
//// Sets the mode of the sensor by writing to the mode register
//int MAX30102_Set_Mode(I2C_HandleTypeDef *i2c, int mode) {
//    uint8_t mode_value;
//
//    switch (mode) {
//        case 0: mode_value = 0x02; break; // Heart Rate Mode
//        case 1: mode_value = 0x03; break; // SpO2 Mode
//        case 2: mode_value = 0x07; break; // Multi-LED Mode
//        default: return -1;                  // Invalid mode
//    }
//
//    // Write to MODE_CONFIG register (0x09)
//    uint8_t data[2] = {0x09, mode_value};
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, data, 2, 100);
//    return 0;
//}
//
//// Sets the LED current by writing to the LED current register
//// Ideal: 0x24
//int MAX30102_Set_RLED_Pulse_Amp(I2C_HandleTypeDef *i2c, uint8_t amplitude) {
//    uint8_t data[2] = {0x0C, amplitude}; // Pulse Amplitude Register address and value
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, data, 2, 100); // Send command to set pulse amplitude
//    return 0;
//}
//
//// Sets the IR LED current by writing to the LED current register
//// Ideal: 0x24
//int MAX30102_Set_IRLED_Pulse_Amp(I2C_HandleTypeDef *i2c, uint8_t amplitude) {
//    uint8_t data[2] = {0x0D, amplitude}; // Pulse Amplitude Register address and value
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, data, 2, 100); // Send command to set pulse amplitude
//    return 0;
//}
//
//// Sets the ADC Range, Sample Rate, and Pulse Width by writing to the SPO2 Config register
//// Ideal: 0x00 (2048nA) (ADC Range)
//// Ideal: 0x01 (100Hz) (Sample Rate)
//// Ideal: 0x01 (118uS) (Pulse Width)
//int MAX30102_Set_SPO2_Config(I2C_HandleTypeDef *i2c, uint8_t spo2_config) {
//    uint8_t data[2] = {0x0A, spo2_config}; // SPO2 Configuration Register address and value
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, data, 2, 100); // Send command to set SPO2 configuration
//    return 0;
//}
//
//// Sets the FIFO Average by writing to the FIFO Config register
//int MAX30102_Reset_FIFO(I2C_HandleTypeDef *i2c) {
//    uint8_t wr_ptr_data[2] = {0x04, 0x00};
//    uint8_t ovf_data[2] = {0x05, 0x00};
//    uint8_t rd_ptr_data[2] = {0x06, 0x00};
//
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, wr_ptr_data, 2, 100);
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, ovf_data, 2, 100);
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, rd_ptr_data, 2, 100);
//
//    return 0;
//}
//
//// Reads the FIFO data from the sensor
//// Returns the red LED data from the FIFO register
//uint32_t MAX30102_Read_FIFO(I2C_HandleTypeDef *i2c) {
//    uint8_t reg = 0x07;
//    uint8_t data[3];
//
//    HAL_I2C_Master_Transmit(i2c, SLAVE_ADDR, &reg, 1, 100);
//    HAL_I2C_Master_Receive(i2c, SLAVE_ADDR, data, 3, 100);
//
//    uint32_t red_led = ((data[0] << 16) | (data[1] << 8) | data[2]) & 0x03FFFF;
//
//    return red_led;
//}
