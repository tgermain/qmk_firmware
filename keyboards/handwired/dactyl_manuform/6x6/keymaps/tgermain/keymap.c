#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"


#define BASE 0
#define SYMB 4
#define RESET_ACCESS 11
#define RST_LR 12

#define ALT_TAB LALT(KC_TAB)

// empty layer
// [RESET]=LAYOUT_6x6(
//   _______ ,_______   ,_______ ,_______ ,_______ ,_______                ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
//   _______ ,_______   ,_______ ,_______ ,_______ ,_______                ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
//   _______ ,_______   ,_______ ,_______ ,_______ ,_______                ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
//   _______ ,_______   ,_______ ,_______ ,_______ ,_______                ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
//   _______ ,_______   ,_______ ,_______ ,_______ ,_______                ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
//                      _______ ,_______                                          ,_______ ,_______ ,
//                                 _______ ,_______             ,_______, _______,
//                                   _______ ,_______        ,_______, _______,
//                                   _______ ,_______        ,_______, _______
// ),




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]=LAYOUT_6x6(
    F(1)    ,KC_MPRV      ,KC_MPLY  ,KC_MNXT,KC_F4    ,KC_F5           ,KC_F6  ,KC_F7   ,KC_F8    ,KC_F9   ,KC_F10  ,KC_F11 ,
    KC_TAB  ,KC_1         ,KC_2     ,KC_3   ,KC_4     ,KC_5            ,KC_6   ,KC_7    ,KC_8     ,KC_9    ,KC_0    ,KC_F12 ,
    _______ ,KC_Q         ,KC_W     ,KC_E   ,KC_R     ,KC_T            ,KC_Y   ,KC_U    ,KC_I     ,KC_O    ,KC_P    ,KC_MINS,
    KC_LSFT ,KC_A         ,KC_S     ,KC_D   ,KC_F     ,KC_G            ,KC_H   ,KC_J    ,KC_K     ,KC_L    ,KC_SCLN ,KC_QUOT,
    KC_LCTL ,LALT_T(KC_Z) ,KC_X     ,KC_C   ,KC_V     ,MEH_T(KC_B)     ,KC_N   ,KC_M    ,KC_COMM  ,KC_DOT  ,KC_SLSH ,KC_BSLASH,
                          KC_LEFT   ,KC_RIGHT                                           ,KC_UP    ,KC_DOWN,
                                  KC_SPC  ,KC_BSPC            ,ALT_TAB, KC_ENT,
                                    KC_LCTRL,KC_LSFT        ,KC_END,  KC_DEL,
                                    KC_END  ,KC_HOME        ,KC_LGUI, KC_LALT
  ), 
  [RESET_ACCESS]=LAYOUT_6x6(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
                     _______ ,_______                                             ,_______ ,_______ ,
                                  _______ ,_______             ,_______, _______,
                                    _______ ,_______        ,_______, _______,
                                    _______ ,MO(RST_LR)      ,_______, _______
  ),
  [RST_LR]=LAYOUT_6x6(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
                      _______ ,_______                                             ,_______ ,_______ ,
                                  _______ ,RESET                     ,_______, _______,
                                        _______ ,_______         ,_______, _______,
                                        _______ ,_______         ,_______, _______
  ),

};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_TAP_KEY(SYMB, KC_SPC), // space when tap, hold : momentary Layer symbols
	[1] = ACTION_LAYER_TAP_KEY(RESET_ACCESS, KC_ESC), // space when tap, hold : momentary Layer symbols
};