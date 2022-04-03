#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "keymap_french.h"

#define BASE 0
#define SYMB 4
#define GAME 5
#define ACCENT 5
#define RESET_ACCESS 11
#define RST_LR 12

// accented characters
#define M_ACIRC 2 // â
#define M_ECIRC 3 // ê
#define M_ICIRC 4 // î
#define M_OCIRC 5 // ô
#define M_UCIRC 6 // û
#define M_AUMLT 7 // ä
#define M_EUMLT 8 // ë
#define M_IUMLT 9 // ï
#define M_OUMLT 10 // ö
#define M_UUMLT 11 // ü

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
    KC_TAB,  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,               KC_6,   KC_7,   KC_8,     KC_9,    KC_0,    KC_F12,
    _______, KC_Q,    KC_W,     KC_F,     KC_P,     KC_B,               KC_J,   KC_L,   KC_U,     KC_Y,    US_SCLN, KC_MINS,
    KC_LSFT, KC_A,    KC_R,     KC_S,     KC_T,     KC_G,               KC_M,   KC_N,   KC_E,     KC_I,    KC_O,    US_DGRV,
    KC_LCTL, KC_X,    KC_C,     KC_D,     KC_V,     MEH_T(KC_Z),        KC_K,   KC_H,   KC_COMM,  KC_DOT,  KC_SLSH, US_ACUT,
                            KC_LEFT,  KC_RIGHT,                                               KC_UP,    KC_DOWN,
                                          F(0),  KC_BSPC,                   KC_RSFT, KC_ENT,
                                              KC_LCTRL,KC_LSFT,         KC_ALGR, KC_RGUI,
                                              KC_END, LALT_T(KC_HOME),  KC_PGUP, KC_PGDOWN
  ),
