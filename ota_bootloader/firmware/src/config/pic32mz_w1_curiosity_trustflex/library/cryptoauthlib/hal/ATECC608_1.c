/*
 * Code generated from MPLAB Harmony.
 *
 * This file will be overwritten when reconfiguring your MPLAB Harmony project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */

#include "cryptoauthlib.h"



//ATCAIfaceCfg atecc608_1_init_data = {
//    .iface_type            = ATCA_I2C_IFACE,
//    .devtype               = ATECC608,
//    .atcai2c.address       = 0x6C,
//    .atcai2c.bus           = 0,
//    .atcai2c.baud          = 50000,
//    .wake_delay            = 1500,
//    .rx_retries            = 20,
//    .cfg_data              = &i2c1_plib_i2c_api
//};

ATCAIfaceCfg atecc608_1_init_data = {
    .iface_type            = ATCA_I2C_IFACE,
    .devtype               = ATECC608,
    .atcai2c.address       = 0x6A,
    .atcai2c.bus           = 0,
    .atcai2c.baud          = 1000,
    .wake_delay            = 1500,
    .rx_retries            = 21,
    .cfg_data              = &i2c2_plib_i2c_api
};
