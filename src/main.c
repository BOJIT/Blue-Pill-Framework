/**
 * @file
 * @brief Main entry point for the program
 *
 */

/*------------------------------- PREPROCESSOR -------------------------------*/

/* Include global configuration file and main declarations */
#include "GlobalConfig.h"
#include "main.h"

/* Include FreeRTOS Headers */
#include "FreeRTOS.h"
#include "task.h"

/* Include required libopencm3 headers */
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/*----------------------------- PUBLIC FUNCTIONS -----------------------------*/

/** 
 * @brief Setup basic hardware configuration for the STM32F1 to run, which at
 * minimum involves initialising the RCC and clock hardware.
*/
void hardwareInitialise(void) {
    /* Use preset clock settings - this is fine for most projects */
    rcc_clock_setup_in_hse_8mhz_out_72mhz();

    /* Simple Blink LED Example */
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

/*--------------------------------- FREERTOS ---------------------------------*/

/** 
 * @brief StackOverflow Handler: put any debug/error handling code here:
*/
extern void vApplicationStackOverflowHook(xTaskHandle *pxTask, 
                                          signed portCHAR *pcTaskName);

void vApplicationStackOverflowHook(xTaskHandle *pxTask __attribute((unused)),
                            signed portCHAR *pcTaskName __attribute((unused))) {
    for(;;);    // Loop forever here..
}

/** 
 * @brief Task: Blink System LED.
*/
void startBlink(void *args __attribute((unused))) {

    for (;;) {
        gpio_toggle(GPIOC, GPIO13);
        vTaskDelay(100);
	}
}

/*-------------------------------- MAIN ENTRY --------------------------------*/

/** 
 * @brief This is the main entry point to the program
*/
int main(void) {
    /* Non-OS-Dependent Initialisation: */
    hardwareInitialise();

    /* Create FreeRTOS Objects: */
    xTaskCreate(startBlink, "Blink", 350, NULL, 5, NULL);

    /* Start Scheduler: */
    vTaskStartScheduler();

    /* This point is never reached, as the scheduler is blocking! */
    for (;;);
    return 0;
}
