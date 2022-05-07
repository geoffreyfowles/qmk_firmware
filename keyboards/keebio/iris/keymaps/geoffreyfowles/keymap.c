#include QMK_KEYBOARD_H
#include "features/caps_word.h"

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

enum layer_names {
    _BASE = 0,
    _BASE_MIRRORED,
    _GAMING,
    _GAMING_MIRRORED,
    _GAMING_NUM,
    _GAMING_FN,
    _NUM_FN,
    _SYMBOLS_NAV,
    _MOUSE_MEDIA_MISC,
    _MODS,
    _SHORTCUTS,
};

enum custom_keycodes {
    CLR_MOD = SAFE_RANGE,
};

// renamed keycodes
#define GAMING TG(_GAMING)

#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_N RSFT_T(KC_N)
#define MOD_E LCTL_T(KC_E)
#define MOD_I RALT_T(KC_I)
#define MOD_O RGUI_T(KC_O)
#define LT_D LT(_BASE_MIRRORED, KC_D)
#define LT_H LT(_BASE_MIRRORED, KC_H)

#define LT_ESC LSFT_T(KC_ESC)
#define LT_SPC LT(_NUM_FN, KC_SPC)
#define LT_TAB LT(_SHORTCUTS, KC_TAB)

#define LT_ENT LT(_MOUSE_MEDIA_MISC, KC_ENT)
#define LT_BSP LT(_SYMBOLS_NAV, KC_BSPC)
#define LT_DEL RSFT_T(KC_DEL)

#define GAMENUM MO(_GAMING_NUM)
#define GAME_FN MO(_GAMING_FN)

#define MOD_F10 LGUI_T(KC_F10)
#define MOD_F6 LALT_T(KC_F6)
#define MOD_F5 LCTL_T(KC_F5)
#define MOD_F4 LSFT_T(KC_F4)

#define MOD_UND LGUI_T(KC_UNDS)
#define MOD_MIN LALT_T(KC_MINS)
#define MOD_LPR LCTL_T(KC_LPRN)
#define MOD_RPR LSFT_T(KC_RPRN)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)

#define S_A_TAB LSFT(LALT(KC_TAB))
#define ALT_TAB LALT(KC_TAB)
#define WIN_LFT LGUI(KC_LEFT)
#define WIN_DWN LGUI(KC_DOWN)
#define WIN_UP LGUI(KC_UP)
#define WIN_RGT LGUI(KC_RGHT)
#define W_SFT_L LGUI(LSFT(KC_LEFT))
#define W_SFT_R LGUI(LSFT(KC_RGHT))
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define MICMUTE LGUI(LSFT(KC_A)) // powertoys default

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F13  ,KC_F14  ,KC_F15  ,KC_F16  ,KC_F17  ,KC_F18  ,                   KC_F19  ,KC_F20  ,KC_F21  ,KC_F22  ,KC_F23  ,KC_F24  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                   KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,MOD_A   ,MOD_R   ,MOD_S   ,MOD_T   ,KC_G    ,                   KC_M    ,MOD_N   ,MOD_E   ,MOD_I   ,MOD_O   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,KC_X    ,KC_C    ,LT_D    ,KC_V    ,DM_PLY1 , DM_REC1 ,KC_K    ,LT_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_ESC  ,LT_SPC  ,LT_TAB  ,          LT_ENT  ,LT_BSP  ,LT_DEL
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_BASE_MIRRORED] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SCLN ,KC_Y    ,KC_U    ,KC_L    ,KC_J    ,                   KC_B    ,KC_P    ,KC_F    ,KC_W    ,KC_Q    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,MOD_O   ,MOD_I   ,MOD_E   ,MOD_N   ,KC_M    ,                   KC_G    ,MOD_T   ,MOD_S   ,MOD_R   ,MOD_A   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SLSH ,KC_DOT  ,KC_COMM ,LT_H    ,KC_K    ,DM_REC1 , DM_PLY1 ,KC_V    ,LT_D    ,KC_C    ,KC_X    ,KC_Z    ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_DEL  ,LT_BSP  ,LT_ENT  ,          LT_TAB  ,LT_SPC  ,LT_ESC
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,                   KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LSFT ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,                   KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LCTL ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,_______ , _______ ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    GAME_FN ,KC_SPC  ,GAMENUM ,          _______ ,KC_BSPC ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_GAMING_MIRRORED] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_P    ,KC_O    ,KC_I    ,KC_U    ,KC_Y    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SCLN ,KC_L    ,KC_K    ,KC_J    ,KC_H    ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SLSH ,KC_DOT  ,KC_COMM ,KC_M    ,KC_N    ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,KC_BSPC ,_______ ,          _______ ,_______ ,_______
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
     _______ ,MOD_F10 ,MOD_F6  ,MOD_F5  ,MOD_F4  ,PB_1    ,                   _______ ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F3   ,KC_F2   ,KC_F1   ,_______ ,_______ , _______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,KC_BSPC ,KC_PDOT
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_SYMBOLS_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PLUS ,KC_EQL  ,KC_LCBR ,KC_RCBR ,_______ ,                   KC_INS  ,KC_PSCR ,KC_SLCK ,KC_PAUS ,KC_APP  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,MOD_UND ,MOD_MIN ,MOD_LPR ,MOD_RPR ,KC_BSLS ,                   KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_QUOT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_RBRC ,KC_PIPE ,_______ , _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,KC_DQUO ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_MOUSE_MEDIA_MISC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_U ,KC_WH_L ,KC_MS_U ,KC_WH_R ,_______ ,                   _______ ,KC_BRID ,KC_BRIU ,RGB_VAD ,RGB_VAI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_WH_D ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,                   GAMING  ,KC_RSFT ,KC_RCTL ,KC_RALT ,KC_RGUI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_BTN5 ,KC_BTN3 ,KC_BTN4 ,_______ ,_______ , _______ ,KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,KC_BTN1 ,KC_BTN2 ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_MODS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,OS_LGUI ,OS_LALT ,OS_LCTL ,OS_LSFT ,CLR_MOD ,                   _______ ,KC_RSFT ,KC_RCTL ,KC_RALT ,KC_RGUI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_SHORTCUTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,W_SFT_L ,WIN_UP  ,W_SFT_R ,_______ ,                   _______ ,KC_F19  ,KC_F20  ,KC_F21  ,KC_F23  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,S_A_TAB ,WIN_LFT ,WIN_DWN ,WIN_RGT ,ALT_TAB ,                   _______ ,KC_F16  ,KC_F17  ,KC_F18  ,KC_F22  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,COPY    ,PASTE   ,MICMUTE ,_______ , _______ ,_______ ,KC_F13  ,KC_F14  ,KC_F15  ,KC_F24  ,_______ ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______ ,_______ ,_______ ,          _______ ,_______ ,_______
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),
};
// clang-format on

