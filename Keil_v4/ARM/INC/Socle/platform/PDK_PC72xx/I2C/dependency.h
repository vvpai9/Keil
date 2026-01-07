#include <platform.h>
#include <irqs.h>

#ifndef SOCLE_APB0_I2C0
#ifdef SOCLE_APB0_I2C
#define SOCLE_APB0_I2C0 SOCLE_APB0_I2C
#else
#error "I2C IP base address is not defined"
#endif
#endif

#ifndef SOCLE_INTC_I2C0
#ifdef SOCLE_INTC_I2C
#define SOCLE_INTC_I2C0 SOCLE_INTC_I2C
#else
#error "I2C IRQ is not defined"
#endif
#endif

#if defined(CONFIG_PC7210) || defined(CONFIG_PC9002)
#define SOCLE_I2C_AT24C02B_EEPROM_TEST 0
#else
#define SOCLE_I2C_AT24C02B_EEPROM_TEST 1
#endif

