/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder (index 0)
        if (clockwise) {
            // Action for clockwise rotation (e.g., volume up)
            tap_code(KC_VOLU);
        } else {
            // Action for counter-clockwise rotation (e.g., volume down)
            tap_code(KC_VOLD);
        }
    }
    return true;
}

/*
void encoder_update_user(uint8_t index, bool clockwise) {
    // if (clockwise) {
    //     tap_code(RGB_VAI);
    // } else {
    //     tap_code(RGB_VAD);
    // }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);  
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // if (clockwise) {
        //     tap_code(RGB_VAI);
        // } else {
        //     tap_code(RGB_VAD);
        // }
    }
}
*/