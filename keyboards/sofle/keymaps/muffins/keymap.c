 /* Copyright 2021 Nick Anderson
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    // [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
};
#endif

/* 32 * 14 os logos */
static const char PROGMEM win_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM mac_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

enum sofle_layers {
    _DEFAULT = 0,
    _WINDOWS = 0,
    _MACOS,
    _MOD,
};

enum custom_keycodes {
    KC_WINDOWS = SAFE_RANGE,
    KC_MACOS,
	KC_MOD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Windows Mode
 * ,-----------------------------------------.                    ,---------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Bspc    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '       |
 * |------+------+------+------+------+------| Next  |    | Stop  |------+------+------+------+------+----------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Ctl+Cmd+Q|
 * `-----------------------------------------/       /     \      \---------------------------------------------'
 *            |TO(1) | LAlt | MO(1)| LGUI | /Del    /       \Enter \  |Space |   =  |  [   |   ]  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_WINDOWS] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,     KC_3,     KC_4,  KC_5,                          KC_6,   KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,  KC_T,                          KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSLS,
  KC_LSFT,  KC_A,    KC_S,     KC_D,     KC_F,  KC_G,                          KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,    KC_X,     KC_C,     KC_V,  KC_B, KC_MNXT,      KC_MSTP,   KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, LGUI(KC_L),
            KC_MACOS,   KC_LALT,  MO(2), KC_LGUI, KC_DEL,                    KC_ENT, KC_SPC,   KC_EQL,  KC_LBRC, KC_RBRC
),

/*
 * macOS mode
 * ,-----------------------------------------.                    ,---------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Bspc    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '       |
 * |------+------+------+------+------+------| Next  |    | Stop  |------+------+------+------+------+----------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Ctl+Cmd+Q|
 * `-----------------------------------------/       /     \      \---------------------------------------------'
 *            |TO(1) | LAlt | MO(1)| LGUI | /Del    /       \Enter \  |Space |   =  |  [   |   ]  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_MACOS] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,     KC_3,     KC_4,  KC_5,                               KC_6,   KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,  KC_T,                               KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSLS,
  KC_LSFT,  KC_A,    KC_S,     KC_D,     KC_F,  KC_G,                               KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,    KC_X,     KC_C,     KC_V,  KC_B, KC_MNXT,           KC_MSTP,   KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, LCTL(LGUI(KC_Q)),
            KC_WINDOWS,   KC_LALT,  MO(2), KC_LGUI, KC_DEL,          KC_ENT, KC_SPC,   KC_EQL,  KC_LBRC, KC_RBRC
),

/* MOD
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |       |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG| hue+ | sat+ | bri+ | PgDwn| PgUp |                    | Prev | Play | Next |      |      | F12  |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBmode| hue- | sat- | bri- | Home | End  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------|    |-------|   -  |  `   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |       |
 *            `----------------------------------'            '------''----------------------------'
 */
[_MOD] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,                         KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_PGDN,   KC_PGUP,                       KC_MPRV, KC_MPLY, KC_MNXT,   _______,  _______, KC_F12,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_HOME,   KC_END,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______,   _______, _______,     _______, KC_MINUS, KC_GRAVE, _______, _______,  _______, _______,
                    _______, _______, _______,   _______, _______,     _______, _______,  _______,  _______, _______
),
};


#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {

    // Print current mode
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _WINDOWS:
            oled_write_raw_P(win_logo, sizeof(win_logo));
            oled_write_ln_P(PSTR("win"), false);
            break;
        case _MACOS:
            oled_write_raw_P(mac_logo, sizeof(mac_logo));
            oled_write_ln_P(PSTR("mac"), false);
            break;
        case _MOD:
            oled_write_P(PSTR("\n\n"), false);
            oled_write_ln_P(PSTR("mod"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _WINDOWS:
        case _MACOS:
            oled_write_P(PSTR("Base"), false);
            break;
        case _MOD:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_WINDOWS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WINDOWS);
            }
            return false;
        case KC_MACOS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACOS);
            }
            return false;
        case KC_MOD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOD);
            }
            return false;
    }
    return true;
}

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
// 		} else if (index == 1) {
//         if (clockwise) {
//           tap_code(KC_PGDN);
//         } else {
//           tap_code(KC_PGUP);
//         }
//     }
//     return true;
// }
// #endif
