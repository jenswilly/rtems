/**
 * @file stm32h7-gpio.c
 *
 * @ingroup arm_stm32h7
 *
 * @brief GPIO Support for STM32H7 Nucleo Board.
 */

/**
 * Copyright (c) 2025 Jens Willy Johannsen <jens@jenswilly.dk>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

/* BSP specific function definitions for STM32H7 Nucleo Board.
 * This file is based on the BeagleBone Black GPIO BSP specific implementation.
 *
 * This file is included in the BSP build from bspnucleoh753zi.yml only so
 * everything can be specific to the Nucleo H753zi board.
 */

#include <assert.h>
#include <bsp/gpio.h>
#include <rtems.h>
#include <stdlib.h>
#include <stm32h7xx_hal_gpio.h>

static const uint32_t gpio_bank_addrs[] = {GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE,
                                           GPIOE_BASE, GPIOF_BASE, GPIOG_BASE, GPIOH_BASE,
                                           GPIOI_BASE, GPIOJ_BASE, GPIOK_BASE};

/**
 * @brief Converts a pin number (0-15) to the corresponding GPIO pin value (GPIO_PIN_0 -
 * GPIO_PIN_15)
 * @param pin The pin number to convert (32-bit value)
 * @return uint16_t The corresponding GPIO pin value
 */
uint16_t static inline pin_to_gpio_pin(uint32_t pin) { return (uint16_t)(1 << (uint16_t)pin); }

rtems_status_code rtems_gpio_bsp_multi_set(uint32_t bank, uint32_t bitmask) {
    return RTEMS_NOT_DEFINED;
}

rtems_status_code rtems_gpio_bsp_multi_clear(uint32_t bank, uint32_t bitmask) {
    return RTEMS_NOT_DEFINED;
}

uint32_t rtems_gpio_bsp_multi_read(uint32_t bank, uint32_t bitmask) { return RTEMS_NOT_DEFINED; }

rtems_status_code rtems_gpio_bsp_set(uint32_t bank, uint32_t pin) {
    HAL_GPIO_WritePin((GPIO_TypeDef *)gpio_bank_addrs[bank], pin_to_gpio_pin(pin), GPIO_PIN_SET);
    return RTEMS_SUCCESSFUL;
}

rtems_status_code rtems_gpio_bsp_clear(uint32_t bank, uint32_t pin) {
    HAL_GPIO_WritePin((GPIO_TypeDef *)gpio_bank_addrs[bank], pin_to_gpio_pin(pin), GPIO_PIN_RESET);
    return RTEMS_SUCCESSFUL;
}

uint32_t rtems_gpio_bsp_get_value(uint32_t bank, uint32_t pin) { return RTEMS_NOT_DEFINED; }

rtems_status_code rtems_gpio_bsp_select_input(uint32_t bank, uint32_t pin, void *bsp_specific) {
    return RTEMS_NOT_DEFINED;
}

/**
 * @brief Configure a GPIO pin as output
 * @param bank The GPIO bank to use. A=0, B=1, etc.
 * @param pin The pin number in the bank to use (0-15). Do _not_ use STM32 HAL pins (GPIO_PIN_3)
 * values here!
 * @return always RTEMS_SUCCESSFUL
 */
rtems_status_code rtems_gpio_bsp_select_output(uint32_t bank, uint32_t pin, void *bsp_specific) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = pin_to_gpio_pin(pin);
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_MEDIUM;  // Default to medium. This should be set in bsp_specific.
    HAL_GPIO_Init((GPIO_TypeDef *)gpio_bank_addrs[bank], &GPIO_InitStruct);

    return RTEMS_SUCCESSFUL;
}

rtems_status_code rtems_gpio_bsp_select_specific_io(uint32_t bank, uint32_t pin, uint32_t function,
                                                    void *pin_data) {
    return RTEMS_NOT_DEFINED;
}

rtems_status_code rtems_gpio_bsp_set_resistor_mode(uint32_t bank, uint32_t pin,
                                                   rtems_gpio_pull_mode mode) {
    /* TODO: Add support for setting up resistor mode */
    return RTEMS_NOT_DEFINED;
}

rtems_vector_number rtems_gpio_bsp_get_vector(uint32_t bank) { return RTEMS_NOT_DEFINED; }

uint32_t rtems_gpio_bsp_interrupt_line(rtems_vector_number vector) { return RTEMS_NOT_DEFINED; }

rtems_status_code rtems_gpio_bsp_enable_interrupt(uint32_t bank, uint32_t pin,
                                                  rtems_gpio_interrupt interrupt) {
    return RTEMS_NOT_DEFINED;
}

rtems_status_code rtems_gpio_bsp_disable_interrupt(uint32_t bank, uint32_t pin,
                                                   rtems_gpio_interrupt interrupt) {
    return RTEMS_NOT_DEFINED;
}

rtems_status_code rtems_gpio_bsp_multi_select(rtems_gpio_multiple_pin_select *pins,
                                              uint32_t pin_count, uint32_t select_bank) {
    return RTEMS_NOT_DEFINED;
}

rtems_status_code rtems_gpio_bsp_specific_group_operation(uint32_t bank, uint32_t *pins,
                                                          uint32_t pin_count, void *arg) {
    return RTEMS_NOT_DEFINED;
}
