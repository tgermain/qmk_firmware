#include QMK_KEYBOARD_H
#include "keymap_french.h"

#define BASE 0
#define SYMB 4
#define GAME 5
#define ACCENT 6
#define RESET_ACCESS 11
#define RST_LR 12

enum custom_keycodes {
  M_ACIRC = SAFE_RANGE,
  M_ECIRC,
  M_ICIRC,
  M_OCIRC,
  M_UCIRC,
  M_AUMLT,
  M_EUMLT,
  M_IUMLT,
  M_OUMLT,
  M_UUMLT,
  ALT_TAB,
};

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.
const uint16_t ALT_TAB_TIMEOUT = 500;     // we will be using them soon.


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_ACIRC:
      if (record->event.pressed) {
        register_code(KC_LBRC);
        register_code(KC_Q);
      } else {
        unregister_code(KC_Q);
      }
      break;
    case M_ECIRC:
      if (record->event.pressed) {
        register_code(KC_LBRC);
        register_code(KC_E);
      } else {
        unregister_code(KC_E);
      }
      break;
    case M_UCIRC:
      if (record->event.pressed) {
        register_code(KC_LBRC);
        register_code(KC_U);
      } else {
        unregister_code(KC_U);
      }
      break;
    case M_ICIRC:
      if (record->event.pressed) {
        register_code(KC_LBRC);
        register_code(KC_I);
      } else {
        unregister_code(KC_I);
      }
      break;
    case M_OCIRC:
      if (record->event.pressed) {
        register_code(KC_LBRC);
        register_code(KC_O);
      } else {
        unregister_code(KC_O);
      }
      break;
    case M_AUMLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
        unregister_code(KC_RSFT);
        register_code(KC_Q);
      } else {
        unregister_code(KC_Q);
      }
      break;
    case M_EUMLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
        unregister_code(KC_RSFT);
        register_code(KC_E);
      } else {
        unregister_code(KC_E);
      }
      break;
    case M_UUMLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
        unregister_code(KC_RSFT);
        register_code(KC_U);
      } else {
        unregister_code(KC_U);
      }
      break;
    case M_IUMLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
        unregister_code(KC_RSFT);
        register_code(KC_I);
      } else {
        unregister_code(KC_I);
      }
      break;
    case M_OUMLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
        unregister_code(KC_RSFT);
        register_code(KC_O);
      } else {
        unregister_code(KC_O);
      }
      break;
      case ALT_TAB:
        if (record->event.pressed) {
          if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
          }
          alt_tab_timer = timer_read();
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer for alt-tab
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMEOUT) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

//Tap Dance Declarations
enum {
  TD_LSFT_CLCK,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for shift, twice for caps lock
  [TD_LSFT_CLCK]  =  ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPSLOCK),
};

#define SP_SYMB LT(SYMB, KC_SPC)
#define ESC_RSTA LT(RESET_ACCESS, KC_ESC)
#define TMUX_LDR LCTL(FR_B)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ,-------------------------------.          ,-------------------------------.
 * ,---------------| MPLY  | MNXT  |  F4   |  F5   |          |  F6   |  F7   |  F8   |  F9   |--------------.
 * |ESC_RST| MPRV  |-------+-------+-------+-------|          |-------+-------+-------+-------|  F10  | F11  |
 * |-------+-------|   2   |   3   |   4   |   5   |          |   6   |   7   |   8   |   9   |-------+------|
 * |ALT_TAB|   1   |-------+-------+-------+-------|          |-------+-------+-------+-------|   0   | F12  |
 * |-------+-------|   W   |   F   |   P   |   B   |          |   J   |   L   |   U   |   Y   |-------+------|
 * |TMUX_LD|   Q   |-------+-------+-------+-------|          |-------+-------+-------+-------|accent | DEL  |
 * |-------+-------|   R   |   S   |   T   |   G   |          |   M   |   N   |   E   |   I   |-------+------|
 * |  TAB  |   A   |-------+-------+---------------|          |---------------+-------+-------|   O   |ALT_TA|
 * |-------+-------|   C   |   D   |   V   | Z_meh |          |   K   |   H   |   ,   |   ;   |-------+------|
 * | LALT  |   X   |-------+-------+---------------'          `---------------+-------+-------|   :   |  !   |
 * `---------------| LEFT  | RIGHT |                                          |  UP   | DOWN  |--------------'
 *                 `---------------'  ,-------.                    ,-------.  `---------------'
 *                                    |SP_SYMB|-------.    ,-------|  ENT  |
 *                                    `-------+ BSPC  |    |TD(TD_L+-------'
 *                                            `-------'    `-------'
 *                                   ,----------------.    ,----------------.
 *                                   | LCTRL |  LSFT  |    |  ALGR  | RGUI  |
 *                                   |-------+--------/    \--------+-------|
 *                                   | HOME  |  END  |      | PGUP  |PGDOWN |
 *                                   `---------------'      `---------------'     generated by [keymapviz] */
  [BASE]=LAYOUT_6x6(
    ESC_RSTA,   KC_MPRV, KC_MPLY,  KC_MNXT,  KC_F4,    KC_F5,              KC_F6,  KC_F7,  KC_F8,    KC_F9,   KC_F10,      KC_F11,
    ALT_TAB,    KC_1,    KC_2,     KC_3,     KC_4,     KC_5,               KC_6,   KC_7,   KC_8,     KC_9,    KC_0,        KC_F12,
    TMUX_LDR,   FR_Q,    FR_W,     FR_F,     FR_P,     FR_B,               FR_J,   FR_L,   FR_U,     FR_Y,    OSL(ACCENT), KC_DEL,
    KC_TAB,     FR_A,    FR_R,     FR_S,     FR_T,     FR_G,               FR_M,   FR_N,   FR_E,     FR_I,    FR_O,        ALT_TAB,
    KC_LALT,    FR_X,    FR_C,     FR_D,     FR_V,     MEH_T(FR_Z),        FR_K,   FR_H,   FR_COMM,  FR_SCLN, FR_COLN,     FR_EXLM,
                            KC_LEFT,  KC_RIGHT,                                               KC_UP,    KC_DOWN,
                                          SP_SYMB,  KC_BSPC,                   TD(TD_LSFT_CLCK), KC_ENT,
                                              KC_LCTRL,KC_LSFT,         KC_ALGR, KC_RGUI,
                                              KC_HOME, KC_END,          KC_PGUP, KC_PGDOWN
  ),
