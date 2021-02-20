#include QMK_KEYBOARD_H

enum preonic_layers
{
   _QWERTY = 0,
   _RFU1,
   _LOWER,
   _RAISE,
   _NUMPAD,
   _FN,
   _RANDOM
};

enum preonic_keycodes
{
   TC_SCAPS = SAFE_RANGE, // Approximates LSFT_T(KC_CAPSLOCK)
   // Layers
//    LY_LWR,
//    LY_RSE,
//    LY_FN,
//    LY_NUMP,
      // Unicode stuff
   UC_FLIP,
   UC_TABL,
   UC_SHRG,
   UC_DISA,
   // placeholder for any future codes
   NEW_SAFE_RANGE
};
// Layer defs (when not using enums)
#define LY_LWR  MO(_LOWER)
#define LY_RSE  MO(_RAISE)
#define LY_FN   MO(_FN)
#define LY_NUMP MO(_NUMPAD)

#define USE_TRI_LAYER_STATE

// This could be moved to config.h; hold duration for surrogate MT() handlers
#define MOM_TAP_HOLD_MS 200

#ifdef RGBLIGHT_ENABLE
#define DEFAULT_RGBLIGHT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
// Allow macro to read current RGB settings
//extern rgblight_config_t rgblight_config;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Primary layer (QWERTY)
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +=  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | Alt  | GUI  |  Fn  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
   [_QWERTY] = LAYOUT_ortho_5x12(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_LCTL, KC_LALT, KC_LGUI, LY_FN,   LY_LWR,  KC_SPC,  KC_SPC,  LY_RSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
   ),
   /* Unused/RFU, trans to allow fall throughs to work right */
   [_RFU1] = LAYOUT_ortho_5x12(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Lower (Numrow, etc...)
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +=  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | NumPd|      |      |      |      |      |      |      |   ,  |   .  |      | TRNS |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     | RAND | TRNS | TRNS | TRNS | TRNS |
    * `-----------------------------------------------------------------------------------'
    */
   [_LOWER] = LAYOUT_ortho_5x12(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      LY_NUMP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  KC_NO,   KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Raise (symbols/shift keys, etc...)
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  -_  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS |   (  |   {  |   }  |   )  |      |   -  |   +  |      |   [  |   ]  |  \|  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |   [  |   ]  |      |      |   _  |   =  |      |   {  |   }  | TRNS |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS | TRNS | RAND |    TRNS     | TRNS | TRNS | TRNS | TRNS | TRNS |
    * `-----------------------------------------------------------------------------------'
    */
   [_RAISE] = LAYOUT_ortho_5x12(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_TRNS, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_NO,   KC_MINS, KC_PLUS, KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LSFT, KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_UNDS, KC_EQL,  KC_NO,   KC_LCBR, KC_RCBR, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Numpad Layer
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |   7  |   8  |   9  |   -  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      | NumLk|   =  |   1  |   2  |   3  | ENT  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS |      |      |    TRNS     |      |   0  |   0  |   .  |   *  |
    * `-----------------------------------------------------------------------------------'
    */
   [_NUMPAD] = LAYOUT_ortho_5x12(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NLCK, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_P0,   KC_P0,   KC_PDOT, KC_PAST
   ),
   /* Fn layer (F keys, pgupdown/etc...)
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F11 |  F12 |      |      |      |      |      | PrSc | ScLk | Pause|  Ins |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Sh/Cps| FLIP | TABL | SHRG | DISA |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Home | PgUp | PgDn | End  |
    * `-----------------------------------------------------------------------------------'
    */
   [_FN] = LAYOUT_ortho_5x12(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_NO,   KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,
      /*LSFT_T(KC_CAPSLOCK),*/
      TC_SCAPS,UC_FLIP, UC_TABL, UC_SHRG, UC_DISA, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END
   ),
   /* Goofy stuff (debug/reset/random stuff I never use
    * ,-----------------------------------------------------------------------------------.
    * | Reset|      |      |      |      |      |      |      |      | Brt- | Brt+ | Debug|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Reset|      |      |      |      |      |      |      |      | Brt- | Brt+ | Debug|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |TermOn|TermOf|      | AuOn | AuOff|      |      | DF(0)| DF[2)| DF(3)| DF(4)|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | BlMd-| BlMd+| BlH- | BlH+ | BlEn | AgSwp| AgNrm|      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
   [_RANDOM] = LAYOUT_ortho_5x12(
      RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_BRIU, DEBUG,
      RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_BRIU, DEBUG,
      TERM_ON, TERM_OFF,KC_NO,   AU_ON,   AU_OFF,  KC_NO,   KC_NO,   DF(_QWERTY), DF(_LOWER), DF(_RAISE), DF(_NUMPAD), KC_NO,
      KC_NO,   RGB_RMOD,RGB_MOD, RGB_HUD, RGB_HUI, RGB_TOG, AG_SWAP, AG_NORM, KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
   )
};

#ifdef USE_TRI_LAYER_STATE
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _RANDOM);
    return state;
}
#endif // USE_TRI_LAYER_STATE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   // Temp timer starting value
   static uint16_t shcaps_time_start;

   switch (keycode) {
      #ifndef USE_TRI_LAYER_STATE
      // Manual Tri-layer stuff
      case LY_LWR:
         if(record->event.pressed) {
            layer_on(_LOWER);
         } else {
            layer_off(_LOWER);
         }
         update_tri_layer(_LOWER, _RAISE, _RANDOM);
         return false;
         break;
      case LY_RSE:
         if(record->event.pressed) {
            layer_on(_RAISE);
         } else {
            layer_off(_RAISE);
         }
         update_tri_layer(_LOWER, _RAISE, _RANDOM);
         return false;
         break;
      #endif // USE_TRI_LAYER_STATE

      // Handle what LSFT_T(KC_CAPSLOCK) _should_ be doing... but actually do it reliably
      case TC_SCAPS:
         if(record->event.pressed) {
            shcaps_time_start = timer_read();
            register_code(KC_LSFT);
         }
         else {
            unregister_code(KC_LSFT);
            if(timer_elapsed(shcaps_time_start) < MOM_TAP_HOLD_MS) {
               tap_code(KC_CAPSLOCK);
            }
         }
         break;

   // Unicode funny business
   #ifdef UNICODE_ENABLE
      case UC_FLIP:  // (ノಠ痊ಠ)ノ彡┻━┻
         if (record->event.pressed) {
            send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
         }
         break;
      case UC_TABL:  // ┬─┬ノ( º _ ºノ)
         if (record->event.pressed) {
            send_unicode_string("┬─┬ノ( º _ ºノ)");
         }
         break;
      case UC_SHRG:  // ¯\_(ツ)_/¯
         if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
         }
         break;
      case UC_DISA:  // ಠ_ಠ
         if (record->event.pressed) {
            send_unicode_string("ಠ_ಠ");
         }
         break;
   #endif
   }
   return true;
};

// Update LED(s) based on state change (specifically ram-based / non-eeprom abusing)
bool led_update_user(led_t led_state)
{
   #ifdef RGBLIGHT_ENABLE
   static bool caps_on = false;
   // Did caps lock state change?
   if(caps_on != led_state.caps_lock) {
      caps_on = led_state.caps_lock;
      if(caps_on) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_RED); // Set color to red to stick out on caps on
      } else {
        rgblight_mode_noeeprom(DEFAULT_RGBLIGHT_MODE);
      }
   }
   #endif
   return true;
}

#if 0
void matrix_scan_user(void)
{
#ifdef RGBLIGHT_ENABLE
   rgblight_config.raw = eeconfig_read_rgblight();
#endif
}
#endif

void keyboard_post_init_user(void)
{
   // Set the default RGB configuration at power-on (w/o requiring EEPROM)
   #ifdef RGBLIGHT_ENABLE
   rgblight_enable_noeeprom();
   rgblight_mode_noeeprom(DEFAULT_RGBLIGHT_MODE);
   #endif
}
