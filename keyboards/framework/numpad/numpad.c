// Copyright 2023 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "numpad.h"

void keyboard_post_init_user(void) {
    // Sync initial numlock state from the host
    layer_on(_NUMLOCK);
    if (host_keyboard_led_state().num_lock) {
        backlight_level_noeeprom(2);
    } else {
        backlight_level_noeeprom(1);
    }
}
