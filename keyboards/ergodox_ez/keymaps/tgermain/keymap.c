#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_french.h"

#define LED_BRIGHTNESS_VLO 5

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3 // default layer without special binding on space and shifts
#define CLMK 4 // colemak DH characters
#define ACC  5 // accented characters

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

//Tap Dance Declarations
enum {
  TD_LSFT_CLCK = 0
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  L3  |           | CLMK |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Alt |           | Media|   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|  tab |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    /   |
 * |--------+------+------+------+------+------|  Meh |           | Acc  |------+------+------+------+------+--------|
 * |shift/CLK|  Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  | LGUI | Left | Right|                                       |  Up  | Down |      | LALT | Ctrl |
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
                                              F(0), KC_BSPC,  KC_END,
        // right hand
        TG(CLMK),    KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_TRNS,
        TG(MDIA),   KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_QUOT,
                    KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  FR_SLSH,
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
       KC_TRNS, FR_LESS, FR_AT,   FR_LCBR, FR_RCBR, FR_PIPE, KC_TRNS,
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
       KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

/* Keymap 4: Base Colemak Mod-DH layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   :  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[CLMK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TRNS,    KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,    FR_Q,       FR_W,   KC_F,   KC_P,   KC_B,   KC_TRNS,
        KC_TRNS,    FR_A,       KC_R,   KC_S,   KC_T,   KC_G,
        KC_TRNS,    FR_Z,       KC_X,   KC_C,   KC_D,   KC_V,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                 KC_SPACE, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS,    KC_6,   KC_7,   KC_8,   KC_9,    KC_0,      KC_TRNS,
        KC_TRNS,    KC_J,   KC_L,   KC_U,   KC_Y,    FR_SCLN,   KC_TRNS,
                    FR_M,   KC_N,   KC_E,   KC_I,    KC_O,      KC_TRNS,
        KC_TRNS,    KC_K,   KC_H,   FR_COMM,FR_DOT,  FR_COLN,   KC_TRNS,
                            KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,   KC_TRNS,
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

       KC_TRNS, KC_TRNS, FR_AGRV, M(M_AUMLT), M(M_ACIRC), KC_TRNS, KC_TRNS,
       KC_TRNS, FR_EACU, FR_EGRV, M(M_EUMLT), M(M_ECIRC), KC_TRNS,
       KC_TRNS, KC_TRNS, FR_UGRV, M(M_UUMLT), M(M_UCIRC), KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, M(M_ICIRC), M(M_IUMLT), KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, M(M_OCIRC), M(M_OUMLT), KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
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

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for shift, twice for caps lock
  [TD_LSFT_CLCK]  =  ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPSLOCK)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_TAP_KEY(SYMB, KC_SPC), // space when tap, hold : momentary Layer 1 (symbols)
};


//KC_CAPSLOCK
static bool shift_disabled = false;
static bool delete_pressed = false;
/**
 * Change shift+backspace into delete and do not register the shift modifier.
 */
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if(keycode == KC_BSPC) {
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
  } else if(keycode == KC_LSFT && !record->event.pressed && delete_pressed) {
    delete_pressed = false;
    shift_disabled = false;
    unregister_code(KC_DEL);
    register_code(KC_BSPC);
    return false;
  }
  return true;
}

// Runs whenever there is a layer state change.
// state is a 32 bit where each bit on is a layer activated
// note that the base layer is always active which mean our first is always at 1
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_led_all_set(LED_BRIGHTNESS_VLO);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();


    // to set our leds on our off we rely on bitwise and mask operations
    uint32_t symb_mask = 0x00000003; // last 8 bits : 0000 0011 -> base layer + layer 1
    uint32_t mdia_mask = 0x00000005; // last 8 bits : 0000 0101 -> base layer + layer 2
    uint32_t game_mask = 0x00000009; // last 8 bits : 0000 1001 -> base layer + layer 3
    uint32_t clmk_mask = 0x00000011; // last 8 bits : 0001 0001 -> base layer + layer 4

    if (state & symb_mask) {
        ergodox_right_led_3_on(); // blue led low for symbol layer
    }

    if (state & mdia_mask) {
        ergodox_right_led_2_on(); // green led low for media layer
    }

    if (state & game_mask) {
        ergodox_right_led_1_on(); // red led low for game layer
    }

    if (state & clmk_mask) {
        ergodox_right_led_1_set(30); // red led high for accent layer
        ergodox_right_led_3_set(10); // green led high for accent layer
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
    }

    return state;
};
