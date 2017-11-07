# MPU 6050 I2C Driver  

(MPU 6050 Datasheet)[https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf]


 - minimal driver template
 - minimal sysfs driver returns some string with read operation
 - minimal i2c driver
 
 
1. The starting trigger function for the driver->probe() callback is the module_init() macro called while loading the driver; this macro is defined in include/linux/module.h.
2. module_init(my_driver_init) has the callback to my_driver_init() function. my_driver_init() function should have a call to platform_driver_register(my_driver)
3. platform_driver_register(my_driver) assigns my_driver -> probe() handle to generic drv -> probe() and calls the driver_register(my_driver) function.
4. driver_register(my_driver) function adds my_driver to the platform bus and calls driver_attach() function.
5. In the same way, even the platform_device needs to attach to the platform bus.
6. Finally, only if the driver_match_device() returns success based on the .name & .id_table of the driver matches in the platform devices list that comes either from ACPI/DTS, then the driver_probe_device() gets called that has the drv->probe() callback.

https://www.quora.com/Linux-Kernel-How-do-the-probe-function-of-Device-Driver-gets-called

