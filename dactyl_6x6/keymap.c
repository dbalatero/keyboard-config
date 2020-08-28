#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _RAISE 1

#define RAISE TG(_RAISE)

// Define super key as ctrl, cmd, alt
#define KC_SUPER LCTL(LGUI(KC_LALT))

// Combination ctrl when held, enter when tapped
#define HYPER_SEMI HYPR_T(KC_SCLN)

// TODO
// super
// arrow key layer
// leader key for layer?

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

                                      // 1         2                               7         8
                                      KC_LCTRL, KC_LGUI,                        KC_BSPACE, KC_SPACE,
                                        // 3       4                          9     10
                                        KC_LALT, _______,                     KC_SUPER, _______,
                                          // 5      6                       11    12
                                          _______, _______,                  KC_F1, RAISE
  ),

  [_RAISE] = LAYOUT_6x6(

       _______  ,_______,_______,_______,_______,_______,                        _______,_______ ,_______,_______,_______,_______    ,
       KC__VOLUP,_______,_______,_______,_______,_______,                        _______,_______ ,_______,_______,_______,KC__VOLDOWN,
       _______  ,_______,_______,_______,_______,_______,                        _______,_______ ,RAISE  ,_______,_______,_______    ,
       _______  ,_______,_______,_______,_______,_______,                        KC_LEFT ,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______    ,
       _______  ,_______,_______,_______,_______,_______,                        _______,KC__MUTE,_______,_______,_______,_______    ,
                         _______,_______,                                                         _______,_______,

                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
