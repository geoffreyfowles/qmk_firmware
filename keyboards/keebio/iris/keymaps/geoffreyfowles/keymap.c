#include QMK_KEYBOARD_H

// clang-format off
enum layer_names {
    _BASE = 0,
    _GAMING,
    _NUM_FN,
    _SYMBOLS_NAV,
    _MOUSE_SYMBOLS,
    _OSM_MEDIA_LIGHTS,
    _EXTRA_FN,
};

enum custom_keycodes {
    HSV_TXT = SAFE_RANGE,
    CLR_MOD,
};

// renamed keycodes
#define LOCK    LGUI(KC_L)
#define GAMING  TG(_GAMING)
#define EXTRAFN TO(_EXTRA_FN)

#define MOD_A   LSFT_T(KC_A)
#define MOD_S   LALT_T(KC_S)
#define MOD_D   LGUI_T(KC_D)
#define MOD_F   LCTL_T(KC_F)
#define MOD_J   RCTL_T(KC_J)
#define MOD_K   RGUI_T(KC_K)
#define MOD_L   RALT_T(KC_L)
#define MOD_SCL RSFT_T(KC_SCLN)

#define LT_PB_1 LT(_OSM_MEDIA_LIGHTS, PB_1)
#define LT_SPC  LT(_SYMBOLS_NAV,      KC_SPC)
#define LT_CAPS LT(_NUM_FN,           KC_CAPS)
#define LT_BSPC LT(_SYMBOLS_NAV,      KC_BSPC)
#define LT_ENT  LT(_MOUSE_SYMBOLS,    KC_ENT)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)

#define WIN_L LGUI(KC_LEFT)
#define WIN_U LGUI(KC_UP)
#define WIN_R LGUI(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LOCK    ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                   KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,GAMING  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                   KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,MOD_A   ,MOD_S   ,MOD_D   ,MOD_F   ,KC_G    ,                   KC_H    ,MOD_J   ,MOD_K   ,MOD_L   ,MOD_SCL ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CLR_MOD ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,DM_PLY1 , DM_REC1 ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_APP  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_PB_1 ,LT_SPC  ,LT_CAPS ,          OS_LSFT ,LT_BSPC ,LT_ENT
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F2   ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F3   ,KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F4   ,KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_ESC  , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_F5   ,KC_SPC  ,KC_F6   ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_NUM_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F11  ,KC_F9   ,KC_F8   ,KC_F7   ,_______ ,                   _______ ,KC_P7   ,KC_P8   ,KC_P9   ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F10  ,KC_F6   ,KC_F5   ,KC_F4   ,_______ ,                   _______ ,KC_P4   ,KC_P5   ,KC_P6   ,KC_P0   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F3   ,KC_F2   ,KC_F1   ,_______ ,_______ , _______ ,_______ ,KC_P1   ,KC_P2   ,KC_P3   ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          KC_PDOT ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_SYMBOLS_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PPLS ,KC_EQL  ,KC_LCBR ,KC_RCBR ,_______ ,                   KC_INS  ,KC_PSCR ,KC_SLCK ,KC_PAUS ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_UNDS ,KC_PMNS ,KC_LPRN ,KC_RPRN ,_______ ,                   KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_DEL  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_RBRC ,_______ ,_______ , _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_MOUSE_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_U ,KC_WH_L ,KC_MS_U ,KC_WH_R ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_D ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,                   _______ ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_BTN5 ,KC_BTN3 ,KC_BTN4 ,_______ ,_______ , _______ ,_______ ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,KC_BTN1 ,KC_BTN2 ,          _______ ,_______ ,_______
                                // └───────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_OSM_MEDIA_LIGHTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,RGB_HUI ,RGB_SAI ,RGB_VAI ,HSV_TXT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,RGB_HUD ,RGB_SAD ,RGB_VAD ,RGB_TOG ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,OS_LSFT ,OS_LALT ,OS_LGUI ,OS_LCTL ,_______ ,                   KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,EXTRAFN ,_______ ,_______ , _______ ,_______ ,KC_BRID ,KC_BRIU ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
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

static uint8_t base_hue = 142;
static uint8_t base_sat = 255;
static uint8_t base_val = RGBLIGHT_LIMIT_VAL;
static char    current_hsv[12];

static uint8_t mod_state;
static uint8_t osm_state;
static uint8_t total_mod_state;
static bool    caps_on   = false;
static bool    gaming_on = false;

void save_current_hsv(void) {
    base_hue = rgb_matrix_get_hue();
    base_sat = rgb_matrix_get_sat();
    base_val = rgb_matrix_get_val();
    snprintf(current_hsv, 12, "%d,%d,%d", base_hue, base_sat, base_val);
}

void set_layer_color(void) {
    if (get_oneshot_mods()) {
        rgb_matrix_sethsv_noeeprom(21, 255, rgb_matrix_get_val());
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

    switch (keycode) {
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
        case MOD_A:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_A));
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

        case RGB_HUI ... RGB_VAD:
            if (record->event.pressed) {
                switch (keycode) {
                    case RGB_HUI:
                        rgb_matrix_increase_hue();
                        break;
                    case RGB_HUD:
                        rgb_matrix_decrease_hue();
                        break;
                    case RGB_SAI:
                        rgb_matrix_increase_sat();
                        break;
                    case RGB_SAD:
                        rgb_matrix_decrease_sat();
                        break;
                    case RGB_VAI:
                        rgb_matrix_increase_val();
                        if (rgb_matrix_get_val() > RGBLIGHT_LIMIT_VAL) {
                            rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), RGBLIGHT_LIMIT_VAL);
                        }
                        break;
                    case RGB_VAD:
                        rgb_matrix_decrease_val();
                        break;
                }

                save_current_hsv();
            }
            return false;

        case HSV_TXT:
            if (record->event.pressed) {
                send_string(current_hsv);
            }
            break;

        case KC_P1 ... KC_PDOT:
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
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_PB_1:
        case LT_SPC:
        case LT_CAPS:
        case LT_BSPC:
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

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv(base_hue, base_sat, base_val);
    snprintf(current_hsv, 12, "%d,%d,%d", base_hue, base_sat, base_val);
}

void dynamic_macro_record_start_user(void) { rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING); }

void dynamic_macro_record_end_user(int8_t direction) { rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); }

void oneshot_mods_changed_user(uint8_t mods) { set_layer_color(); }
