#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _SYMBOLS = 1,
    _NUMBERS = 2,
    _NAVIGATION = 3,
    _ADJUST = 4,
  };

  /* Dynamic copy/paste/cut based on cgswap status*/
enum custom_keycodes {
    RSQBRKT = SAFE_RANGE,
    LSQBRKT,
    PIPE,
    BSLS,
};
// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSQBRKT:
        if (record->event.pressed) {
            SEND_STRING("]");
        } else {
        // when keycode QMKBEST is released
         }
        break;
        case LSQBRKT:
        if (record->event.pressed) {
            SEND_STRING("[");
         } else {
        // when keycode QMKBEST is released
        }
        break;
        case PIPE:
        if (record->event.pressed) {
            SEND_STRING("|");
         } else {
        // when keycode QMKBEST is released
        }
        break;
        case BSLS:
        if (record->event.pressed) {
            SEND_STRING("\\");
         } else {
        // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

// Adding unique tapping terms for space and tab keys and right homemods
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMBERS,KC_TAB):
            return TAPPING_TERM - 50;
        case LT(_SYMBOLS,KC_SPC):
            return TAPPING_TERM - 50;
        case RCTL_T(KC_J):
            return TAPPING_TERM + 50;
        case RALT_T(KC_K):
            return TAPPING_TERM + 50;
        case RGUI_T(KC_L):
            return TAPPING_TERM + 50;
        case RSFT_T(KC_SCLN):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_ESC),LSFT_T(KC_A),LGUI_T(KC_S),LALT_T(KC_D),LCTL_T(KC_F),KC_G,      KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_SYMBOLS),  MO(_NUMBERS),   LT(_SYMBOLS,KC_SPC),   MO(_NUMBERS), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, LSQBRKT,    RSQBRKT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_BSPC,    _______,   _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      PIPE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,   _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                    //`--------------------------'  `--------------------------'
),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY] = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_SYMBOLS] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_NUMBERS] = { ENCODER_CCW_CW(KC_UP,   KC_DOWN), ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  },
  [_NAVIGATION] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  },
  [_ADJUST] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  }
};
