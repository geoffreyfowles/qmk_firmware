#include QMK_KEYBOARD_H

#ifdef SWAP_HANDS_ENABLE
__attribute__((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},
    /* Right hand, matrix positions */
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
};
#endif

// clang-format off
enum layer_names {
    _BASE = 0,
    _GAMING,
    _GAMING_NUM,
    _GAMING_FN,
    _NUM_FN,
    _SYMBOLS_NAV,
    _MOUSE,
    _OSM_SHORTCUTS_MEDIA_LIGHTS,
    _EXTRA_FN,
};

enum custom_keycodes {
    HSV_TXT = SAFE_RANGE,
    CLR_MOD,
};

// renamed keycodes
#define LOCK    LGUI(KC_L)
#define GAMING  TG(_GAMING)
#define EXTRAFN TG(_EXTRA_FN)
#define LT_TAB  LT(0, KC_TAB)

#define UNDO   LCTL(KC_Z)
#define CUT    LCTL(KC_X)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)

#define MOD_S   LALT_T(KC_S)
#define MOD_D   LGUI_T(KC_D)
#define MOD_F   LCTL_T(KC_F)
#define MOD_J   RCTL_T(KC_J)
#define MOD_K   RGUI_T(KC_K)
#define MOD_L   RALT_T(KC_L)

#define LT_PB_1 LT(_OSM_SHORTCUTS_MEDIA_LIGHTS, PB_1)
#define SFT_SPC LSFT_T(KC_SPC)
#define LT_CAPS LT(_NUM_FN,           KC_CAPS)

#define LT_ENT  LT(_SYMBOLS_NAV, KC_ENT)
#define SFT_BSP RSFT_T(KC_BSPC)
#define LT_DEL  LT(_MOUSE,       KC_DEL)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)

#define GAMENUM MO(_GAMING_NUM)
#define GAME_FN MO(_GAMING_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LOCK    ,KC_P1   ,KC_P2   ,KC_P3   ,KC_P4   ,KC_P5   ,                   KC_P6   ,KC_P7   ,KC_P8   ,KC_P9   ,KC_P0   ,GAMING  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                   KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,MOD_S   ,MOD_D   ,MOD_F   ,KC_G    ,                   KC_H    ,MOD_J   ,MOD_K   ,MOD_L   ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CLR_MOD ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,DM_PLY1 , DM_REC1 ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_APP  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_PB_1 ,SFT_SPC ,LT_CAPS ,          LT_ENT  ,SFT_BSP ,LT_DEL
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_GRV  ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     SH_OS   ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LOCK ,KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    GAME_FN ,KC_SPC  ,GAMENUM ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MINS ,KC_9    ,KC_8    ,KC_7    ,KC_T    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_0    ,KC_6    ,KC_5    ,KC_4    ,KC_G    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EQL  ,KC_3    ,KC_2    ,KC_1    ,KC_B    ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F11  ,KC_F9   ,KC_F8   ,KC_F7   ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F10  ,KC_F6   ,KC_F5   ,KC_F4   ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F3   ,KC_F2   ,KC_F1   ,_______ ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_NUM_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F11  ,KC_F9   ,KC_F8   ,KC_F7   ,_______ ,                   _______ ,KC_7    ,KC_8    ,KC_9    ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F10  ,KC_F6   ,KC_F5   ,KC_F4   ,_______ ,                   _______ ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F3   ,KC_F2   ,KC_F1   ,_______ ,_______ , _______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,KC_PDOT
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_SYMBOLS_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PLUS ,KC_EQL  ,KC_LCBR ,KC_RCBR ,_______ ,                   KC_INS  ,KC_PSCR ,KC_SLCK ,KC_PAUS ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_UNDS ,KC_MINS ,KC_LPRN ,KC_RPRN ,_______ ,                   KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_RBRC ,_______ ,_______ , _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_U ,KC_WH_L ,KC_MS_U ,KC_WH_R ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_D ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,                   _______ ,KC_RCTL ,KC_RGUI ,KC_RALT ,KC_RSFT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_BTN5 ,KC_BTN3 ,KC_BTN4 ,_______ ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,KC_BTN1 ,KC_BTN2 ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_OSM_SHORTCUTS_MEDIA_LIGHTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,EXTRAFN ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,OS_LSFT ,OS_LALT ,OS_LGUI ,OS_LCTL ,_______ ,                   KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ENT  ,UNDO    ,CUT     ,COPY    ,PASTE   ,_______ ,_______ , _______ ,_______ ,KC_BRID ,KC_BRIU ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,KC_BSPC ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_EXTRA_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F23  ,KC_F21  ,KC_F20  ,KC_F19  ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F22  ,KC_F18  ,KC_F17  ,KC_F16  ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F24  ,KC_F15  ,KC_F14  ,KC_F13  ,_______ ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),
};
// clang-format on

