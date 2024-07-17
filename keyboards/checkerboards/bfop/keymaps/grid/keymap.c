/* Copyright 2021 Nathan Spears
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

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR  LCTL(LSFT(KC_ESC))
#define M_SERCH LGUI(KC_S)
#define M_SAVE  LCTL(KC_S)
#define LT_SPC  LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_grid(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   M_SERCH, KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_HOME, KC_CALC, KC_PSLS, KC_PAST, KC_PMNS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_PGUP, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_CUT,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_VOLU, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_COPY, KC_END,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
      TT(2),   KC_LCTL, KC_LGUI, KC_LALT, TT(2),   KC_SPC,  KC_PSTE, M_SAVE,  KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_VOLD, KC_SPC,  TT(1),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [1] = LAYOUT_grid(
      QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_RBT
    ),

    [2] = LAYOUT_grid(
      QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_RBT
    ),
};
