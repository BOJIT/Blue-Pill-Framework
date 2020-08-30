/**
 * @file
 * @brief Global application configuration
 *
 * @author @htmlonly &copy; @endhtmlonly 2020 James Bennion-Pedley
 *
 * @date 7 June 2020
 */

#ifndef __GLOBAL_CONFIG__
#define __GLOBAL_CONFIG__

/*----------------------------- General Config -------------------------------*/

/// Enables all system debugging features if defined
#define DEBUG

/// Macro for number of elements in an array
///#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

/* Clock configuration */
#define HSE_FREQ         8000000    ///< MCU input oscillator frequency
#define SYSCLK_FREQ      72000000   ///< Core MCU system frequency


/*----------------------------- FreeRTOS Config ------------------------------*/

#define FREERTOS_PRIORITIES     10  ///< Number of priorities that FreeRTOS uses

/*----------------------------------------------------------------------------*/

#endif /* __GLOBAL_CONFIG__ */
