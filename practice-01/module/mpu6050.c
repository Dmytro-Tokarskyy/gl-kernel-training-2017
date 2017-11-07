#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


// 1. Declare device ids supported by the driver. You can do that using
//    i2c_device_id. If DT is supported, use of_device_id too.

/*
 	mpu6050: mpu6050@68 {
		compatible = "mpu6050";
		reg = <0x68>;
	}
 */

/*! Device ID
 *  Uses in 'i2c_driver.id_table
 */
static const struct i2c_device_id mpu650_id[] = {
		{"mpu650", 0}
	};

/*!
 *  Make matching with Device Tree.
 *  Uses in 'i2c_driver.driver.of_match_table'
*/
static const struct of_device_id mpu6050_match[] = {
		{.compatible = "mpu6050"}
};


// 2. Call MODULE_DEVICE_TABLE(i2c, my_id_table to register your device list
//    with the I2C core. If device tree is supported, you must call
//    MODULE_DEVICE_TABLE(of, your_of_match_table) to register your device list
//    with the OF core.

MODULE_DEVICE_TABLE(i2c, mpu6050_match); // MODULE_DEVICE_TABLE(i2c, mpu650_id)


// 3. Write the probe and remove functions according to their respective
//    prototypes. If needed, write power management functions too. The probe
//    function must identify your device, configure it, define per-device
//    (private) data, and register with the appropriate kernel framework. The
//    driver's behavior depends on what you have done in the probe function.
//    The remove function must undo everything you have done in the probe
//    function (free memory and unregister from any framework).





static int __init hellowolrd_init(void) {
    pr_info("Hello world!\n");
    return 0;
}

static void __exit hellowolrd_exit(void) {
    pr_info("End of the world\n");
}

module_init(hellowolrd_init);
module_exit(hellowolrd_exit);

MODULE_AUTHOR("Dmytro Tokarskyy <dmytro.tokarskyy@globallogic.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MPU 6050 I2C Driver");
