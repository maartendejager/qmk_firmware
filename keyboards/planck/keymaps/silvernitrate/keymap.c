#include QMK_KEYBOARD_H
#include "muse.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_alt_esc_active = false;
uint16_t alt_esc_timer = 0;

enum planck_layers {
  _I3,
  _I3_LWR,
  _I3_RSE,
  _CAPSFM,
  _WIN,
  _WIN_LWR,
  _WIN_RSE,
  _CAPSFN,
  _NPFN,
  _STRCFT,
  _USHIFT,
  _USHIFTI3,
  _I3_FN
};

enum planck_keycodes {
  I3 = SAFE_RANGE,
  I3_LWR,
  I3_RSE,
  CAPSFM,
  WIN,
  WIN_LWR,
  WIN_RSE,
  STRCFT,
  CAPSFN,
  NPFN,
  USHIFT,
  USHIFTI3,
  I3_FN,
  SIDEBAR,
  EXT_PLV,
  SPCSPC,
  DSHARR,
  EQUARR,
  OUTSPC,
  SCRN1,
  SCRN2,
  SFTSFT,
  BACKLIT,
  ALT_TAB,
  ALTESC
};

const uint16_t PROGMEM fn_actions[] = {
  // [1] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT), // MT(KC_RSFT, KC_ENT)
  // [2] = ACTION_MODS_KEY(MOD_LSFT, KC_UP), // S(KC_UP) 
  // [3] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_MINS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_I3] = LAYOUT_planck_grid(
  LT(_USHIFTI3, KC_ESC), KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,    KC_BSPC,
  LT(_CAPSFN, KC_TAB), KC_A,      KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,    KC_SCLN,    LT(_I3_FN, KC_QUOT),
  MT(MOD_LSFT, KC_MINS), KC_Z,    KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,    KC_COMM,     KC_DOT, CTL_T(KC_SLSH), MT(MOD_RSFT, KC_ENT),
     MO(_NPFN),    KC_LCTL,    KC_LALT,    KC_LGUI, MO(_WIN_LWR),   KC_SPC,    KC_SPC, MO(_WIN_RSE),   _______,   _______,    _______, MO(_USHIFTI3)
),

[_WIN] = LAYOUT_planck_grid(
  LT(_USHIFT, KC_ESC), KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,    KC_BSPC,
  LT(_CAPSFN, KC_TAB), KC_A,      KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,    KC_SCLN,    KC_QUOT,
  MT(MOD_LSFT, KC_MINS), KC_Z,    KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,    KC_COMM,     KC_DOT, CTL_T(KC_SLSH), MT(MOD_RSFT, KC_ENT),
     MO(_NPFN),    KC_LCTL,    KC_LALT,    KC_LGUI, MO(_WIN_LWR),   KC_SPC,    KC_SPC, MO(_WIN_RSE),   _______,   _______,    _______, MO(_USHIFT)
),

[_WIN_LWR] = LAYOUT_planck_grid(
        ALTESC, LALT(KC_F1), LALT(KC_1), LCA(KC_D),  LCA(KC_F),    _______, A(KC_LEFT), RCS(KC_TAB), RCS(KC_UP), C(KC_TAB),    SFTSFT,    _______,
       ALT_TAB,  LCA(KC_0),   S(KC_F8),      KC_F7,      KC_F8,      KC_F9,    _______, LSFT(KC_TAB), RCS(KC_DOWN), KC_TAB, A(KC_HOME),    _______,
       KC_PIPE,   C(KC_F1),  LCA(KC_8),   C(KC_F2),  LCA(KC_9),   C(KC_F4),   C(KC_F5),  G(KC_PGUP),    ALTESC, G(KC_PGDN),    _______, LCA(KC_ENT),
  LCA(KC_COMM),    _______,  LCA(KC_8),   A(KC_F8),    _______,     OUTSPC,    _______,   LCA(KC_N), LCA(KC_M), C(KC_PLUS), C(KC_MINS), LCA(KC_DOT)
),
 
[_WIN_RSE] = LAYOUT_planck_grid(
        KC_GRV,     KC_EQL,    KC_PLUS,    KC_MINS,    _______,    _______,    _______, S(KC_HOME),   S(KC_UP),  S(KC_END), S(KC_PGUP),     KC_DEL,   
       KC_CAPS,    KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,    _______,    _______, S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT), S(KC_PGDN),   _______,   
        DSHARR,    KC_LCBR,    KC_RCBR,    _______,  S(KC_INS),    _______,    _______,    _______,    _______,      KC_UP,    KC_BSLS, RCS(KC_ENT),   
        EQUARR,    _______,    _______,    _______,    _______,     SPCSPC,     SPCSPC,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,      _______
),

[_CAPSFN] = LAYOUT_planck_grid(
  LSFT(KC_ESC),      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,    _______,    KC_HOME,      KC_UP,     KC_END,    KC_PGUP,     KC_F12,   
       _______,      KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,     KC_F11,   
       _______,     KC_F11,     KC_F12,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BSLS,   C(KC_F1),   
       _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,   KC__MUTE
),

