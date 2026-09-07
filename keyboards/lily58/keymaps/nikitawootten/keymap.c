 /* Copyright 2020 Naoki Katahira
  * Copyright 2025 Nikita Wootten
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
#include "users/holykeebs/holykeebs.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CLEAN,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define HM_A    LSFT_T(KC_A)
#define HM_S    LCTL_T(KC_S)
#define HM_D    LGUI_T(KC_D)
#define HM_F    LALT_T(KC_F)
#define HM_J    RALT_T(KC_J)
#define HM_K    RGUI_T(KC_K)
#define HM_L    RCTL_T(KC_L)
#define HM_SCLN RSFT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `/~ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | A/Sft| S/Ctl| D/Gui| F/Alt|   G  |-------.    ,-------|   H  | J/Alt| K/Gui| L/Ctl| ;/Sft|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_ESC,   HM_A,   HM_S,    HM_D,    HM_F,    KC_G,                     KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
  SC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SC_RSPC,
                      LOWER, KC_LGUI,  KC_LALT, KC_SPC,   KC_ENT,   KC_BSPC,  KC_RGUI, RAISE
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  /   | KP 7 | KP 8 | KP 9 |  -   |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  *   | KP 4 | KP 5 | KP 6 |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| NUM  | KP 1 | KP 2 | KP 3 |Enter |      |
 * |------+------+------+------+------+------|  Scrl |    |       |------+------+------+------+------+------|
 * |      |DMode | Btn4 | Btn5 | Btn1 | Btn2 |-------|    |-------|      | KP 0 |  ,   |  .   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                        KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_EQL,
  _______, _______, _______, _______, _______, _______,                        KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______,                        KC_NUM,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
  _______, HK_D_MODE, KC_BTN4, KC_BTN5, KC_BTN1, KC_BTN2, HK_S_MODE,  _______, _______, KC_P0,   KC_PCMM, KC_PDOT, _______, _______,
                             _______, _______, _______, _______,      _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      | PScr | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, KC_PSCR, KC_F12,
  _______, _______, _______, _______, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______,   _______, _______, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Home | PgDn | PgUp |  End |      |      |
 * |------+------+------+------+------+------| CLEAN |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  | Del  | RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *  Note: [ = TG(Clean)
 */
  [_ADJUST] = LAYOUT(
    XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT,      HK_DUMP,    HK_SAVE,    HK_RESET,     XXXXXXX, HK_C_SCROLL,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    QK_C_EEPROM,  HK_P_SET_D, HK_P_SET_S, HK_P_SET_BUF, XXXXXXX, HK_S_MODE_T,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, QK_C_EEPROM,
    KC_LSFT,      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, HK_D_MODE_T, TG(_CLEAN),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                   _______, _______, _______, _______,  _______, KC_DEL,  _______, _______
  ),

/* CLEAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |      |-------.    ,-------|      |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------| BASE  |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCtrl | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RCtrl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
  [_CLEAN] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    _______,                        _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    KC_LSFT, _______, _______, _______, _______, _______, TG(_CLEAN),  _______, _______, _______, _______, _______, _______, KC_RSFT,
                               KC_LCTL, _______, _______, _______,      _______, _______, _______, KC_RCTL
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
  return state;
}

#if defined(OLED_ENABLE) && !defined(HK_OLED_ENABLE)

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

#define ANT_W OLED_DISPLAY_WIDTH
#define ANT_H OLED_DISPLAY_HEIGHT
#define ANT_STEPS_PER_FRAME 1
#define ANT_FRAME_MS 33

static uint8_t ant_x, ant_y, ant_d;  // 0=up 1=right 2=down 3=left
static bool ant_ready = false;

static bool ant_px_get(uint8_t x, uint8_t y) {
    // one byte = 8 vertically stacked pixels
    oled_buffer_reader_t r = oled_read_raw(x + (y / 8) * OLED_DISPLAY_WIDTH);
    return (*r.current_element >> (y % 8)) & 1;
}

static void ant_step(void) {
    bool on = ant_px_get(ant_x, ant_y);
    ant_d = (ant_d + (on ? 3 : 1)) & 3;  // lit: turn left, unlit: turn right
    oled_write_pixel(ant_x, ant_y, !on);
    switch (ant_d) {
    case 0: ant_y = ant_y ? ant_y - 1 : ANT_H - 1; break;
    case 1: ant_x = (ant_x + 1) % ANT_W;           break;
    case 2: ant_y = (ant_y + 1) % ANT_H;           break;
    case 3: ant_x = ant_x ? ant_x - 1 : ANT_W - 1; break;
    }
}

bool oled_task_user(void) {
    static uint16_t last = 0;

    if (!ant_ready) {
        oled_clear();
        ant_x = ANT_W / 2;
        ant_y = ANT_H / 2;
        ant_d = 0;
        ant_ready = true;
    }

    if (timer_elapsed(last) > ANT_FRAME_MS) {
        last = timer_read();
        for (uint8_t i = 0; i < ANT_STEPS_PER_FRAME; i++) {
            ant_step();
        }
    }

    return false;
}

#endif // OLED_ENABLE
