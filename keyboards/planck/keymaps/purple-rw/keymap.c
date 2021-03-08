/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _COLEMAK,	// Colemak-DH
  _QWERTY,
  _RAISE,	// Symbols
  _LOWER,	// Navigation & Functions
  _NUMPAD,
  _MOUSE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY
};

enum planck_tap_dance {
  _TD_QESC,	// Q or Escape
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // tap once for Q, twice for Escape
    [_TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

// Thumb keys
#define TAP_LWR KC_TAB
#define TAP_RSE KC_ENT
#define NUMPAD  LT(_NUMPAD, KC_DEL)
#define LOWER   LT(_LOWER,  TAP_LWR)
#define Sx_BS   LSFT_T(KC_BSPC)
#define Sx_SPC  RSFT_T(KC_SPC)
#define RAISE   LT(_RAISE,  TAP_RSE)
#define MOUSE   LT(_MOUSE,  KC_QUOT)
#define ADJUSTL LT(_ADJUST, TAP_LWR)
#define ADJUSTR LT(_ADJUST, TAP_RSE)

// Alphas with modifiers
#define Cx_A    LCTL_T(KC_A)
#define Ax_R    LALT_T(KC_R)
#define Ax_S    LALT_T(KC_S)
#define Gx_S    LGUI_T(KC_S)
#define Gx_D    LGUI_T(KC_D)
#define Sx_T    LSFT_T(KC_T)
#define Sx_F    LSFT_T(KC_F)

#define Cx_O    RCTL_T(KC_O)
#define Cx_SCLN RCTL_T(KC_SCLN)
#define Ax_I    RALT_T(KC_I)
#define Ax_L    RALT_T(KC_L)
#define Gx_E    RGUI_T(KC_E)
#define Gx_K    RGUI_T(KC_K)
#define Sx_N    RSFT_T(KC_N)
#define Sx_J    RSFT_T(KC_J)

// Special keys
#define TD_QESC	TD(_TD_QESC)
#define TD_SCQT TD(_TD_SCQT)
#define ZOOMOUT A(G(KC_MINS))
#define ZOOMIN  A(G(KC_EQL))

// Additional modifiers
#define CTL_LT  LCTL_T(KC_LEFT)
#define ALT_RT  LALT_T(KC_RIGHT)
#define ALT_DN  RALT_T(KC_DOWN)
#define CTL_UP  RCTL_T(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* HOLD in Colemak or Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |      |      |      |      |      |      | GUI  | Alt  | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |NumPad|Lower |Shift | GUI  | GUI  |Shift |Raise |Mouse | Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  Q   |  W   |  F   |  P   |  B   |  [   |  ]   |  J   |  L   |  U   |  Y   |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A   |  R   |  S   |  T   |  G   |  \   |  '   |  M   |  N   |  E   |  I   |  O   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Z   |  X   |  C   |  D   |  V   |Zoom- |Zoom+ |  K   |  H   |  ,   |  .   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Left |Right | Del  | Tab  | Bksp | GUI  | GUI  |Space |Enter |  '   | Left |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    TD_QESC, KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    Cx_A,    Ax_R,    Gx_S,    KC_T,    KC_G,    KC_BSLS, KC_QUOT, KC_M,    KC_N,    Gx_E,    Ax_I,    Cx_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    ZOOMOUT, ZOOMIN,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    CTL_LT,  ALT_RT,  NUMPAD,  LOWER,   Sx_BS,   KC_LGUI, KC_RGUI, Sx_SPC,  RAISE,   MOUSE,   ALT_DN,  CTL_UP
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Q   |  W   |  E   |  R   |  T   |  [   |  ]   |  Y   |  U   |  I   |  O   |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A   |  S   |  D   |  F   |  G   |  \   |  '   |  H   |  J   |  K   |  L   |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Z   |  X   |  C   |  V   |  B   |Zoom- |Zoom+ |  N   |  M   |  ,   |  .   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Left |Right | Del  | Tab  | Bksp | GUI  | GUI  |Space |Enter |  '   | Left |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    TD_QESC, KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    Cx_A,    Ax_S,    Gx_D,    KC_F,    KC_G,    KC_BSLS, KC_QUOT, KC_H,    KC_J,    Gx_K,    Ax_L,    Cx_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ZOOMOUT, ZOOMIN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    CTL_LT,  ALT_RT,  NUMPAD,  LOWER,   Sx_BS,   KC_LGUI, KC_RGUI, Sx_SPC,  RAISE,   MOUSE,   ALT_DN,  CTL_UP
),

/* Raise (Symbols)
 * ,-----------------------------------------------------------------------------------.
 * |  7   |  5   |  3   |  1   |  9   |      |      |  8   |  0   |  2   |  4   |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  #   |  =   |  -   |  (   |  [   |  ~   |  `   |  ]   |  )   |  _   |  *   |  $   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  !   |  |   |  &   |  {   |  %   |      |      |  ^   |  }   |  \   |  @   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Prev | Play |  ~   |      | Del  |      |      |      |      |  `   | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    _______, _______, KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
    KC_HASH, KC_EQL,  KC_MINS, KC_LPRN, KC_LBRC, KC_TILD, KC_GRV,  KC_RBRC, KC_RPRN, KC_UNDS, KC_ASTR, KC_DLR,
    KC_EXLM, KC_PIPE, KC_AMPR, KC_LCBR, KC_PERC, _______, _______, KC_CIRC, KC_RCBR, KC_BSLS, KC_AT,   KC_PLUS,
    KC_MRWD, KC_MPLY, KC_TILD, ADJUSTL, KC_DEL,  _______, _______, _______, _______, KC_GRV,  KC_VOLD, KC_VOLU
),

/* Lower (Navigation & Functions)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |ScrLk |      |      | Ins  | PgUp |  Up  | PgDn | Menu |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |PrScn |      |      | Home | Left | Down |Right | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F9  | F10  | F11  | F12  |Pause |      |      |CapsLk|  '   |  "   |  `   |  ~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Prev | Play |  ~   |      |      |      |      |      |      |  `   | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SLCK, _______, _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_APP,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PSCR, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, _______, _______, KC_CAPS, KC_QUOT, KC_DQUO, KC_GRV,  KC_TILD,
    KC_MRWD, KC_MPLY, KC_TILD, _______, _______, _______, _______, _______, ADJUSTR, KC_GRV,  KC_VOLD, KC_VOLU
),

/* Numpad (& Multimedia)
 * ,-----------------------------------------------------------------------------------.
 * |Eject |Rewind| Play |Forwrd|      |      |      |NumLk |  7   |  8   |  9   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ |      |      |      |  -   |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  *   |  1   |  2   |  3   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |Enter |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_EJCT, KC_MRWD, KC_MPLY, KC_MFFD, KC_WSTP, _______, _______, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PEQL,
    KC_WHOM, KC_MUTE, KC_VOLD, KC_VOLU, KC_WREF, _______, _______, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_WFWD, KC_MYCM, KC_MAIL, KC_CALC, KC_WBAK, _______, _______, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PENT, KC_PDOT, _______, _______
),

/* Mouse (& Additional Functions)
 * ,----------------------------------------------------------------------------------.
 * | F13  | F14  | F15  | F16  |Power |      |      |WhlLt | Btn1 |  Up  | Btn2 |WhlRt |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F17  | F18  | F19  | F20  |Sleep |      |      |WhlDn | Left | Down |Right |WhlUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F21  | F22  | F23  | F24  | Wake |      |      | Btn3 | Acc0 | Acc1 | Acc2 | Btn4 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  `   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_PWR,  _______, _______, KC_WH_L, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_R,
    KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_SLEP, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,
    KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_WAKE, _______, _______, KC_BTN3, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN4,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *               v-------------. . . . . . . . . . .------------RGB CONTROL------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug | RGB  |RGBMOD|AGswap|      |      | HUE+ | SAT- | SAT+ |BRGTH-|BRGTH+|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MUSmod|Aud on|Audoff|AGnorm|      |      | HUE- |Colemk|Qwerty|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Voice-|Voice+|Mus on|Musoff|      |      |      |      |MIDIon|MIDIof|TermOn|TermOf|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   RGB_TOG, RGB_MOD, AG_SWAP, _______, _______, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,
    _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _______, _______, RGB_HUD, COLEMAK, QWERTY,  _______, _______,
    MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______, _______, MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

// Longer tapping term for pinkies and ring fingers
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case Cx_A:
    case Ax_R:
    case Ax_S:
//    case Gx_S:
//    case Gx_D:
//    case Sx_T:
//    case Sx_F:
    case Cx_O:
    case Cx_SCLN:
    case Ax_I:
    case Ax_L:
//    case Gx_E:
//    case Gx_K:
//    case Sx_N:
//    case Sx_J:
      return TAPPING_TERM + 100;
    case Sx_SPC:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

// Permissive hold for all thumb keys
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAISE:
    case LOWER:
    case Sx_BS:
    case Sx_SPC:
    case NUMPAD:
    case MOUSE:
      return true;
    default:
      return false;
  }
}

// Ignore mod tap interrupt EXCEPT for all thumb keys but NOT space nor backspace
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAISE:
    case LOWER:
    case NUMPAD:
    case MOUSE:
      return false;
    default:
      return true;
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
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
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
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
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
