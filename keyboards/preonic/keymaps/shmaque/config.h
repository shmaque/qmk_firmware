#pragma once

// comment out for black keeb - for blue/silver limit pallette
#undef RGBLIGHT_RAINBOW_HUE_MIN
#undef RGBLIGHT_RAINBOW_HUE_MAX
#define RGBLIGHT_RAINBOW_HUE_MIN 115
#define RGBLIGHT_RAINBOW_HUE_MAX 175

#ifdef AUDIO_ENABLE
    // Tempos are a bit quick on the new builds...
    #undef TEMPO_DEFAULT
    #define TEMPO_DEFAULT 120
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
