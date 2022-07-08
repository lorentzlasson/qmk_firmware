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
    _ADJUST
};

// all modifiers should be modtap!
#define KC_MYENT  LT(_SYS, KC_ENT)
#define KC_MYSYM  LT(_SYM, KC_TAB)
#define KC_MYSPC  MT(MOD_LCTL, KC_SPC)
#define KC_MYBSPC MT(MOD_LCTL, KC_BSPC)
#define KC_MYALT  MT(MOD_LALT, KC_TAB)
#define KC_MYGUI  KC_LGUI
#define KC_MYTAB  LT(_SYS, KC_TAB)

// Fillers to make layering more clear
#define _______ KC_TRANSPARENT
#define XXXXXXX KC_NO

// Swedish keybord special signs
#define KC_ARING KC_LBRC
#define KC_OUML KC_SCLN
#define KC_AUML KC_QUOT
#define KC_SE_SLSH S(KC_7)
#define KC_SE_AT RALT(KC_2)
#define KC_SE_AMPR S(KC_6)
#define KC_SE_LPRN S(KC_8)
#define KC_SE_RPRN S(KC_9)
#define KC_SE_QUOT KC_BSLS
#define KC_SE_DQUO S(KC_2)
#define KC_SE_DLR RALT(KC_4)
#define KC_SE_LCBR S(RALT(KC_8))
#define KC_SE_RCBR S(RALT(KC_9))
#define KC_SE_LBRC RALT(KC_8)
#define KC_SE_RBRC RALT(KC_9)
#define KC_SE_EQL S(KC_0)
#define KC_SE_GBP RALT(KC_3)
#define KC_SE_TILD RALT(KC_RBRC)
#define KC_SE_EURO RALT(KC_E)
#define KC_SE_AA KC_LBRC
#define KC_SE_OE KC_SCLN
#define KC_SE_AE KC_QUOT
#define KC_SE_PLAYP KC_MEDIA_PLAY_PAUSE
#define KC_SE_MUTE KC_AUDIO_MUTE
#define KC_SE_CIRC KC_RCBR
#define KC_SE_PARA KC_GRAVE
#define KC_SE_HALF KC_TILD
#define KC_SE_ACUT KC_EQL
#define KC_SE_GRAV KC_PLUS
#define KC_SE_GT S(KC_GRV)
#define KC_SE_LT KC_GRV
#define KC_SE_PLUS KC_MINS
#define KC_SE_ASTR KC_PIPE
#define KC_SE_QUES S(KC_MINS)
#define KC_SE_BSLS ALGR(KC_MINUS)
#define KC_SE_PIPE RALT(KC_7)
#define KC_SE_SCLN S(KC_COMM)
#define KC_SE_COLN S(KC_DOT)
#define KC_SE_MINS KC_SLSH
#define KC_SE_UNDS S(KC_SLSH)

enum custom_keycodes {
  SYM = SAFE_RANGE,
  SYS,
  ANSIKEY,
  ANSICOM,
  ANSIDOT,
  MY_SCREENSHOT,
  M_ARROW,
};

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * | Tab    |   Q  |   W  |  E   |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |  D   |   F  |   G  |                |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  | ,  < | . >  | /  ? | Shift  |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               | Super| Tab  | Bspc |  | Space| Enter| Tab  |
 *                               |      | SYM  | Ctrl |  | Ctrl | SYS  | Alt  |
 *                               ---------------------'  `---------------------
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
     KC_MYTAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_ARING,
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_OUML, KC_AUML,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ANSICOM, ANSIDOT, ANSIKEY, KC_LSFT,
                                         KC_MYGUI,KC_MYSYM,KC_MYBSPC,      KC_MYSPC,KC_MYENT,KC_MYALT
  ),

/*
 * Symbol layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |   `    |  !   |  @   |  {   |  }   |  &   |                |  *   |  7   |  8   |  9   |  +   |  =     |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |   ~    |  ^   |  $   |  (   |  )   |  '   |                |  ;   |  4   |  5   |  6   |  -   |  _     |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |   |    |  #   |  %   |  [   |  ]   |  "   |                |  :   |  1   |  2   |  3   |  \   |  ->    |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               |      |      |      |  |      |  0   |  0   |
 *                               |      |      |      |  |      |      |      |
 *                               ----------------------  ----------------------
 */

  [_SYM] = LAYOUT_split_3x6_3(
     KC_SE_GRAV, KC_EXLM,    KC_SE_AT,  KC_SE_LCBR, KC_SE_RCBR, KC_SE_AMPR,                 KC_SE_ASTR, KC_7, KC_8, KC_9, KC_SE_PLUS, KC_SE_EQL,
     KC_SE_TILD, KC_SE_CIRC, KC_SE_DLR, KC_SE_LPRN, KC_SE_RPRN, KC_SE_QUOT,                 KC_SE_SCLN, KC_4, KC_5, KC_6, KC_SE_MINS, KC_SE_UNDS,
     KC_SE_PIPE, KC_HASH,    KC_PERC,   KC_SE_LBRC, KC_SE_RBRC, KC_SE_DQUO,                 KC_SE_COLN, KC_1, KC_2, KC_3, KC_SE_BSLS, M_ARROW,
                                                          _______, _______, _______,  KC_0, KC_0, KC_0
  ),

/*
 * System layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                | LEFT | DOWN |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+  +------+------+------+------+----------------------'
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |      |  |      |      |      |
 *                               ----------------------  ----------------------
 */

  [_SYS] = LAYOUT_split_3x6_3(
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    _______,    _______,    _______,    _______,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,   _______,
     _______,    _______,    _______,    _______,    _______,    _______,                   _______,    _______,    _______,    _______,    _______,   _______,
                                                    _______, _______, _______,        _______, _______, _______
  )


};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

// Handle ANSI keys - from johannes-jansson
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t shift_pressed = get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
  // uint8_t alt_pressed = get_mods() & ((MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)));

  switch (keycode) {
    case ANSIKEY: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_MINS);
        } else {
          register_code(KC_LSHIFT);
          register_code(KC_7);
          unregister_code(KC_LSHIFT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_MINS);
        } else {
          unregister_code(KC_7);
        }
      return false;
    }
    case ANSICOM: {
      if (record->event.pressed)
        if(shift_pressed) {
          unregister_code(KC_LSHIFT);
          register_code(KC_GRV);
          register_code(KC_LSHIFT);
        } else {
          register_code(KC_COMM);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_COMM);
        }
      return false;
    }
    case ANSIDOT: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_GRV);
        } else {
          register_code(KC_DOT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_DOT);
        }
      return false;
    }
    case MY_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT(SS_TAP(X_4)))));
      }
      return false;
      break;
    case M_ARROW:
      if (record->event.pressed) {
        SEND_STRING("/" SS_LSFT("`")); // ->
      }
      return false;
      break;
    // The following handle layer switching
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
  }
  return true;
}
#endif // OLED_ENABLE
