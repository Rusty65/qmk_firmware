#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _GAMING = 1,
    _SYMBOLS = 3,
    _NUMBERS = 2,
    _NAVIGATION = 4,
    _MOUSE = 5,
    _ADJUST = 6,
  };

  //Tap Dance custom calls
enum {
    TD_VOLU_NX,
    TD_VOLD_PV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_VOLU_NX] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MNXT),
    [TD_VOLD_PV] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MPRV),
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

// // Adding unique tapping terms for space and tab keys and right homemods
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMBERS,KC_TAB):
            return TAPPING_TERM - 25;
        case LT(_SYMBOLS,KC_SPC):
            return TAPPING_TERM - 25;
        case RCTL_T(KC_J):
            return TAPPING_TERM + 50;
        case RALT_T(KC_K):
            return TAPPING_TERM + 50;
        case RGUI_T(KC_L):
            return TAPPING_TERM + 50;
        case RSFT_T(KC_SCLN):
            return TAPPING_TERM + 50;
        case LCTL_T(KC_ESC):
            return TAPPING_TERM -75;
        default:
            return TAPPING_TERM;
    }
}


// in keymap.c:
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LGUI_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  LALT_T(KC_MINS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,LT(_NAVIGATION,KC_G),             KC_H,    KC_J,   KC_K,     KC_L, KC_SCLN, RCTL_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_SYMBOLS),  LT(_NUMBERS,KC_SPC),   LT(_SYMBOLS,KC_SPC),   MO(_NUMBERS), KC_MUTE
                                      //`--------------------------'  `--------------------------'

  ),

    [_GAMING] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LGUI_T(KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  LALT_T(KC_MINS),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F, LT(_NAVIGATION,KC_G),            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RCTL_T(KC_QUOT),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,   MO(_SYMBOLS),  LT(_NUMBERS,KC_SPC),   LT(_SYMBOLS,KC_SPC),   MO(_NUMBERS), KC_MUTE
                                        //`--------------------------'  `--------------------------'

    ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LGUI_T(KC_TILD), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  LALT_T(KC_GRV),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, KC_LPRN,                      KC_RPRN, _______, _______, _______, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         PIPE, _______, _______, _______, _______, KC_LCBR,                      KC_RCBR, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, _______, KC_BSPC,    XXXXXXX,   _______, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  LGUI_T(KC_TILD),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   LALT_T(KC_GRV),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BSLS,    _______, _______, _______, _______, LSQBRKT,                      RSQBRKT, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, _______, XXXXXXX,     KC_ENT, _______, KC_MPLY
                                      //`--------------------------'  `--------------------------'
  ),
  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                    //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, MS_BTN3, MS_BTN2, MS_BTN1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN1, _______, MS_BTN1,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, CG_NORM, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,PDF(_QWERTY),PDF(_GAMING),              XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CG_SWAP, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          DT_PRNT, _______, _______,    _______, _______, HF_TOGG
                                      //`--------------------------'  `--------------------------'
  )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_GAMING] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
  [_NUMBERS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(C(KC_RGHT), C(KC_LEFT))  },
  [_NAVIGATION] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_MOUSE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_ADJUST] = { ENCODER_CCW_CW(DT_UP, DT_DOWN), ENCODER_CCW_CW(HF_PREV, HF_NEXT)  }
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOLS, _NUMBERS ,_ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case 6:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

static void oled_render_default_layer_state(void) {
    oled_write_P(PSTR("Mode: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Homerow mods"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

static void mode(bool swap) {
    if (swap == true) {
        oled_write_ln_P(PSTR("Mode: Mac"), false);
    } else {
        oled_write_ln_P(PSTR("Mode: PC"), false);
    }
}

bool oled_task_user(void) {
    //if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_default_layer_state();
        if (is_caps_word_on()) {
            oled_write_ln_P(PSTR("CAPS-WORD: On "), false);
        } else {
            oled_write_ln_P(PSTR("CAPS-WORD: Off"), false);
        }
        mode(keymap_config.swap_lctl_lgui);

    //} else {
    //}
    return false;
}
#endif // OLED_ENABLE
