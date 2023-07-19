/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_LED_MAP \
        { 0, 1, 2, 9, 8, 7, 4, 3, 5, 6, 19, 18, 17, 10, 11, 12, 15, 16, 14, 13 }
#    undef RGBLIGHT_EFFECT_BREATHING
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_SNAKE
#    undef RGBLIGHT_EFFECT_KNIGHT
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#    undef RGBLIGHT_EFFECT_RGB_TEST
#    undef RGBLIGHT_EFFECT_ALTERNATING
// #undef RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

#define SPLIT_WPM_ENABLE

#define ENCODER_RESOLUTION 2

#define OLED_BRIGHTNESS 20
// #define OLED_TIMEOUT 5000