[_NPFN] = LAYOUT_planck_grid(
       _______,    _______,    _______,    _______,    _______,    _______,    KC_NLCK,       KC_7,       KC_8,       KC_9,    KC_BSLS,    KC_PSCR,   
       _______,    _______,    _______,    _______,    _______,    _______,    _______,       KC_4,       KC_5,       KC_6,    KC_ASTR,     KC_INS,   
       _______,    _______,    _______,    _______,    _______,    _______,    C(KC_M),       KC_1,       KC_2,       KC_3,    KC_MINS,    KC_PENT,   
       _______,    _______,    _______,    _______,    _______,    C(KC_N),    C(KC_N),       KC_0,     KC_EQL,     KC_DOT,    KC_PLUS,    _______
),

[_STRCFT] = LAYOUT_planck_grid(
         KC_F1,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,     KC_DEL,
          KC_9,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,    KC_SCLN,    KC_QUOT,
          KC_8,       KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,    KC_COMM,     KC_DOT,      F(20),    MT(MOD_RSFT, KC_ENT),
          KC_7,     KC_DOT,    KC_COMM,    KC_SLSH,    KC_LCTL,    KC_RSFT,    KC_RSFT,    KC_LALT,    KC_LEFT,      KC_UP,    KC_DOWN,    LT(_USHIFT, KC_RIGHT)
),

[_USHIFT] = LAYOUT_planck_grid(
       _______,    KC_EXLM,      KC_AT,    KC_HASH,     KC_DLR,    KC_PERC,    _______,     _______, LSG(KC_PGUP), _______,    _______,    G(KC_L),
         RESET,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______, LSG(KC_LEFT), LSG(KC_PGDN), LSG(KC_RIGHT), _______, LCA(KC_DEL),
       _______,    _______,    _______,    _______,    _______,    _______,    _______,  G(KC_LEFT), A(KC_F10), G(KC_RIGHT),   _______,    _______,
           I3,        WIN,     STRCFT,    _______,    _______, A(KC_HOME),    _______,     _______,   _______,    _______,    _______,    _______
   ),

[_USHIFTI3] = LAYOUT_planck_grid(
       _______,    KC_EXLM,      KC_AT,    KC_HASH,     KC_DLR,    KC_PERC,    _______, LSG(KC_LBRC), G(KC_UP), LSG(KC_RBRC),    _______,    LSG(KC_X),
         RESET,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______, G(KC_LEFT), G(KC_DOWN), G(KC_RIGHT), _______, LSG(KC_O),
       _______,    _______,    _______,    _______,    _______,    _______,    _______,  LSG(KC_LEFT), LSG(KC_UP), LSG(KC_RIGHT),   _______,    _______,
           I3,        WIN,     STRCFT,    _______,    _______, A(KC_HOME),    _______,     _______,  LSG(KC_DOWN),    _______,    _______,    _______
   ),

[_I3_FN] = LAYOUT_planck_grid(
       _______,    G(KC_Q),    _______,  LSG(KC_K),      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    
       _______,    _______,  LSG(KC_J),  LSG(KC_L), LSG(KC_SCLN),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    
       _______,    _______,    _______,    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    
       _______,    _______,    _______,    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
   )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case I3:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        set_single_persistent_default_layer(_I3);
      }
      return false;
      break;
    case I3_LWR:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_I3_LWR);
      }
      return false;
      break;
    case I3_RSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_I3_RSE);
      }
      return false;
      break;
    case CAPSFM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CAPSFM);
      }
      return false;
      break;
    case WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN);
      }
      return false;
      break;
    case WIN_RSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN_RSE);
      }
      return false;
      break;
    case WIN_LWR:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN_LWR);
      }
      return false;
      break;
    case CAPSFN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CAPSFN);
      }
      return false;
      break;
    case NPFN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NPFN);
      }
      return false;
      break;
    case USHIFT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_USHIFT);
      }
      return false;
      break;
    case STRCFT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_STRCFT);
      }
      return false;
      break;
    case SPCSPC:
      if (record->event.pressed) {
        SEND_STRING(" "SS_TAP(X_LEFT)" ");
      }
      return false; 
      break;
    case DSHARR:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false; 
      break;
    case EQUARR:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false; 
      break;
    case OUTSPC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")" "SS_TAP(X_ESCAPE)SS_TAP(X_ESCAPE));
      }
      return false; 
      break;
    case SFTSFT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LSHIFT)SS_TAP(X_LSHIFT));
      }
      return false; 
      break;
    case SCRN1:
      if (record->event.pressed) {
        register_code16(KC_BTN1);
        unregister_code16(KC_BTN1);
        SEND_STRING(SS_LCTRL("1"));
      }
      return false; 
      break;
    case SCRN2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("2"));
        register_code16(KC_BTN1);
        unregister_code16(KC_BTN1);
      }
      return false; 
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ALTESC:
      if (record->event.pressed) {
        if (!is_alt_esc_active) {
          is_alt_esc_active = true;
          register_code(KC_LALT);
        }
        alt_esc_timer = timer_read();
        register_code(KC_ESC);
      } else {
        unregister_code(KC_ESC);
      }
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_WIN_RSE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_alt_esc_active) {
    if (timer_elapsed(alt_esc_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_esc_active = false;
    }
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case _WIN_RSE:
    case _WIN_LWR:
      return false;
    default:
      return true;
  }
}
