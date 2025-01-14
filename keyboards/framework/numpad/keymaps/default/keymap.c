// Copyright 2022-2023 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     *         ┌────┬────┬────┬────┐
     *  4 keys │Esc │Calc│ =  │ <- │
     *         ├────┼────┼────┼────┤
     *  4 keys │ Num│ /  │ *  │ -  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 7  │ 8  │ 9  │    │
     *         ├────┼────┼────┤    │
     *  4 keys │ 4  │ 5  │ 6  │ +  │
     *         ├────┼────┼────┼────┤
     *  3 keys │ 1  │ 2  │ 3  │    │
     *         ├────┴────┼────┤    │
     *  3 keys │ 0       │ .  │Entr│
     *         └─────────┴────┴────┘
     * 21 total
     */
    [_NUMLOCK] = LAYOUT(
        KC_ESC,  KC_CALC, KC_PEQL, KC_BSPC,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT, KC_ENT
    ),

     /*
     * Extra keys for when numlock is disabled.
     * Numlock keys are passed through to the number layer,
     * and automatically remapped by the OS.
     *         ┌────┬────┬────┬────┐
     *  4 keys │Esc │PScr│MicM│Mute│
     *         ├────┼────┼────┼────┤
     *  4 keys │ Num│Bck-│Bck+│Vol-│
     *         ├────┼────┼────┼────┤
     *  3 keys │Home│ ↑  │PgUp│    │
     *         ├────┼────┼────┤    │
     *  4 keys │ ←  │    │ →  │Vol+│
     *         ├────┼────┼────┼────┤
     *  3 keys │End │ ↓  │PdDn│    │
     *         ├────┴────┼────┤    │
     *  3 keys │ Insert  │Del │Entr│
     *         └─────────┴────┴────┘
     * 21 total
     */
    [_FN] = LAYOUT(
        KC_ESC,  S(KC_PRINT_SCREEN), KC_F20,  KC_MUTE,
        KC_NUM,  KC_BRID, KC_BRIU, KC_VOLD,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_VOLU,
        KC_P1,   KC_P2,   KC_P3,
        KC_INS,  KC_DEL,  KC_ENT
    ),
};


bool led_update_user(led_t led_state) {
    if (led_state.num_lock) {
        layer_off(_FN);
        backlight_level_noeeprom(2);
    } else {
        layer_on(_FN);
        backlight_level_noeeprom(1);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t bootloader_key_timer = 0;
    static bool bootloader_other_key_recorded = false;  // track if any key other than NumLock has been pressed
    if (keycode != KC_NUM) { bootloader_other_key_recorded = true; }

    switch (keycode) {

        case KC_NUM:  // enter bootloader if NumLock is held for 5 seconds
            if (record->event.pressed) {
                bootloader_key_timer = timer_read();
                bootloader_other_key_recorded = false;  // start tracking other keys
            } else {
                if (!bootloader_other_key_recorded) {  // only go to bootloader if no other key has been pressed
                    if (timer_elapsed(bootloader_key_timer) >= 5000) {
                        bootloader_jump();
                    }
                }
                bootloader_key_timer = 0;  // reset timer counter on release so it can be used for tracking if NumLock is pressed
            }
            break;

        default:
            break;
    }

    return true;
}