/*                 ,-------------------------------.          ,-------------------------------.
 * ,---------------|  F2   |  F3   |       |       |          |       |       |       |       |--------------.
 * |       |  F1   |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       |          |       |       |       |       |-------+------|
 * |       |       |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|   @   |   {   |   }   |   |   |          |   _   |   7   |   8   |   9   |-------+------|
 * |       |  </>  |-------+-------+-------+-------|          |-------+-------+-------+-------|   *   |      |
 * |-------+-------|   $   |   (   |   )   |   `   |          |   -   |   4   |   5   |   6   |-------+------|
 * |       |   #   |-------+-------+---------------|          |---------------+-------+-------|   +   |      |
 * |-------+-------|   ^   |   [   |   ]   |   ~   |          |   =   |   1   |   2   |   3   |-------+------|
 * |       |   %   |-------+-------+---------------'          `---------------+-------+-------|   \   |TG(GAM|
 * `---------------|       |       |                                          |   0   |   .   |--------------'
 *                 `---------------'  ,-------.                    ,-------.  `---------------'
 *                                    |       |-------.    ,-------|       |
 *                                    `-------+       |    |       +-------'
 *                                            `-------'    `-------'
 *                                   ,----------------.    ,----------------.
 *                                   |       |        |    |        |       |
 *                                   |-------+--------/    \--------+-------|
 *                                   |       |       |      |       |       |
 *                                   `---------------'      `---------------'     generated by [keymapviz] */
  [SYMB]=LAYOUT_6x6(
    _______, KC_F1,   KC_F2,    KC_F3,    _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, _______, _______,  _______,  _______, _______,         _______,  _______,_______,  _______, _______, _______,
    _______, FR_LABK, FR_AT,    FR_LCBR,  FR_RCBR, FR_PIPE,         FR_UNDS,  FR_7,   FR_8,     FR_9,    FR_ASTR, _______,
    _______, FR_HASH, FR_DLR,   FR_LPRN,  FR_RPRN, FR_GRV,          FR_MINS,  FR_4,   FR_5,     FR_6,    FR_PLUS, _______,
    _______, FR_PERC, FR_CIRC,  FR_LBRC,  FR_RBRC, FR_TILD,         FR_EQL,   FR_1,   FR_2,     FR_3,    FR_BSLS, TG(GAME),
                      _______,  _______,                                      FR_0,   FR_DOT,
                                        _______, _______,             _______, _______,
                                          _______, _______,         _______, _______,
                                          _______, _______,         _______, _______
  ),
