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
    _COLEMAK_DH = 0,
    _GAMING,
    _GAMING_NUM,
    _GAMING_FN,
    _NUM_FN,
    _SYMBOLS_NAV,
    _MOUSE_MEDIA_MODS,
    _OSM_SHORTCUTS_EXTRA_FN,
    _WIN_SHORTCUTS,
};

enum custom_keycodes {
    CLR_MOD = SAFE_RANGE,
};

// renamed keycodes
#define GAMING  TG(_GAMING)
#define LT_CAPS LT(0, KC_CAPS)
#define LT_PB_1 LT(0, PB_1)  // this has to be a layer tap for it to be recognized by ahk for some reason. simply putting the PB_1 keycode in the keymap doesn't seem to work

#define LT_A    LT(_WIN_SHORTCUTS, KC_A)
#define MOD_R   LALT_T(KC_R)
#define MOD_S   LGUI_T(KC_S)
#define MOD_T   LCTL_T(KC_T)
#define MOD_N   RCTL_T(KC_N)
#define MOD_E   RGUI_T(KC_E)
#define MOD_I   RALT_T(KC_I)

#define LT_ESC  LT(_OSM_SHORTCUTS_EXTRA_FN, KC_ESC)
#define SFT_SPC LSFT_T(KC_SPC)
#define LT_TAB  LT(_NUM_FN,        KC_TAB)

#define LT_ENT  LT(_SYMBOLS_NAV,      KC_ENT)
#define SFT_BSP RSFT_T(KC_BSPC)
#define LT_DEL  LT(_MOUSE_MEDIA_MODS, KC_DEL)

#define GAMENUM MO(_GAMING_NUM)
#define GAME_FN MO(_GAMING_FN)

#define MOD_MIN LALT_T(KC_MINS)
#define MOD_LPR LGUI_T(KC_LPRN)
#define MOD_RPR LCTL_T(KC_RPRN)

#define S_A_TAB LSFT(LALT(KC_TAB))
#define ALT_TAB LALT(KC_TAB)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)

#define UNDO    LCTL(KC_Z)
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)

