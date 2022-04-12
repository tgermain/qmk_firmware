#include QMK_KEYBOARD_H
#include "keymap_french.h"

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

//Tap Dance Declarations
enum {
  TD_LSFT_CLCK,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for shift, twice for caps lock
  [TD_LSFT_CLCK]  =  ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPSLOCK),
};

//KC_CAPSLOCK
static bool shift_disabled = false;
static bool delete_pressed = false;

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
    // shift + backspace -> delete
    case KC_BSPC:
      if (record->event.pressed) {
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
            delete_pressed = true;
            shift_disabled = true;
            unregister_code(KC_LSFT);
            register_code(KC_DEL);
            return false;
        }
      } else if(delete_pressed) {
        delete_pressed = false;
        unregister_code(KC_DEL);

        if(shift_disabled) {
          shift_disabled = false;
          register_code(KC_LSFT);
        }
        return false;
      }
  }
  if(keycode == KC_LSFT && !record->event.pressed && delete_pressed) {
    delete_pressed = false;
    shift_disabled = false;
    unregister_code(KC_DEL);
    register_code(KC_BSPC);
    return false;
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

#define LED_BRIGHTNESS_VLO 5

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3 // default layer without special binding on space and shifts
#define ACC  4 // accented characters



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  L3  |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Alt |           | Media|   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|  tab |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|  Meh |           | Acc  |------+------+------+------+------+--------|
 * |shift/CLK|  Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  | LGUI | Left | Right|                                       |  Up  | Down |      | RALT | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |altTab| LGui |       | Prev | Next |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| RShift |Enter |
 *                                 |/L1   |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,             KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   TG(GAME),
        KC_TAB,             KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   ALT_TAB,
        KC_BSPC,            KC_A,       KC_S,   KC_D,   KC_F,   KC_G,
        TD(TD_LSFT_CLCK),   KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_MEH,
        KC_LCTRL,           KC_LALT,    KC_LGUI,KC_LEFT,KC_RGHT,
                                              ALT_TAB,  KC_MPLY,
                                                              KC_HOME,
                                              LT(SYMB, KC_SPC), KC_BSPC,  KC_END,
        // right hand
        KC_TRNS,    KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_TRNS,
        TG(MDIA),   KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_TRNS,
                    KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_TRNS,
        OSL(ACC),   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                            KC_UP,  KC_DOWN,  KC_TRNS,  KC_RALT,  KC_RCTRL,
        KC_MPRV,  KC_MNXT,
        KC_PGUP,
        KC_PGDN, KC_RSFT, KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  </> |   @  |   {  |   }  |   |  |      |           |      |  _   |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|  -   |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   =  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    . |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS

[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, FR_LABK, FR_AT,   FR_LCBR, FR_RCBR, FR_PIPE, KC_TRNS,
       KC_TRNS, FR_HASH, FR_DLR,  FR_LPRN, FR_RPRN, FR_GRV,
       KC_TRNS, FR_PERC, FR_CIRC, FR_LBRC, FR_RBRC, FR_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, FR_UNDS, FR_7,   FR_8,    FR_9,    FR_ASTR, KC_F12,
                FR_MINS, FR_4,   FR_5,    FR_6,    FR_PLUS, KC_TRNS,
       KC_TRNS, FR_EQL,  FR_1,   FR_2,    FR_3,    FR_BSLS, KC_TRNS,
                         FR_0,   FR_DOT,  KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Mute | VolUp|      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Prev | VolDn| Next |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Play |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_MPLY, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: game mode like  default layer without special binding on space and shifts
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | RShift |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[GAME] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                 KC_SPACE, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 5: accented characters
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  à   |  ä   |  â   |      |      |           |      |      |  î   |  ï   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  é   |  è   |  ë   |  ê   |      |------|           |------|      |  ô   |  ö   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  ù   |  ü   |  û   |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// ACCENTED CHARACTERS
[ACC] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS, FR_AGRV, M_AUMLT, M_ACIRC, KC_TRNS, KC_TRNS,
       KC_TRNS, FR_EACU, FR_EGRV, M_EUMLT, M_ECIRC, KC_TRNS,
       KC_TRNS, KC_TRNS, FR_UGRV, M_UUMLT, M_UCIRC, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, M_ICIRC,  M_IUMLT,  KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, M_OCIRC,  M_OUMLT,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs whenever there is a layer state change.
// state is a 32 bit where each bit on is a layer activated
// note that the base layer is always active which mean our first is always at 1
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_led_all_set(LED_BRIGHTNESS_VLO);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (biton32(state)) {
      case SYMB:
        ergodox_right_led_3_on(); // blue led low for symbol layer
        break;
      case MDIA:
        ergodox_right_led_2_on(); // green led low for media layer
        break;
      case GAME:
        ergodox_right_led_1_on(); // red led low for game layer
        break;
      case ACC:
        ergodox_right_led_1_set(30); // red led high for accent layer
        ergodox_right_led_3_set(10); // green led high for accent layer
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
    }

    return state;
};
