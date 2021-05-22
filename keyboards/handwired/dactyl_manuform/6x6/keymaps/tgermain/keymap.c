#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

#define BASE 0
#define SYMB 4
#define GAME 5
#define RESET_ACCESS 11
#define RST_LR 12

#define ALT_TAB LALT(KC_TAB)

// empty layer
// [RESET]=LAYOUT_6x6(
//   _______, _______,   _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
//   _______, _______,   _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
//   _______, _______,   _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
//   _______, _______,   _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
//   _______, _______,   _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
//                      _______, _______,                                          _______, _______, 
//                                 _______, _______,             _______, _______,
//                                   _______, _______,        _______, _______,
//                                   _______, _______,        _______, _______
// ),




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]=LAYOUT_6x6(
    F(1),    KC_MPRV, KC_MPLY,  KC_MNXT,  KC_F4,    KC_F5,              KC_F6,  KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11, 
    KC_TAB,  US_1,    US_2,     US_3,     US_4,     US_5,               US_6,   US_7,   US_8,     US_9,    US_0,    KC_F12, 
    _______, US_Q,    US_W,     US_F,     US_P,     US_B,               US_J,   US_L,   US_U,     US_Y,    US_SCLN, KC_MINS,
    KC_LSFT, US_A,    US_R,     US_S,     US_T,     US_G,               US_M,   US_N,   US_E,     US_I,    US_O,    US_DGRV,
    KC_LCTL, KC_X,    US_C,     US_D,     US_V,     MEH_T(US_Z),        US_K,   US_H,   US_COMM,  US_DOT,  US_SLSH, US_ACUT,
                            KC_LEFT,  KC_RIGHT,                                               KC_UP,    KC_DOWN,
                                                F(0),  KC_BSPC,               ALT_TAB, KC_ENT,
                                                  KC_LCTRL,KC_LSFT,           KC_END,  KC_DEL,
                                                  KC_END,  LALT_T(KC_HOME),           KC_LGUI, KC_LALT
  ), 
  [SYMB]=LAYOUT_6x6(
    _______, KC_F1,   KC_F2,    KC_F3,    _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, _______, _______,  _______,  _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, US_ACUT, US_AT,    US_LCBR,  US_RCBR, US_PIPE,         US_UNDS,  US_7,   US_8,     US_9,    US_ASTR, _______,
    _______, US_HASH, US_DLR,   US_LPRN,  US_RPRN, US_DGRV,         US_MINS,  US_4,   US_5,     US_6,    US_PLUS, _______,
    _______, US_PERC, US_DCIR,  US_LBRC,  US_RBRC, US_DTIL,         US_EQL,   US_1,   US_2,     US_3,    US_BSLS, TG(GAME),
                      _______,  _______,                                      US_0,   US_DOT, 
                                        _______, _______,             _______, _______,
                                          _______, _______,         _______, _______,
                                          _______, _______,         _______, _______
  ),
  [GAME]=LAYOUT_6x6(
    KC_ESC,  KC_F1,   KC_F2,    KC_F3,    _______,  _______,        _______,  _______,  _______,  _______,  _______,  _______,
    US_U,    US_0,    US_1,     US_2,     US_3,     US_4,           _______,  _______,  _______,  _______,  _______,  _______,
    US_I,    KC_TAB,  US_Q,     US_W,     US_E,     US_R,           US_T,     US_Y,     US_U,     US_I,     US_O,     US_P,   
    US_Y,    KC_LSFT, US_A,     US_S,     US_D,     US_F,           US_G,     US_H,     US_J,     US_K,     US_L,     _______,
    US_B,    KC_LCTL, US_Z,     US_X,     US_C,     US_V,           US_B,     US_N,     US_M,     _______,  _______,  _______,
                      _______,  _______,                                                _______,  _______, 
                                  KC_SPC, _______,                    _______, _______,
                                    _______, _______,               _______, _______,
                                    _______, _______,               TG(GAME), _______
  ),
  [RESET_ACCESS]=LAYOUT_6x6(
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                      _______, _______,                                             _______, _______, 
                                  _______, _______,             _______, _______,
                                    _______, _______,        _______, _______,
                                    _______, MO(RST_LR),      _______, _______
  ),
  [RST_LR]=LAYOUT_6x6(
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                      _______, _______,                                             _______, _______, 
                                  _______, RESET,                     _______, _______,
                                        _______, _______,         _______, _______,
                                        _______, _______,         _______, _______
  ),

};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_TAP_KEY(SYMB, KC_SPC), // space when tap, hold : momentary Layer symbols
	[1] = ACTION_LAYER_TAP_KEY(RESET_ACCESS, KC_ESC), // space when tap, hold : momentary Layer symbols
};