/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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

//Audio
#undef AUDIO_VOICES
#undef AUDIO_PIN
#define AUDIO_PIN A5
#define AUDIO_PIN_ALT A4
#define AUDIO_PIN_ALT_AS_NEGATIVE


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#define AUDIO_CLICKY
  /* to enable clicky on startup */
  //#define AUDIO_CLICKY_ON
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
#endif

// configure oled driver for the 128x32 oled
#define OLED_UPDATE_INTERVAL 33 // ~30fps

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Haptic Driver initialization settings
 * Feedback Control Settings */
#define FB_ERM_LRA 1 /* For ERM:0 or LRA:1*/
#define FB_BRAKEFACTOR 6 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* default 3V ERM vibration motor voltage and library*/
#if FB_ERM_LRA == 0
#define RATED_VOLTAGE 3
#define V_RMS 2.3
#define V_PEAK 3.30
/* Library Selection */
#define LIB_SELECTION 4 /* For Empty:0' TS2200 library A to D:1-5, LRA Library: 6 */

/* default 2V LRA voltage and library */
#elif FB_ERM_LRA == 1
#define RATED_VOLTAGE 2
#define V_RMS 2.0
#define V_PEAK 2.85
#define F_LRA 200
/* Library Selection */
#define LIB_SELECTION 6 /* For Empty:0' TS2200 library A to D:1-5, LRA Library: 6 */

#endif

/* Control 1 register settings */
#define DRIVE_TIME 25
#define AC_COUPLE 0
#define STARTUP_BOOST 1

/* Control 2 Settings */
#define BIDIR_INPUT 1
#define BRAKE_STAB 1 /* Loopgain is reduced when braking is almost complete to improve stability */
#define SAMPLE_TIME 3
#define BLANKING_TIME 1
#define IDISS_TIME 1

/* Control 3 settings */
#define NG_THRESH 2
#define ERM_OPEN_LOOP 1
#define SUPPLY_COMP_DIS 0
#define DATA_FORMAT_RTO 0
#define LRA_DRIVE_MODE 0
#define N_PWM_ANALOG 0
#define LRA_OPEN_LOOP 0
/* Control 4 settings */
#define ZC_DET_TIME 0
#define AUTO_CAL_TIME 3

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE

#define RGB_MATRIX_LED_COUNT 10

// #define RGB_MATRIX_KEYPRESSES

#define SOLENOID_PIN A14
