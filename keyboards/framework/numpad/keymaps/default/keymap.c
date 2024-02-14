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
     *         └─────────┴────┴────┴
     * 21 total
     */
    [_NUMLOCK] = LAYOUT(
        KC_ESC,  KC_CALC, KC_EQL,  KC_BSPC,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
            KC_P0,        KC_PDOT, KC_ENT
    ),
};

bool led_update_user(led_t led_state) {
    // Change layer if numlock state changes, either triggered by OS or
    // by numlock key on this keyboard
    if (led_state.num_lock) {
        backlight_level_noeeprom(2);
    } else {
        backlight_level_noeeprom(1);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t escape_key_timer = 0;
    static bool escape_other_key_recorded = false;  // track if any key other than ESC has been pressed
    if (keycode != KC_ESC) { escape_other_key_recorded = true; }

    switch (keycode) {
        case KC_ESC:
            if (record->event.pressed) {
                escape_key_timer = timer_read();
                escape_other_key_recorded = false;  // start tracking other keys
            } else {
                if (!escape_other_key_recorded) {  // only go to bootloader if no other key has been pressed
                    if (timer_elapsed(escape_key_timer) >= 5000) {
                        bootloader_jump();
                    }
                }
                escape_key_timer = 0;  // reset timer counter on release so it can be used for tracking if ESC is pressed
            }
            break;

        default:
            break;
    }

    return true;
}
