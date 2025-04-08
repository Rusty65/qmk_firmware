#pragma once

#define MASTER_LEFT
//#ifdef CONVERT_TO_KB2040

//Encoder blips per detent|
//#define ENCODER_RESOLUTION 4

//#define PIMORONI_TRACKBALL_ADDRESS 0x0A

//Cirque touchpad settings
#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_ADDR 0x2A
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE //enable circular scroll
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE //cursor glide
// #define CIRQUE_PINNACLE_TAP_ENABLE //tap to left click

// Haptics
#define DRV2605L_FB_ERM_LRA 1
#define DRV2605L_FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define DRV2605L_FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define DRV2605L_RATED_VOLTAGE 2
#define DRV2605L_V_PEAK 2.1
#define DRV2605L_V_RMS 2.0
//#define DRV2605L_V_PEAK 2.1
#define DRV2605L_F_LRA 150 /* resonance freq */

#define DRV2605L_GREETING 113
#define DRV2605L_DEFAULT_MODE 47


//Split Keyboard data sync
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define SPLIT_OLED_ENABLE
#define SPLIT_HAPTIC_ENABLE




//Tri layer definitions
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4

//caps word config
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

// #define WS2812_DI_PIN GP17 // this is your rgb_matrix.
// #define CUSTOM_DI_PIN GP23 // use rgblight

// #define RGBLIGHT_LED_COUNT 1

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
//#endif
