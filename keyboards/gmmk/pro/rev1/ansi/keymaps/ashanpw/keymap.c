/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

enum userspace_layers {
  QWERTY,
	FNLAYER,
	POPTAB,
};

//custom keycodes
#define MODS_ALT_MASK (MOD_BIT(KC_LALT)) // Make ALT layer for encoder use
#define MODS_CTRL_MASK (MOD_BIT(KC_LCTL)) // Make CTRL layer for encoder use
#define SWAP_L SGUI(KC_LEFT) // Swap application to left display
#define SWAP_R SGUI(KC_RGHT) // Swap application to right display
#define MINI LGUI(KC_DOWN) // Shrink window
#define MAXI LGUI(KC_UP) // Maximize window
#define CLOSEAPPLICATION LALT(KC_F4) // Kill application
#define CLOSETAB LCTL(KC_W) // Kill current tab
#define POPOUT LCTL(LSFT(KC_K))

enum custom_keycodes {
    KC_CUSTOM_Q = SAFE_RANGE,  // Define custom keycode
    KC_CUSTOM_W,  
    KC_CUSTOM_E,  
    KC_CUSTOM_R,  
    // Other custom keycodes if needed
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    [QWERTY] = LAYOUT(
        KC_ESC,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                KC_MUTE,
        KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,                KC_MNXT,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                KC_VOLU,
        MO(FNLAYER), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                 KC_VOLD,
        KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,                  KC_VOLD,
        KC_LCTL,     KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(FNLAYER),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [FNLAYER] = LAYOUT(
        CLOSEAPPLICATION, CLOSETAB, _______,     _______,     _______,     _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_MNXT,
        KC_ESC,  _______,           _______,     _______,     _______,     _______, _______, _______, _______, _______,  _______, _______, _______, _______,          KC_VOLU,
        _______, KC_CUSTOM_Q,       KC_CUSTOM_W, KC_CUSTOM_E, KC_CUSTOM_R, _______, _______, KC_HOME, KC_UP,   KC_END,   KC_DEL,  _______, _______, QK_BOOT,          KC_MEDIA_PLAY_PAUSE,
        _______, _______,           MINI  ,      _______,     KC_LCTL,     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,          _______,         KC_VOLD,
        _______,                    _______,     _______,     KC_CAPS,     _______, _______, _______, _______, _______,  _______, _______,          _______, _______, _______,
        _______, _______,           _______,                            _______,                               _______, _______,  KC_TRNS, _______, _______, _______
    ),     


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CUSTOM_Q:
            // Handle custom shift key behavior
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("q"));
            }
            break;
        case KC_CUSTOM_W:
            // Handle custom shift key behavior
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("w"));
            }
            break;
        case KC_CUSTOM_E:
            // Handle custom shift key behavior
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("e"));
            }
            break;
        case KC_CUSTOM_R:
            // Handle custom shift key behavior
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("r"));
            }
            break;
    }
    return true; // Process other keycodes normally
}



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_mods() & MODS_ALT_MASK) {
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if (get_mods() & MODS_CTRL_MASK) {
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if(IS_LAYER_ON(FNLAYER)) {
        if (clockwise) {
            tap_code(KC_MEDIA_NEXT_TRACK);
        } else {
            tap_code(KC_MEDIA_PREV_TRACK);
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t LED_LIST[] = { 67, 68, 70, 71, 73, 74, 76, 77, 80, 81, 83, 84, 87, 88, 91, 92};
    switch(get_highest_layer(layer_state)) {
    // special handling per layer
        case 0:  //layer one
            if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color(3, 255, 255 ,255);
            } else  {
                rgb_matrix_set_color_all(0,0,0);
                
                for (uint8_t i = 0; i < 16 ; i++) {
                    rgb_matrix_set_color(LED_LIST[i], 255, 255 ,255);
                }
            }
            break;
        case 1:
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i,0,0,0);
            }
            for (uint8_t i = 0; i < 16 ; i++) {
                rgb_matrix_set_color(LED_LIST[i], 255, 255 ,255);
            }
            RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 20, 20) //esc
            RGB_MATRIX_INDICATOR_SET_COLOR(8, 60, 60, 255) //q
            RGB_MATRIX_INDICATOR_SET_COLOR(14, 60, 60, 255) //w
            RGB_MATRIX_INDICATOR_SET_COLOR(20, 60, 60, 255) //e
            RGB_MATRIX_INDICATOR_SET_COLOR(25, 60, 60, 255) //r
            RGB_MATRIX_INDICATOR_SET_COLOR(42, 60, 60, 255) //j
            RGB_MATRIX_INDICATOR_SET_COLOR(46, 60, 60, 255) //i
            RGB_MATRIX_INDICATOR_SET_COLOR(47, 60, 60, 255) //k
            RGB_MATRIX_INDICATOR_SET_COLOR(53, 60, 60, 255) //l

            break;
        default:
            break;
    }
    return false;
}
