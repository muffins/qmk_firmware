// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |               |   Increase Brightness  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Hue Cycle |
     */
    [0] = LAYOUT(
        MO(1)  , RGB_VAI, KC_MUTE,
        RGB_MOD, RGB_VAD, RGB_HUI
    ),
    
    /*
        |                  |          | Knob 2: Vol Up/Dn |
        |  Toggle Layer 1  |    Up    |    Press: Mute    |
        |      Left        |   Down   |      Right        |
     */
    [1] = LAYOUT(
        _______, KC_MYCM, KC_MUTE,
        KC_MPRV , KC_MPLY  , KC_MNXT
    ),
};