#define WIN_L   LGUI(KC_LEFT)
#define WIN_D   LGUI(KC_DOWN)
#define WIN_U   LGUI(KC_UP)
#define WIN_R   LGUI(KC_RGHT)
#define W_SFT_L LGUI(LSFT(KC_LEFT))
#define W_SFT_R LGUI(LSFT(KC_RGHT))
#define MICMUTE LGUI(LSFT(KC_A))  // powertoys default

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F13  ,KC_F14  ,KC_F15  ,KC_F16  ,KC_F17  ,KC_F18  ,                   KC_F19  ,KC_F20  ,KC_F21  ,KC_F22  ,KC_F23  ,KC_F24  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_CAPS ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                   KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,GAMING  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_PB_1 ,LT_A    ,MOD_R   ,MOD_S   ,MOD_T   ,KC_G    ,                   KC_M    ,MOD_N   ,MOD_E   ,MOD_I   ,KC_O    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SH_OS   ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,DM_PLY1 , DM_REC1 ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,SH_OS   ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_ESC  ,SFT_SPC ,LT_TAB  ,          LT_ENT  ,SFT_BSP ,LT_DEL
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LOCK ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,                   KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_LSFT ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,                   KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SH_OS   ,KC_LCTL ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,_______ , _______ ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    GAME_FN ,KC_SPC  ,GAMENUM ,          _______ ,KC_BSPC ,_______
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
     _______ ,KC_F10  ,KC_F6   ,KC_F5   ,KC_F4   ,KC_ESC  ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F3   ,KC_F2   ,KC_F1   ,KC_GRV  ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
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
     _______ ,KC_PLUS ,KC_EQL  ,KC_LCBR ,KC_RCBR ,_______ ,                   KC_INS  ,KC_PSCR ,KC_SLCK ,KC_PAUS ,KC_APP  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_UNDS ,MOD_MIN ,MOD_LPR ,MOD_RPR ,KC_BSLS ,                   KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_QUOT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_RBRC ,KC_PIPE ,_______ , _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,KC_DQUO ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_MOUSE_MEDIA_MODS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_U ,KC_WH_L ,KC_MS_U ,KC_WH_R ,_______ ,                   _______ ,KC_BRID ,KC_BRIU ,RGB_VAD ,RGB_VAI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_D ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,                   _______ ,KC_RCTL ,KC_RGUI ,KC_RALT ,KC_RSFT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_BTN5 ,KC_BTN3 ,KC_BTN4 ,_______ ,_______ , _______ ,KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,KC_BTN1 ,KC_BTN2 ,          RESET   ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_OSM_SHORTCUTS_EXTRA_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,S_A_TAB ,ALT_TAB ,_______ ,_______ ,                   _______ ,KC_F19  ,KC_F20  ,KC_F21  ,KC_F23  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,OS_LSFT ,OS_LALT ,OS_LGUI ,OS_LCTL ,CLR_MOD ,                   _______ ,KC_F16  ,KC_F17  ,KC_F18  ,KC_F22  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,COPY    ,PASTE   ,_______ ,_______ , _______ ,_______ ,KC_F13  ,KC_F14  ,KC_F15  ,KC_F24  ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,RESET   ,          _______ ,KC_BSPC ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_WIN_SHORTCUTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,W_SFT_L ,WIN_U   ,W_SFT_R ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,WIN_L   ,WIN_D   ,WIN_R   ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,MICMUTE ,_______ ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
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
static bool    caps_on     = false;
static bool    gaming_on   = false;
static bool    locked      = false;
static bool    alt_pressed = false;

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

    if (locked && !(keycode == LT_CAPS && !record->tap.count)) {
        rgb_matrix_enable_noeeprom();
        locked = false;
    }

    switch (keycode) {
        case LT_PB_1:
            // pb_1 on tap, alt+f4 on hold
            if (record->event.pressed && !record->tap.count) {
                tap_code16(LALT(KC_F4));
                return false;
            }
            break;

        case LT_CAPS:
            // caps on tap, lock on hold
            if (record->event.pressed) {
                if (record->tap.count) {
                    caps_on = !caps_on;
                    set_layer_color();
                    return false;
                } else {
                    tap_code16(LGUI(KC_L));
                    rgb_matrix_disable_noeeprom();
                    locked = true;
                }
            }
            break;
        case KC_A ... KC_Z:
            if (record->event.pressed && caps_on && !total_mod_state) {
                tap_code16(LSFT(keycode));
                return false;
            }
            break;
        case MOD_R:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_R));
                return false;
            }
            break;
        case MOD_S:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_S));
                return false;
            }
            break;
        case MOD_T:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_T));
                return false;
            }
            break;
        case MOD_N:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_N));
                return false;
            }
            break;
        case MOD_E:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_E));
                return false;
            }
            break;
        case MOD_I:
            if (record->event.pressed && record->tap.count && caps_on && !total_mod_state) {
                tap_code16(LSFT(KC_I));
                return false;
            }
            break;

        case RGB_VAI:
        case RGB_VAD:
            if (record->event.pressed) {
                switch (keycode) {
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
                base_val = rgb_matrix_get_val();
            }
            return false;

        case KC_PDOT:
        case KC_EQL:
        case KC_GRV:
        case KC_LBRC:
        case KC_RBRC:
        case KC_BSLS:
        case MOD_MIN:
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

        case MOD_LPR:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;

        case MOD_RPR:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        case CLR_MOD:
            if (record->event.pressed) {
                clear_all_mods();
            }
            break;

        case S_A_TAB:
        case ALT_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                alt_pressed = true;
            }
            break;

        case LT_ESC:
            if (!record->event.pressed && alt_pressed) {
                unregister_code(KC_LALT);
                alt_pressed = false;
            }
            break;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_ESC:
        case SFT_SPC:
        case LT_TAB:
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

void dynamic_macro_record_start_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
}

void dynamic_macro_record_end_user(int8_t direction) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

void oneshot_mods_changed_user(uint8_t mods) {
    set_layer_color();
}