static uint8_t base_hue = 106;
static uint8_t base_sat = 255;
static uint8_t base_val = RGBLIGHT_LIMIT_VAL;

static bool gaming_on   = false;
static bool locked      = false;
static bool alt_pressed = false;

enum combos {
    CAPS_WORD_COMBO,
    LOCK_COMBO,
    SWAP_HANDS_COMBO,
    SWAP_HANDS_COMBO_2,
    MODS_LAYER_COMBO,
    SWAP_HANDS_COMBO_GAMING,
    ALT_GAMING_COMBO,
    RESET_COMBO,
    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_word_combo[]         = {LT_SPC, LT_BSP, COMBO_END};
const uint16_t PROGMEM lock_combo[]              = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM swap_hands_combo[]        = {LT_TAB, DM_PLY1, COMBO_END};
const uint16_t PROGMEM swap_hands_combo_2[]      = {LT_ENT, DM_REC1, COMBO_END};
const uint16_t PROGMEM mods_layer_combo[]        = {LT_ESC, LT_SPC, COMBO_END};
const uint16_t PROGMEM swap_hands_combo_gaming[] = {GAMENUM, DM_PLY1, COMBO_END};
const uint16_t PROGMEM alt_gaming_combo[]        = {GAME_FN, KC_SPC, COMBO_END};
const uint16_t PROGMEM reset_combo[]             = {LT_ESC, LT_SPC, LT_TAB, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [CAPS_WORD_COMBO]         = COMBO_ACTION(caps_word_combo),
    [LOCK_COMBO]              = COMBO_ACTION(lock_combo),
    [SWAP_HANDS_COMBO]        = COMBO(swap_hands_combo, MO(_BASE_MIRRORED)),
    [SWAP_HANDS_COMBO_2]      = COMBO(swap_hands_combo_2, MO(_BASE_MIRRORED)),
    [MODS_LAYER_COMBO]        = COMBO(mods_layer_combo, MO(_MODS)),
    [SWAP_HANDS_COMBO_GAMING] = COMBO(swap_hands_combo_gaming, MO(_GAMING_MIRRORED)),
    [ALT_GAMING_COMBO]        = COMBO(alt_gaming_combo, KC_LALT),
    [RESET_COMBO]             = COMBO(reset_combo, RESET),
};
// clang-format on

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CAPS_WORD_COMBO:
            if (pressed) {
                caps_word_set(!caps_word_get());
            }
            break;
        case LOCK_COMBO:
            if (pressed) {
                tap_code16(LGUI(KC_L));
                rgb_matrix_disable_noeeprom();
                locked = true;
            }
            break;
    }
}

void set_layer_color(void) {
    if (get_oneshot_mods()) {
        rgb_matrix_sethsv_noeeprom(142, 255, rgb_matrix_get_val());
    } else if (caps_word_get()) {
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    if (locked) {
        rgb_matrix_enable_noeeprom();
        locked = false;
    }

    switch (keycode) {
        case PB_1:
            // HACK see README
            if (record->event.pressed) {
                tap_code16(PB_1);
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

        // workaround for basic keycode limitations
        case MOD_UND:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_UNDS);
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
        case LT_TAB:
            if (!record->event.pressed && alt_pressed) {
                unregister_code(KC_LALT);
                alt_pressed = false;
            }
            break;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LT_ESC:
        case LT_SPC:
        case LT_TAB:
        case LT_ENT:
        case LT_BSP:
        case LT_DEL:
            return true;
        default:
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAMING:
        case _GAMING_MIRRORED:
            clear_all_mods();
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

void caps_word_set_user(bool active) {
    set_layer_color();
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
