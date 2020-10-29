#include QMK_KEYBOARD_H

enum planck_layers
{
   _QWERTY = 0,
   _RFU1,
   _LOWER,
   _RAISE,
   _NUMPAD,
   _FN,
   _RANDOM
};

enum custom_keycodes
{
   TC_SHCAPS = SAFE_RANGE, // Approximates LSFT_T(KC_CAPSLOCK)
   TC_LSPC,
   TC_RSPC
};

// This could be moved to config.h; hold duration for surrogate MT() handlers
#define MOM_TAP_HOLD_MS 200

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Primary layer (QWERTY)
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | Alt  | GUI  |  Fn  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
   [_QWERTY] = LAYOUT_ortho_4x12(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
      KC_LCTL, KC_LALT, KC_LGUI, MO(_FN), MO(_LOWER), TC_LSPC, TC_RSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
   ),
   /* Unused/RFU, trans to allow fall throughs to work right */
   [_RFU1] = LAYOUT_ortho_4x12(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Lower (Numrow, etc...) 
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | NumPd|      |      |      |      |      |      |      |   ,  |   .  |      | TRNS |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     | MO(6)| TRNS | TRNS | TRNS | TRNS |
    * `-----------------------------------------------------------------------------------'
    */
   [_LOWER] = LAYOUT_ortho_4x12(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
      MO(_NUMPAD), KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  KC_NO,   KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RANDOM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Raise (symbols/shift keys, etc...)
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS |   (  |   {  |   }  |   )  |      |   -  |   +  |      |   [  |   ]  |   \  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |   [  |   ]  |      |      |   _  |   =  |      |   {  |   }  | TRNS |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS | TRNS | MO(6)|    TRNS     | TRNS | TRNS | TRNS | TRNS | TRNS |
    * `-----------------------------------------------------------------------------------'
    */
   [_RAISE] = LAYOUT_ortho_4x12(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
      KC_TRNS, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_NO,   KC_MINS, KC_PLUS, KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, 
      KC_LSFT, KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_UNDS, KC_EQL,  KC_NO,   KC_LCBR, KC_RCBR, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RANDOM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   ),
   /* Numpad Layer
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |   7  |   8  |   9  |  -   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |   4  |   5  |   6  |  +   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      | NumLk|   =  |   1  |   2  |   3  | ENT  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TRNS | TRNS | TRNS | TRNS |      |    TRNS     |      |   0  |   0  |   .  |  *   |
    * `-----------------------------------------------------------------------------------'
    */
   [_NUMPAD] = LAYOUT_ortho_4x12(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS, 
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NLCK, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_P0,   KC_P0,   KC_PDOT, KC_PAST
   ),
   /* Fn layer (F keys, pgupdown/etc...)
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F11 |  F12 |      |      |      |      |      | PrSc | ScLk | Pause|  Ins |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Sh/Cps|      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Home | PgUp | PgDn | End  |
    * `-----------------------------------------------------------------------------------'
    */
   [_FN] = LAYOUT_ortho_4x12(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, 
      KC_NO,   KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, 
      /*LSFT_T(KC_CAPSLOCK),*/
      TC_SHCAPS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END
   ),
   /* Goofy stuff (debug/reset/random stuff I never use
    * ,-----------------------------------------------------------------------------------.
    * | Reset|      |      |      |      |      |      |      |      | Brt- | Brt+ | Debug|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |TermOn|TermOf|      | AuOn | AuOff|      |      | DF(0)| DF[2)| DF(3)| DF(4)|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      | AgSwp| AgNrm|      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
   [_RANDOM] = LAYOUT_ortho_4x12(
      RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_BRIU, DEBUG, 
      TERM_ON, TERM_OFF,KC_NO,   AU_ON,   AU_OFF,  KC_NO,   KC_NO,   DF(_QWERTY), DF(_LOWER), DF(_RAISE), DF(_NUMPAD), KC_NO, 
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   AG_SWAP, AG_NORM, KC_NO,   KC_NO,   KC_NO,   KC_NO, 
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
   )
#if 0
   [6] = LAYOUT_ortho_4x12(
      KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, 
      KC_TRNS, KC_TRNS, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   DF(1),   DF(2),   TO(5),   KC_TRNS, 
      KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
   )
#endif
};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
   // Mask vars for two-keyed spacebar boards(e.g. planck rev4)
   static bool ls_masked = false;
   static bool rs_masked = false;

   // Temp timer starting value
   static uint16_t shcaps_time_start;

   switch(keycode) {
      // Handle what LSFT_T(KC_CAPSLOCK) _should_ be doing... but actually do it reliably
      case TC_SHCAPS:
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

      // Handle left/right center shift keys masked to one pseudo-event
      case TC_LSPC:
         if(!ls_masked) {
            if(record->event.pressed) {
               rs_masked = true;
               register_code(KC_SPC);
            }
            else {
               rs_masked = false;
               unregister_code(KC_SPC);
            }
         }
         break;
      case TC_RSPC:
         if(!rs_masked) {
            if(record->event.pressed) {
               ls_masked = true;
               register_code(KC_SPC);
            }
            else {
               ls_masked = false;
               unregister_code(KC_SPC);
            }
         }
         break;
      default:
         // Do nothing for all other keys
         break;
   }
   return true;
}
