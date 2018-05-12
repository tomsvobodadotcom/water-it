/**
 * @brief: Water-it: Software for automated flower watering
 * @file: config.h
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Static scheduling configuration */
#define SSCHED_START_H 20
#define SSCHED_START_M 0
#define SSCHED_START_S 0
#define SSCHED_DURATION_MS 20 * 1000 // 20sec

/* Output config */
#define PIN_MOTOR Gpio::Pin(Gpio::RpiZeroPin::GPIO17)

/* Main loop variables */
#define LOOP_SLEEP_SEC 60*10 // 10 minutes

#endif /* CONFIG_H */
