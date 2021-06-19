#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap.h"
#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _GAMING 1
#define _SHIFT 2
#define _LOWER 3
#define _RAISE 4
#define _GAMING_CHAT_OVERLAY 10

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  SHIFT,
  GAMING_ENTER,
  GAMING_ESCAPE,
};

#define _ KC_TRNS

#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_GENT GAMING_ENTER
#define KC_GAES GAMING_ESCAPE
#define KC_RASE TT(_RAISE)
#define KC_LOWR MO(_LOWER)
#define KC_TCTL CTL_T(KC_ESC)
#define KC_CLFT LCTL(KC_LEFT)
#define KC_CRHT LCTL(KC_RIGHT)
#define KC_HRSE TG(_RAISE)
#define KC_GMNG TG(_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_DLR,  KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN,                            KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _,       KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LOWR,          KC_LGUI, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_MINS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    SHIFT,   KC_LALT, KC_SPC,                    KC_LOWR, SHIFT,   KC_LCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SHIFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_PERC, KC_7,    KC_5,    KC_3,    KC_1,                               KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      , KC_HRSE,          _      , _      , _      , _      , _      , _      , _      ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _      , _      , KC_SPC,                    KC_DEL,  _      , KC_PSCR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              _      , _      , KC_CIRC, KC_GRV,  KC_EXLM, KC_HASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             _      , KC_CLFT, KC_UP,   KC_CRHT, KC_AT,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , KC_LEFT, KC_DOWN, KC_RGHT, _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _      , _      , _      , _      , _      , _      ,          KC_VOLU, KC_MUTE, KC_MPLY, _      , _      , _      , KC_GMNG,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _      , _      , _      ,                   KC_VOLD, KC_MPRV, KC_MNXT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _      , _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , KC_RTOG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , KC_BTN1, KC_MS_U, KC_BTN2, _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , KC_MS_L, KC_MS_D, KC_MS_R, _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      , KC_HRSE,          KC_PGUP, _      , _      , _      , _      , _      , KC_INS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _      , _      , _      ,                   KC_PGDN, _      , KC_PSCR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_GENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_RASE, KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LALT, KC_SPC,                    KC_LOWR, KC_LCTL, KC_LSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING_CHAT_OVERLAY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _      , _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , _      ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GAES, _      , _      , _      , _      , _      ,                            _      , _      , _      , _      , _      , KC_GENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _      , _      , _      , _      , _      , _      , _      ,          _      , _      , _      , _      , _      , _      , _      ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _      , _      , _      ,                   _      , _      , _
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

};

void gaming_toggle_and_register_key(uint16_t key_to_send, keyrecord_t *record);

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer); default_layer_set(default_layer);
}

void switch_to_layer(uint8_t layer, bool pressed) {
    if (pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (action_for_key(_SHIFT, record->event.key).code != ACTION_TRANSPARENT) {
        unregister_code(KC_LSFT);

        /* Run the action without shift activated */
        action_t action = store_or_get_action(record->event.pressed, record->event.key);
        process_action(record, action);

        /* If shift was pressed re-press it */
        if (IS_LAYER_ON(_SHIFT))
            register_code(KC_LSFT);

        return false;
    }

    switch (keycode) {
        case SHIFT:
            switch_to_layer(_SHIFT, record->event.pressed);

            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }

            return false;

       case GAMING_ENTER:
            gaming_toggle_and_register_key(KC_ENT, record);
	    return false;

       case GAMING_ESCAPE:
            gaming_toggle_and_register_key(KC_ESC, record);
	    return false;
    }
    return true;
}

void gaming_toggle_and_register_key(uint16_t key_to_send, keyrecord_t *record) {
    if (record->event.pressed) {
    	register_code(key_to_send);
    } else {
    	unregister_code(key_to_send);
    	return;
    }

    layer_invert(_GAMING);
    layer_invert(_GAMING_CHAT_OVERLAY);

    return;
}

void led_set_rgb_range(int r, int g, int b) {
    #ifdef RGBLIGHT_ENABLE
    for (unsigned int i = 0; i <= 14; i++) {
        rgblight_setrgb_at(r, g, b, 14);
    }
    #endif
}

void led_set_default(void) {
    #ifdef RGBLIGHT_ENABLE
    rgblight_mode(1);
    // Should be at most 255 / 7 (~36)
    const unsigned int grad_magnitude = 30;

    // Left side
    for (unsigned int i = 0; i <= 6; i++) {
        unsigned int x = 6 - i;
        rgblight_setrgb_at(x * grad_magnitude, 255 - x * grad_magnitude, 0, i);
    }

    // Right side
    for (unsigned int i = 7; i <= 14; i++) {
        unsigned int x = i - 7;
        rgblight_setrgb_at(x * grad_magnitude, 0, 255 - x * grad_magnitude, i);
    }
    #endif
}

void keyboard_post_init_user(void) {
    led_set_default();
}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    #ifdef RGBLIGHT_ENABLE
    uint8_t layer = biton32(state);
    switch (layer) {
        case _DVORAK:
            led_set_default();
            break;
        case _LOWER:
            rgblight_setrgb_blue();
            break;
        case _RAISE:
            rgblight_setrgb_green();
            break;
        case _GAMING:
            rgblight_setrgb_red();
            break;
    }
    #endif

    return state;
}