static uint8_t base_hue = 106;
static uint8_t base_sat = 255;
static uint8_t base_val = RGBLIGHT_LIMIT_VAL;

static uint8_t mod_state;
static uint8_t osm_state;
static uint8_t total_mod_state;
static bool    caps_on   = false;
static bool    gaming_on = false;
static bool    locked    = false;

void set_layer_color(void) {
    if (get_oneshot_mods()) {
        rgb_matrix_sethsv_noeeprom(142, 255, rgb_matrix_get_val());
    } else if (caps_on) {
        rgb_matrix_sethsv_noeeprom(43, 255, rgb_matrix_get_val());
    } else if (gaming_on) {
        rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val());
    } else {
        rgb_matrix_sethsv(base_hue, base_sat, base_val);
    }
}

void clear_all_mods(void) {
    clear_oneshot_mods();
    unregister_mods(MOD_MASK_CSAG);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state       = get_mods();
    osm_state       = get_oneshot_mods();
    total_mod_state = mod_state | osm_state;

    if (locked && keycode != LOCK) {
        rgb_matrix_enable_noeeprom();
        locked = false;
    }

    switch (keycode) {
        case LOCK:
            if (record->event.pressed) {
                rgb_matrix_disable_noeeprom();
                locked = true;
            }
            break;

        case LT_TAB:
            // tab on press, alt+tab on hold
            if (record->event.pressed && !record->tap.count) {
                tap_code16(LALT(KC_TAB));
                return false;
            }
            break;

        case LT_CAPS:
            if (record->event.pressed && record->tap.count) {
                caps_on = !caps_on;
                set_layer_color();
                return false;
            }
            break;
        case KC_A ... KC_Z:
            if (record->event.pressed && caps_on && !total_mod_state) {
                tap_code16(LSFT(keycode));
                return false;
            }
            break;
        case MOD_S:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_S));
                return false;
            }
            break;
        case MOD_D:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_D));
                return false;
            }
            break;
        case MOD_F:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_F));
                return false;
            }
            break;
        case MOD_J:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_J));
                return false;
            }
            break;
        case MOD_K:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_K));
                return false;
            }
            break;
        case MOD_L:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_L));
                return false;
            }
            break;

        case KC_PDOT:
        case KC_EQL:
        case KC_GRV:
        case KC_LBRC:
        case KC_RBRC:
            // ignore shift for these keys
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(keycode);
                    set_mods(mod_state);
                    return false;
                } else if (osm_state & MOD_MASK_SHIFT) {
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    register_code(keycode);
                    return false;
                }

            } else {
                unregister_code(keycode);
                return false;
            }
            break;

        case CLR_MOD:
            if (record->event.pressed) {
                clear_all_mods();
            }
            break;

        case LT_PB_1:
            if (!record->event.pressed && !record->tap.count) {
                // key released after holding
                layer_off(_EXTRA_FN);
            }
            break;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_PB_1:
        case SFT_SPC:
        case LT_CAPS:
        case LT_DEL:
        case SFT_BSP:
        case LT_ENT:
            return true;
        default:
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAMING:
            clear_all_mods();
            caps_on   = false;
            gaming_on = true;
            break;

        case _GAMING_NUM:
        case _GAMING_FN:
            break;

        default:
            if (gaming_on) {
                gaming_on = false;
                clear_all_mods();
            }

            break;
    }
    set_layer_color();
    return state;
}

void keyboard_post_init_user(void) { rgb_matrix_sethsv(base_hue, base_sat, base_val); }

void dynamic_macro_record_start_user(void) { rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING); }

void dynamic_macro_record_end_user(int8_t direction) { rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); }

void oneshot_mods_changed_user(uint8_t mods) { set_layer_color(); }
