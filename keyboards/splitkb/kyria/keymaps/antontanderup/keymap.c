/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include <oledstuff.h>

enum layers {
    _QWERTY = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_CUT LCTL(KC_X)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))

#define EMOJI LCTL(LGUI(KC_SPACE))
#define CHANGE_LANGUAGE LGUI(KC_SPACE)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT(
                                                            _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEFT_BRACKET,
     _______, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G,                                        KC_H, MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN),  KC_QUOTE,
                                        KC_MS_BTN2, MT(MOD_LCTL, KC_Z), KC_X, KC_C, KC_V, KC_B, EMOJI, KC_F13,                     KC_MS_BTN1, KC_MS_BTN2, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, CHANGE_LANGUAGE,
                                     _______, LT(_ADJUST, RGB_TOG), LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPACE), LT(_MOUSE, KC_TAB),                  LT(_SYM, KC_ENTER), LT(_NUM, KC_BACKSPACE), LT(_FUN, KC_DELETE), CG_TOGG, _______
    ),

 /*
 * Nav Layer: Navigation
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_REDO, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, _______ ,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INSERT, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer: Mousing
*/
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_AGAIN, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, _______ ,
      _______, _______, _______, _______, _______, _______,                                      KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, _______, _______
    ),

/*
 * Media Layer: Media controls
 */
    [_MEDIA] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, _______, _______
    ),

/*
 * Num layer: Numbers and some symbols
 */
    [_NUM] = LAYOUT(
      _______, KC_LEFT_BRACKET,  KC_7, KC_8, KC_9, KC_RIGHT_BRACKET,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_SEMICOLON, KC_4, KC_5, KC_6, KC_EQUAL,                                    _______, _______, _______, _______, _______, _______,
      _______, KC_GRAVE, KC_1, KC_2, KC_3, KC_BACKSLASH, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                                 _______, _______, KC_DOT, KC_0, KC_MINUS, _______, _______, _______, _______, _______
    ),


/*
 * Symbols layer: Symbols
 */
    [_SYM] = LAYOUT(
      _______, KC_LEFT_CURLY_BRACE, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_CURLY_BRACE,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_COLON, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_PLUS,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_UNDERSCORE, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 */
    [_FUN] = LAYOUT(
      _______, KC_F12,  KC_F7 ,  KC_F8,  KC_F9, KC_PRINT_SCREEN,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F11, KC_F4 ,  KC_F5 ,  KC_F6  , KC_SCROLL_LOCK,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F10,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_PAUSE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, KC_APPLICATION, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______ , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, RGB_M_G, RGB_M_X , RGB_M_TW, RGB_M_P	,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_mods_layer(void) {

    render_bottom_background();

    uint8_t mod = get_mods();

    if ((mod & MOD_BIT(KC_LSFT)) || (mod & MOD_BIT(KC_RSFT))) {
        render_shift();
    }

    if ((mod & MOD_BIT(KC_LGUI)) || (mod & MOD_BIT(KC_RGUI))) {
        render_gui();
    }

    if ((mod & MOD_BIT(KC_LALT)) || (mod & MOD_BIT(KC_RALT))) {
        render_alt();
    }

    if ((mod & MOD_BIT(KC_LCTL)) || (mod & MOD_BIT(KC_RCTL))) {
        render_ctrl();
    }
}

bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _NUM:
                render_top_num();
                render_mods_layer();
                break;
            case _SYM:
                render_top_sym();
                render_mods_layer();
                break;
            case _FUN:
                oled_write_P(PSTR("F12 F7 F8 F9 PrtSc\n\n"), false);
                oled_write_P(PSTR("F11 F4 F5 F6 ScrLk\n\n"), false);
                oled_write_P(PSTR("F10 F1 F2 F3 Pause\n\n"), false);
                oled_write_P(PSTR("\n\n"), false);
                break;
            case _NAV:
                render_top_nav();
                render_mods_layer();
                break;
            default:
                render_top_home();
                render_mods_layer();
        }
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // RIGHT SIDE ENCODER
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _MEDIA:
            case _MOUSE:
            case _QWERTY:
            case _NUM:
            case _SYM:
            case _FUN:
            case _ADJUST:
            case _NAV:
            default:
                // Redo and undo
                if (clockwise) {
                    tap_code16(LGUI(LSFT(KC_Z)));
                } else {
                    tap_code16(LGUI(KC_Z));
                }
        }
    } else if (index == 1) {
        // RIGHT SIDE ENCODER
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _MEDIA:
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _MOUSE:
            case _QWERTY:
            case _NUM:
            case _SYM:
            case _FUN:
            case _ADJUST:
            case _NAV:
            default:
                // Page up/Page down
                if (clockwise) {
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                }
        }
    }
    return false;
}
#endif
