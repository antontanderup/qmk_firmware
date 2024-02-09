/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

enum dilemma_keymap_layers { _QWERTY = 0, _NAV, _MOUSE, _MEDIA, _NUM, _SYM, _FUN, _ADJUST, _GAMING };

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY
     */
    [_QWERTY] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEFT_BRACKET,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G, KC_H, MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOTE,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        EMOJI, MT(MOD_LCTL, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, CHANGE_LANGUAGE,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        LT(_ADJUST, RGB_TOG), LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPACE), LT(_MOUSE, KC_TAB), LT(_SYM, KC_ENTER), LT(_NUM, KC_BACKSPACE), LT(_FUN, KC_DELETE), TG(_GAMING)
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Nav Layer: Navigation
     */
    [_NAV] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, KC_REDO, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INSERT, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Mouse Layer: Mousing
     */
    [_MOUSE] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, KC_AGAIN, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, KC_MS_BTN2, KC_MS_BTN1, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Media Layer: Media controls
     */
    [_MEDIA] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Num layer: Numbers and some symbols
     */
    [_NUM] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_LEFT_BRACKET, KC_7, KC_8, KC_9, KC_RIGHT_BRACKET, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_SEMICOLON, KC_4, KC_5, KC_6, KC_EQUAL, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_GRAVE, KC_1, KC_2, KC_3, KC_BACKSLASH, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_DOT, KC_0, KC_MINUS, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Symbols layer: Symbols
     */
    [_SYM] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_LEFT_CURLY_BRACE, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_CURLY_BRACE, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_COLON, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_PLUS, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_UNDERSCORE, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    /*
     * Function Layer: Function keys
     */
    [_FUN] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_F12, KC_F7, KC_F8, KC_F9, KC_PRINT_SCREEN, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCROLL_LOCK, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUSE, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, KC_APPLICATION, _______, _______, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    [_ADJUST] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, RGB_M_G, RGB_M_X, RGB_M_TW, RGB_M_P, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

    [_GAMING] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LALT,
        // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
        KC_LALT, KC_BSPC, KC_SPC, KC_9, _______, _______, _______, _______
        //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
        ),

};

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    // set_auto_mouse_layer(<mouse_layer>); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}
#endif // POINTING_DEVICE_ENABLEE

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
                if (!clockwise) {
                    tap_code16(KC_REDO);
                } else {
                    tap_code16(KC_UNDO);
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
                if (!clockwise) {
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

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (!is_keyboard_left()) {
        return false;
    }
    render_logo();
    return false;
}
#endif
