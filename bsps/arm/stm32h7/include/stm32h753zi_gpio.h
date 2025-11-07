/**
 * @file stm32h753zi_gpio.h
 *
 * @ingroup arm_stm32h7
 *
 * @brief GPIO header for STM32H7 Nucleo Board.
 */

/**
 * Copyright (c) 2025 Jens Willy Johannsen <jens@jenswilly.dk>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

// Only include this file if we are building for the Nucleo H753zi board
#if IS_NUCLEO_H753ZI

#define BSP_GPIO_PIN_COUNT 128
#define BSP_GPIO_PINS_PER_BANK 16

#endif