/*                 ,-------------------------------.          ,-------------------------------.
 * ,---------------|  F2   |  F3   |       |       |          | MPRV  | MPLY  | MNXT  |       |--------------.
 * |  ESC  |  F1   |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|   1   |   2   |   3   |   4   |          |       |       |       |       |-------+------|
 * |   U   |   0   |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|   A   |   Z   |   E   |   R   |          |   T   |   Y   |   U   |   I   |-------+------|
 * |   I   |  TAB  |-------+-------+-------+-------|          |-------+-------+-------+-------|   O   |  P   |
 * |-------+-------|   Q   |   S   |   D   |   F   |          |   G   |   H   |   J   |   K   |-------+------|
 * |   Y   | LSFT  |-------+-------+---------------|          |---------------+-------+-------|   L   |      |
 * |-------+-------|   W   |   X   |   C   |   V   |          |   B   |   N   |   M   |       |-------+------|
 * | LALT  | LCTL  |-------+-------+---------------'          `---------------+-------+-------|       |TG(GAM|
 * `---------------|       |       |                                          |       |       |--------------'
 *                 `---------------'  ,-------.                    ,-------.  `---------------'
 *                                    |  SPC  |-------.    ,-------|       |
 *                                    `-------+   T   |    |       +-------'
 *                                            `-------'    `-------'
 *                                   ,----------------.    ,----------------.
 *                                   |   B   |   G    |    |        |       |
 *                                   |-------+--------/    \--------+-------|
 *                                   |       |  DEL  |      |       |       |
 *                                   `---------------'      `---------------'     generated by [keymapviz] */
  [GAME]=LAYOUT_6x6(
    KC_ESC,  KC_F1,   KC_F2,    KC_F3,    _______,  _______,        KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  _______,  _______,
    FR_U,    KC_0,    KC_1,     KC_2,     KC_3,     KC_4,           _______,  _______,  _______,  _______,  _______,  _______,
    FR_I,    KC_TAB,  FR_A,     FR_Z,     FR_E,     FR_R,           FR_T,     FR_Y,     FR_U,     FR_I,     FR_O,     FR_P,
    FR_Y,    KC_LSFT, FR_Q,     FR_S,     FR_D,     FR_F,           FR_G,     FR_H,     FR_J,     FR_K,     FR_L,     _______,
    KC_LALT, KC_LCTL, FR_W,     FR_X,     FR_C,     FR_V,           FR_B,     FR_N,     FR_M,     _______,  _______,  TG(GAME),
                      _______,  _______,                                                _______,  _______,
                                  KC_SPC,   FR_T,                     _______, _______,
                                    FR_B,   FR_G,                   _______, _______,
                                    _______,KC_DEL,                 _______, _______
  ),
  /*  Accent Layer
/*                 ,-------------------------------.          ,-------------------------------.
 * ,---------------|       |       |       |       |          |       |       |       |       |--------------.
 * |       |       |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|       |       |       |       |          |       |       |       |       |-------+------|
 * |       |       |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|   à   |   ä   |   â   |       |          |       |   î   |   ï   |       |-------+------|
 * |       |       |-------+-------+-------+-------|          |-------+-------+-------+-------|       |      |
 * |-------+-------|   è   |   ë   |   ê   |       |          |       |   ô   |   ö   |       |-------+------|
 * |       |   é   |-------+-------+---------------|          |---------------+-------+-------|       |      |
 * |-------+-------|   ù   |   ü   |   û   |       |          |       |       |       |       |-------+------|
 * |       |       |-------+-------+---------------'          `---------------+-------+-------|       |      |
 * `---------------|       |       |                                          |       |       |--------------'
 *                 `---------------'  ,-------.                    ,-------.  `---------------'
 *                                    |       |-------.    ,-------|       |
 *                                    `-------+       |    |       +-------'
 *                                            `-------'    `-------'
 *                                   ,----------------.    ,----------------.
 *                                   |       |        |    |        |       |
 *                                   |-------+--------/    \--------+-------|
 *                                   |       |       |      |       |       |
 *                                   `---------------'      `---------------'     generated by [keymapviz] */
  [ACCENT]=LAYOUT_6x6(
    _______, _______, _______, _______,  _______,    _______,        _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______,  _______,    _______,        _______, _______,  _______, _______, _______, _______,
    _______, _______, FR_AGRV, M_AUMLT,  M_ACIRC, _______,           _______, M_ICIRC,  M_IUMLT, _______, _______, _______,
    _______, FR_EACU, FR_EGRV, M_EUMLT,  M_ECIRC, _______,           _______, M_OCIRC,  M_OUMLT, _______, _______, _______,
    _______, _______, FR_UGRV, M_UUMLT,  M_UCIRC, _______,           _______, _______,  _______, _______, _______, _______,
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


// led setup
void keyboard_pre_init_user(void) {
// Call the keyboard pre init code.
// Set our LED pins as output.
// Pro Micro LEDs are active low.
setPinOutput(B0);
setPinOutput(D5);
}

void dactyl_right_led_1_on(void) {
  writePinLow(B0);
}

void dactyl_right_led_2_on(void) {
  writePinLow(D5);
}

void dactyl_right_led_1_off(void) {
  writePinHigh(B0);
}

void dactyl_right_led_2_off(void) {
  writePinHigh(D5);
}

void dactyl_all_led_off(void) {
  dactyl_right_led_1_off();
  dactyl_right_led_2_off();
}

// Runs whenever there is a layer state change.
// state is a 32 bit where each bit on is a layer activated
// note that the base layer is always active which mean our first is always at 1
uint32_t layer_state_set_user(uint32_t state) {
  dactyl_all_led_off();
  uint8_t current_layer = biton32(state);

  switch (current_layer) {
    case SYMB:
      dactyl_right_led_1_on();
      break;
    case GAME:
    case RESET_ACCESS:
      dactyl_right_led_2_on();
      break;
    case ACCENT:
    case RST_LR:
      dactyl_right_led_1_on();
      dactyl_right_led_2_on();
      break;
    default:
      break;
  }
  return state;
};