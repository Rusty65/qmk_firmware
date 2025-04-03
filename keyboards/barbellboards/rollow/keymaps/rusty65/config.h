#pragma once

#define MASTER_LEFT
#ifdef CONVERT_TO_KB2040
//Tri layer definitions
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4

//caps word config
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#define WS2812_DI_PIN GP17 // this is your rgb_matrix.
#define CUSTOM_DI_PIN GP23 // use rgblight

#define RGBLIGHT_LED_COUNT 1

// set the same as your RGBLED_NUM, whichever is higher.
//#define CUSTOM_LED_COUNT 1
//#define RGBLED_NUM 1
// Target first led (built-in ws2812). No effect on RGB_MATRIX
//#define RGBLIGHT_LED_MAP { 0 }


/* #define RGB_DI_PIN GP14 replaced by below */
//#define WS2812_DI_PIN GP25
//#define WS2812_LED_COUNT 1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP14 // Specify a optional status led by GPIO number which blinks when entering the bootloader
#endif
