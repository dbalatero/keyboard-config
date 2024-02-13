/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
  MOD_SUPER
};

#define _QWERTY 0
#define _RAISE 1

#define HYPER_SEMI MT(MOD_HYPR, KC_SEMICOLON)
#define FN_KEY MO(_RAISE)

bool handle_mod_super_key(keyrecord_t *record);

bool handle_mod_super_key(keyrecord_t *record) {
  if (record->event.pressed) {
    register_code(KC_LCTL);
    register_code(KC_LGUI);
    register_code(KC_LALT);
  } else {
    unregister_code(KC_LCTL);
    unregister_code(KC_LGUI);
    unregister_code(KC_LALT);
  }

  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOD_SUPER:
      return handle_mod_super_key(record);
  }

  // Pass through all other keys
  return true;
}

// Thumb clusters, match to the comments in the keymaps
//
//         +----+
// +----+  |    |                                          +-----+
// |    |  | 2  | +----+                                   |     |
// | 1  |  |    | |    |                           +-----+ |  9  |
// |    |  +----+ | 3  |                           |     | |     |
// +----+         |    |                    +----+ | 8   | +-----+
//    +----+      +----+                    |    | |     |
//    | 4  |  +----+                        | 7  | +-----+        +----+
//    |    |  | 5  |                        |    |        +----+  |    |
//    +----+  |    |                        +----+        |    |  |12  |
//            +----++-----+                        +----+ |11  |  +----+
//                  |     |                        |    | +----+
//                  | 6   |                        |10  |
//                  +-----+                        +----+
//


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_fun_full_bottom_row(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,                                                                KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,
        KC_EQL,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,                                                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,                                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSLS,
        KC_ENTER, KC_A,     KC_S,     KC_D,    KC_F,     KC_G,                                                                 KC_H,    KC_J,    KC_K,    KC_L,    HYPER_SEMI, KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,                                                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,
        //                                                     1       2        3          7       8        9
        _______,  _______,  KC_GRAVE, KC_LEFT, KC_RIGHT,    KC_LALT, FN_KEY,   KC_HOME,    KC_END, FN_KEY, MOD_SUPER,                   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,    _______,
        //                                                  4        5        6                10       11      12
                                                        KC_LCTL, KC_LGUI, _______,           KC_F12,  KC_BSPC,  KC_SPC
    ),

    [_RAISE] = LAYOUT_fun_full_bottom_row(
        _______, KC_BRMD, KC_BRMU, _______, _______, _______,                                                                  _______, KC_MPRV, KC_MPLY,      KC_MNXT,  KC_VOLD,  KC_MUTE,
        KC_VOLU, _______, _______, _______, _______, _______,                                                                  _______, _______, _______,      _______,  _______,  KC_VOLD,
        _______, _______, _______, _______, _______, _______,                                                                  _______, _______, _______,      KC_END,   _______,  _______,
        _______, _______, _______, _______, _______, _______,                                                                  KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT, _______,  _______,
        _______, _______, _______, _______, _______, _______,                                                                  _______, KC_MUTE, _______,      _______,  _______,  _______,
        _______, _______, _______, _______, _______,      _______, _______, _______,         _______, _______, _______,                 _______, _______,      _______,  _______,  _______,
                                                      _______, _______, _______,                KC_VOLU, _______, _______
    )
};
