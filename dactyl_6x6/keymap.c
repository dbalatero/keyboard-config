#include QMK_KEYBOARD_H

enum custom_keycodes {
  MOD_SUPER,
  TOGGLE_RAISE
};

#define _QWERTY 0
#define _RAISE 1

#define HYPER_SEMI MT(MOD_HYPR, KC_SEMICOLON)

void enable_raise_layer(void);
void disable_raise_layer(void);
void toggle_raise_layer(void);

bool handle_mod_super_key(keyrecord_t *record);

void enable_raise_layer() {
  if (IS_LAYER_ON(_RAISE)) return;

  // Send the OS the F17 key so we can toggle the visual indicator
  SEND_STRING(SS_TAP(X_F17));
  layer_on(_RAISE);
}

void disable_raise_layer() {
  if (IS_LAYER_OFF(_RAISE)) return;

  // Send the OS the F18 key so we can toggle the visual indicator
  SEND_STRING(SS_TAP(X_F18));

  layer_off(_RAISE);
}

void toggle_raise_layer() {
  if (IS_LAYER_ON(_RAISE)) {
    disable_raise_layer();
  } else {
    enable_raise_layer();
  }
}

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

    case KC_ENTER:
      if (record->event.pressed) disable_raise_layer();
      return true;

    case TOGGLE_RAISE:
      if (record->event.pressed) toggle_raise_layer();
      return false;
  }

  // Pass through all other keys
  return true;
}

// Thumb clusters, match to the comments in the keymaps
//
//         +----+
// +----+  |    |                                          +-----+
// |    |  | 2  | +----+                                   |     | +----+
// | 1  |  |    | |    |                           +-----+ | 7   | |    |
// |    |  +----+ | 3  |                           |     | |     | | 8  |
// +----+         |    | +----+             +----+ | 10  | +-----+ |    |
//                +----+ |    |             |    | |     |         +----+
//            +----+     | 4  |             | 9  | +-----+
//            |    |     |    |             |    |        +----+
//            | 5  |     +----+             +----+        | 12 |
//            +----++-----+                        +----+ |    |
//                  |     |                        |    | +----+
//                  | 6   |                        |11  |
//                  +-----+                        +----+
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_6x6(

     KC_ESC    , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8 , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
     KC_EQUAL  , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8   , KC_9   , KC_0   , KC_MINUS,
     KC_TAB    , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I   , KC_O   , KC_P   , KC_BSLASH,
     KC_ENTER  , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K   , KC_L   , HYPER_SEMI, KC_QUOT,
     KC_LSHIFT , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSHIFT,
                        _______, KC_GRAVE,                                                       KC_LBRC, KC_RBRC ,

                                      // 1         2                               7          8
                                      KC_LCTL, KC_LGUI,                      KC_BSPACE, KC_SPACE,
                                        // 3     4                            9        10
                                        KC_LALT, _______,                     _______, MOD_SUPER,
                                          // 5          6                 11      12
                                          TOGGLE_RAISE, _______,          KC_F1, TOGGLE_RAISE
  ),

  [_RAISE] = LAYOUT_6x6(

      _______  ,_______,_______   ,_______   ,_______    ,_______,                        _______,_______ ,_______      ,_______   ,_______,_______    ,
      KC__VOLUP,_______,_______   ,_______   ,_______    ,_______,                        _______,_______ ,_______      ,_______   ,_______,KC__VOLDOWN,
      _______  ,_______,_______   ,KC_MS_UP  ,_______    ,_______,                        _______,_______ ,TOGGLE_RAISE ,_______   ,_______,_______    ,
      _______  ,_______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,                        KC_LEFT,KC_DOWN ,KC_UP        ,KC_RGHT   ,_______,_______    ,
      _______  ,_______,_______   ,_______   ,_______    ,_______,                        _______,KC__MUTE,KC_MS_BTN1   ,KC_MS_BTN2,_______,_______    ,
                        _______,  _______,                                                                   _______    ,_______   ,

                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