/*  Symbol Layer
 *
 * ,------------------------------------------           ------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------           +------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+-------           +------+------+------+------+------+------|
 * |      |  </> |   @  |   {  |   }  |   |  |           |  _   |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |           |  -   |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |           |   =  |   1  |   2  |   3  |   \  |      |
 * `------+------+------+------+------+-------           -------+------+------+------+------+------'
 *               |      |      |                                       |   0  |   .  |
 *               `-------------'                                       `-------------'
 */
  [SYMB]=LAYOUT_6x6(
    _______, KC_F1,   KC_F2,    KC_F3,    _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, _______, _______,  _______,  _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, FR_LABK, FR_AT,    FR_LCBR,  FR_RCBR, FR_PIPE,         FR_UNDS,  KC_7,   KC_8,     KC_9,    FR_ASTR, _______,
    _______, FR_HASH, FR_DLR,   FR_LPRN,  FR_RPRN, FR_GRV,          FR_MINS,  KC_4,   KC_5,     KC_6,    FR_PLUS, _______,
    _______, FR_PERC, FR_CIRC,  FR_LBRC,  FR_RBRC, FR_TILD,         FR_EQL,   KC_1,   KC_2,     KC_3,    FR_BSLS, TG(GAME),
                      _______,  _______,                                      KC_0,   FR_DOT,
                                        _______, _______,             _______, _______,
                                          _______, _______,         _______, _______,
                                          _______, _______,         _______, _______
  ),
  [GAME]=LAYOUT_6x6(
    KC_ESC,  KC_F1,   KC_F2,    KC_F3,    _______,  _______,        _______,  _______,  _______,  _______,  _______,  _______,
    KC_U,    KC_0,    KC_1,     KC_2,     KC_3,     KC_4,           _______,  _______,  _______,  _______,  _______,  _______,
    KC_I,    KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,           KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_Y,    KC_LSFT, KC_A,     KC_S,     KC_D,     KC_F,           KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     _______,
    KC_K,    KC_LCTL, KC_Z,     KC_X,     KC_C,     KC_V,           KC_B,     KC_N,     KC_M,     _______,  _______,  _______,
                      _______,  _______,                                                _______,  _______,
                                  KC_SPC,   KC_T,                     _______, _______,
                                    KC_B,   KC_G,                   _______, _______,
                                    _______,_______,                TG(GAME), _______
  ),
  /*  Accent Layer
 *
 * ,------------------------------------------           ------------------------------------------.
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+-------           +------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+-------           +------+------+------+------+------+------|
 * |      |      |  à   |  ä   |  â   |      |           |      |  î   |  ï   |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |  é   |  è   |  ë   |  ê   |      |           |      |  ô   |  ö   |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |  ù   |  ü   |  û   |      |           |      |      |      |      |      |      |
 * `------+------+------+------+------+-------           -------+------+------+------+------+------'
 *               |      |      |                                       |      |      |
 *               `-------------'                                       `-------------'
 */
  [ACCENT]=LAYOUT_6x6(
    _______, _______, _______, _______,     _______,    _______,        _______, _______,     _______,    _______, _______, _______,
    _______, _______, _______, _______,     _______,    _______,        _______, _______,     _______,    _______, _______, _______,
    _______, KC_TRNS, FR_AGRV, M(M_AUMLT),  M(M_ACIRC), _______,        _______, M(M_ICIRC),  M(M_IUMLT), _______, _______, _______,
    _______, FR_EACU, FR_EGRV, M(M_EUMLT),  M(M_ECIRC), _______,        _______, M(M_OCIRC),  M(M_OUMLT), _______, _______, _______,
    _______, KC_TRNS, FR_UGRV, M(M_UUMLT),  M(M_UCIRC), _______,        _______, _______,     _______,    _______, _______, _______,
                      _______, _______,                                             _______, _______,
                                  _______, _______,                         _______, _______,
                                    _______, _______,                   _______, _______,
                                    _______, _______,                   _______, _______
  ),
  [RESET_ACCESS]=LAYOUT_6x6(
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                      _______, _______,                                             _______, _______,
                                  _______, _______,                 _______, _______,
                                    _______, _______,           _______, _______,
                                    _______, MO(RST_LR),        _______, _______
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
  case M_ACIRC:
    if (record->event.pressed) {
      return MACRO(T(LBRC), // FR_CIRC
                   T(Q), // FR_A
                   END);
    }
    break;
  case M_ECIRC:
    if (record->event.pressed) {
      return MACRO(T(LBRC), // FR_CIRC
                   T(E),
                   END);
    }
    break;
  case M_UCIRC:
    if (record->event.pressed) {
      return MACRO(T(LBRC), // FR_CIRC
                   T(U),
                   END);
    }
    break;
  case M_ICIRC:
    if (record->event.pressed) {
      return MACRO(T(LBRC), // FR_CIRC
                   T(I),
                   END);
    }
    break;
  case M_OCIRC:
    if (record->event.pressed) {
      return MACRO(T(LBRC), // FR_CIRC
                   T(O),
                   END);
    }
    break;
  case M_AUMLT:
    if (record->event.pressed) {
      return MACRO(D(LSFT),
                   T(LBRC),
                   U(LSFT),
                   T(Q),
                   END);
    }
    break;
  case M_EUMLT:
    if (record->event.pressed) {
      return MACRO(D(LSFT),
                   T(LBRC),
                   U(LSFT),
                   T(E),
                   END);
    }
    break;
  case M_UUMLT:
    if (record->event.pressed) {
      return MACRO(D(LSFT),
                   T(LBRC),
                   U(LSFT),
                   T(U),
                   END);
    }
    break;
  case M_IUMLT:
    if (record->event.pressed) {
      return MACRO(D(LSFT),
                   T(LBRC),
                   U(LSFT),
                   T(I),
                   END);
    }
    break;
  case M_OUMLT:
    if (record->event.pressed) {
      return MACRO(D(LSFT),
                   T(LBRC),
                   U(LSFT),
                   T(O),
                   END);
    }
    break;

  }
  return MACRO_NONE;
};