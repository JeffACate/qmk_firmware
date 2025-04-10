/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTLT LCTL_T(KC_T)

// Right-hand home row mods
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)


enum preonic_layers {
  _colmak,
  _num,
  _sym,
  _nav,
  _func,
  _game,
  _qwerty,
  _layer7,
  _mouse
};

// enum preonic_keycodes {
// //   colmak = SAFE_RANGE,
// //   num,
// //   sym,
// //   nav,
// //   func,
// //   game,
// //   qwerty,
// //   layer7,
//     // BACKLIT = SAFE_RANGE,
//     // mouse
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// // switch (keycode) {
//         // case LOWER:
//         // if (record->event.pressed) {
//         //     layer_on(_LOWER);
//         //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
//         // } else {
//         //     layer_off(_LOWER);
//         //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
//         // }
//         // return false;
//         // break;
//         // case RAISE:
//         // if (record->event.pressed) {
//         //     layer_on(_RAISE);
//         //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
//         // } else {
//         //     layer_off(_RAISE);
//         //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
//         // }
//         // return false;
//         // break;
//         // if(IS_LAYER_ON(8))
//         {
//             // if (record->event.pressed) {
//                 // register_code(KC_RSFT);
//                 #ifdef RGBLIGHT_ENABLE
//                 rgblight_step();
//                 break;
//                 #endif
//                 // #ifdef __AVR__
//                 //     gpio_write_pin_low(E6);
//                 // #endif
//                 // return false;
//             // }
//         }
//         return true;
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_colmak] = LAYOUT_preonic_grid(
  // 1           , 2           , 3           , 4             , 5             , 6              , 7       , 8             , 9            , 10          , 11          , 12
    KC_F1        , KC_F2       , KC_F3       , KC_F4         , KC_F5         , KC_F6          , KC_F7   , KC_F8         , KC_F9        , KC_F10      , KC_F11      , KC_F12         ,
    KC_Q         , KC_W        , KC_F        , KC_P          , KC_G          , TG(3)          , TG(5)   , KC_J          , KC_L         , KC_U        , KC_Y        , KC_SCLN        ,
    LGUI_T(KC_A) , LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T)  , KC_D          , UG_TOGG        , KC_TRNS , KC_H          , LCTL_T(KC_N) , LSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)   ,
    LCTL_T(KC_Z) , KC_X        , KC_C        , KC_V          , KC_B          , KC_CAPS        , KC_NO   , KC_K          , KC_M         , KC_COMM     , KC_DOT      , LCTL_T(KC_SLSH),
    KC_NO        , KC_NO       , KC_NO       , LT(3, KC_TAB) , LT(1, KC_SPC) , LT(4, KC_BSPC) , KC_ESC  , LT(2, KC_ENT) , LT(8, KC_DEL), KC_NO       , KC_NO       , KC_NO)         ,


[_num] = LAYOUT_preonic_grid(
 // 1      , 2      , 3      , 4      , 5      , 6      , 7      , 8      , 9     , 10   , 11   , 12
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO, KC_NO, KC_NO  ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_TRNS, KC_7  , KC_8 , KC_9 , KC_UNDS,
    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_APP , KC_NO  , KC_NO  , KC_DLR , KC_4  , KC_5 , KC_6 , KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_TRNS, KC_1  , KC_2 , KC_3 , KC_BSLS,
    KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , KC_TRNS, KC_TRNS, KC_0   , KC_DOT, KC_NO, KC_NO, KC_NO
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |        Space       |Lower |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_sym] = LAYOUT_preonic_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_CIRC, KC_AT, KC_LCBR, KC_RCBR, KC_PLUS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN, KC_EQL, KC_NO, KC_NO, KC_APP, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
    KC_GRV, KC_PERC, KC_LBRC, KC_RBRC, KC_MINS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_nav] = LAYOUT_preonic_grid(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_APP, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_func] = LAYOUT_preonic_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_APP, KC_NO, KC_NO, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, MO(7), KC_NO, KC_NO, KC_NO
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_game] = LAYOUT_preonic_grid(
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_NUM, KC_F9, KC_F10, KC_F11, KC_MPLY,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_P, KC_VOLU,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_P4, KC_P5, KC_P6, KC_SCLN, KC_VOLD,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LCTL, KC_SPC, KC_SPC, MO(3), MO(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),


[_qwerty] = LAYOUT_preonic_grid(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_TRNS, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, MO(3), KC_SPC, KC_SPC, MO(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

// [_layer7] = LAYOUT_preonic_grid(
//     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
//     KC_TRNS, QK_BOOT, DB_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TERM_ON, TERM_OFF, GU_ON, GU_OFF, KC_DEL,
//     KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, RGB_MOD, DF(0), DF(5), DF(6), KC_RCTL,
//     KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, RGB_RMOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_SPI,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_SPD
// ),

[_mouse] = LAYOUT_preonic_grid(
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    QK_RBT, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};
