/* Copyright
 *   2021 iceman_f1
 *   2021 QMK
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
#include "ps21.h"
#ifdef RGBLIGHT_ENABLE
	extern rgblight_config_t rgblight_config; // To pull layer status for RGBLIGHT
#endif

enum layer_names {
    _LAYER0,
    _LAYER1
};
	  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(
		KC_ESC, TO(_LAYER1), KC_CALCULATOR, KC_BSPACE,
		KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,
        KC_KP_0,          KC_KP_DOT
    ),
    [_LAYER1] = LAYOUT(
		KC_TRNS, TO(_LAYER0), KC_TRNS, KC_TRNS,
		KC_TRNS, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_F15,
        KC_F13,       KC_F14
    )
};


void matrix_init_user(void) { //run when matrix is initiated, before all features init
};

void keyboard_post_init_user(void) {	//run as last task in keyboard init
  //debug_enable=true;
  //debug_matrix=true;
  
/*   #ifdef RGB_MATRIX_ENABLE
    //NOTE 1: Layer lighting doesn't work in RGB matrix mode
	//NOTE 2: VIA lighting tab doesn't work and will crash in RGB matrix mode
	//NOTE 3: VIA layers doesn't seem to work properly in RGB matrix mode
	//rgb_matrix_enable_noeeprom(); //turn on RGB matrix based on previous state
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE); //set initial RGB matrix mode	
	rgb_matrix_sethsv_noeeprom(58, 255, 80); //sets LED to green-yellow
  #endif */
  #ifdef RGBLIGHT_ENABLE
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); //Set to static gradient 9. Looks great this way!
	rgblight_sethsv_noeeprom(148, 255, 30); //Set lower default brightness when connected as the right side dimming is not yet in effect
  #endif
};


#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case _LAYER0:
			rgblight_sethsv_noeeprom(148, 255, 70);
			break;
		case _LAYER1:
			rgblight_sethsv_noeeprom(106, 255, 70);
		}
	return state;
	};
#endif
