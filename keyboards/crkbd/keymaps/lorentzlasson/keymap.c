/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include <stdio.h>

// Layers
enum layers {
    _QWERTY = 0,
    _SYM,
    _SYS,
    _F
};

// all modifiers should be modtap!
#define KC_MYENT  MT(MOD_LALT, KC_ENT)
#define KC_MYSYM  LT(_SYM, KC_TAB)
#define KC_MYSPC  MT(MOD_LCTL, KC_SPC)
#define KC_MYBSPC MT(MOD_LCTL, KC_BSPC)
#define KC_MYALT  MT(MOD_LALT, KC_TAB)
#define KC_MYCAPS LT(_F, KC_CAPS)
#define KC_TMUX   LCTL(KC_SPC)
#define KC_MYTAB  LT(_SYS, KC_TAB)

// Fillers to make layering more clear
#define _______ KC_TRANSPARENT
#define XXXXXXX KC_NO

#define KC_AU ALGR(KC_W) // å
#define KC_AE ALGR(KC_Q) // ä
#define KC_OE ALGR(KC_P) // ö

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * | Tab    |   Q  |   W  |  E   |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |  D   |   F  |   G  |                |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |  C   |   V  |   B  |                |   N  |   M  | ,  < | . >  | /  ? | Shift  |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               | Tmux | Tab  | Bspc |  | Space| Enter| SUPER|
 *                               |      | SYM  | Ctrl |  | Ctrl | Alt  |      |
 *                               ---------------------'  `---------------------
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
     KC_MYTAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,            KC_Y,  KC_U,  KC_I,      KC_O,    KC_P,      KC_AU,
     KC_MYCAPS,KC_A,  KC_S,  KC_D,  KC_F,  KC_G,            KC_H,  KC_J,  KC_K,      KC_L,    KC_OE,     KC_AE,
     KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,            KC_N,  KC_M,  KC_COMMA,  KC_DOT,  KC_SLASH,  KC_LSFT,
                        KC_TMUX,KC_MYSYM,KC_MYBSPC,      KC_MYSPC,KC_MYENT,KC_LGUI
  ),

/*
 * Symbol layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |   `    |  !   |  @   |  {   |  }   |  &   |                |  *   |  7   |  8   |  9   |  +   |  =     |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |   ~    |  ^   |  $   |  (   |  )   |  '   |                |  ;   |  4   |  5   |  6   |  -   |  _     |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |   |    |  #   |  %   |  [   |  ]   |  "   |                |  :   |  1   |  2   |  3   |  \   | Del    |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               |      |      |      |  |      |  0   |      |
 *                               |      |      |      |  |      |      |      |
 *                               ----------------------  ----------------------
 */

  [_SYM] = LAYOUT_split_3x6_3(
     KC_GRAVE, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,            KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_EQL,
     KC_TILD,  KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_QUOT,            KC_SCLN, KC_4, KC_5, KC_6, KC_MINS, KC_UNDS,
     KC_PIPE,  KC_HASH, KC_PERC, KC_LBRC, KC_RBRC, KC_DQUO,            KC_COLN, KC_1, KC_2, KC_3, KC_BSLS, KC_DELETE,
                                  _______, _______, _______,        _______, KC_0, _______
  ),

/*
 * System layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                | LEFT | DOWN |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                |      |      |      |      |      | PrtSc  |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |      |  |      |      |      |
 *                               ----------------------  ----------------------
 */

  [_SYS] = LAYOUT_split_3x6_3(
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    _______,    _______,    _______,    _______,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    _______,    _______,    _______,    _______,   KC_PSCR,
                                                    _______, _______, _______,        _______, _______, _______
  ),

/*
 * F layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        |      |      |      |      |      |                |      |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                |      |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                |      |  F1  |  F2  |  F3  |  F12 |        |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |      |  |      |      |      |
 *                               ----------------------  ----------------------
 */

  [_F] = LAYOUT_split_3x6_3(
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    KC_F4,    KC_F5,    KC_F6,    KC_F11,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    KC_F1,    KC_F2,    KC_F3,    KC_F12,   _______,
                                                    _______, _______, _______,        _______, _______, _______
  )

};
