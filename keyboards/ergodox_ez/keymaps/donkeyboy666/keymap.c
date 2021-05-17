/* vim: set foldlevel=0: */

#include QMK_KEYBOARD_H
#include "version.h"

#define LAYER_ON_CHECK(layer) (state & (1 << (layer)))

enum custom_keycodes
{ /*»*/
  KEY_LOCK = EZ_SAFE_RANGE,
  KEY_MHR,
  KEY_WMN,
  KEY_SYM,
  KEY_NUM,
  KEY_000,
  KEY_MWTF,
  KEY_CAPS,
  KEY_SHIFTR,
  KEY_SHIFTL,
  KEY_DOTA,
}; /*«*/

enum layers
{ /*»*/
  BASE,
  NUM,
  SYM,
  MHR,
  WMN,
  DOTA,
}; /*«*/

/* action shortcuts */
#define KEY_QUIT LALT(KC_Q) /*»*/
#define KEY_PASTE LCTL(KC_V)
#define KEY_PASTE_L LCTL(LSFT(KC_V))
#define KEY_COPY LCTL(KC_C)
#define KEY_COPY_L LCTL(LSFT(KC_C))
#define KEY_CUT LCTL(KC_X)
#define KEY_UNDO LCTL(KC_Z)
#define KEY_REDO_V LCTL(KC_R)
#define KEY_REDO LCTL(KC_R)
#define KEY_CTRLZ LCTL(KC_Z)
#define KEY_CTRLD LCTL(KC_D)
#define KEY_CTRLN LCTL(KC_N)
#define KEY_CTRLC LCTL(KC_C)
#define KEY_CTRLW LCTL(KC_W)
#define KEY_EDIT LCTL(KC_T)
#define KEY_RENAME LCTL(KC_T) /*«*/

/* window manager shortcuts */
#define KEY_GA0 LGUI(LALT(KC_0)) /*»*/
#define KEY_GA1 LGUI(LALT(KC_1))
#define KEY_GA2 LGUI(LALT(KC_2))
#define KEY_GA3 LGUI(LALT(KC_3))
#define KEY_GA4 LGUI(LALT(KC_4))
#define KEY_GA5 LGUI(LALT(KC_5))
#define KEY_GA6 LGUI(LALT(KC_6))
#define KEY_GA7 LGUI(LALT(KC_7))
#define KEY_GA8 LGUI(LALT(KC_8))
#define KEY_GA9 LGUI(LALT(KC_9))
#define KEY_WNEW LALT(LCTL(KC_N))       /* go to first empty desktop current monitor */
#define KEY_WNSS LALT(LCTL(LSFT(KC_N))) /* cycle between nodes current desktop */
#define KEY_WSDL LALT(LCTL(KC_LEFT))
#define KEY_WSDV LALT(LCTL(KC_UP)) /* swtich to next monitor desktop */
#define KEY_WSDR LALT(LCTL(KC_RIGHT))
#define KEY_WMWL LALT(LCTL(LSFT(KC_LEFT)))
#define KEY_WMWV LALT(LCTL(LSFT(KC_DOWN))) /* move node to next monitor */
#define KEY_WMWR LALT(LCTL(LSFT(KC_RIGHT)))
#define KEY_WFUL LALT(RGUI(KC_ENT))
#define KEY_WFLT LALT(RGUI(KC_SPC))
#define KEY_WHLF LALT(RGUI(KC_H))
#define KEY_WTLD LALT(RGUI(KC_T))
#define KEY_WSNL LALT(LCTL(LGUI(KC_LEFT)))
#define KEY_WSNU LALT(LCTL(LGUI(KC_UP)))
#define KEY_WSND LALT(LCTL(LGUI(KC_DOWN)))
#define KEY_WSNR LALT(LCTL(LGUI(KC_RIGHT)))
#define KEY_WMNL LALT(LCTL(LGUI(LSFT(KC_LEFT))))
#define KEY_WMNU LALT(LCTL(LGUI(LSFT(KC_UP))))
#define KEY_WMND LALT(LCTL(LGUI(LSFT(KC_DOWN))))
#define KEY_WMNR LALT(LCTL(LGUI(LSFT(KC_RIGHT))))
#define KEY_WNSW LALT(LCTL(LSFT(KC_T))) /* swap nodes */
#define KEY_WNRT LALT(LCTL(LSFT(KC_R))) /* rotate nodes */
#define KEY_WMM1 LALT(LGUI(KC_F1))
#define KEY_WMM2 LALT(LGUI(KC_F2))
#define KEY_WMM3 LALT(LGUI(KC_F3))
#define KEY_WMLB LALT(LGUI(KC_S))       /* browser */
#define KEY_WMLT LALT(LGUI(KC_A))       /* terminal */
#define KEY_WMLC LALT(LGUI(KC_E))       /* cctv */
#define KEY_WMSG LALT(LGUI(KC_G))       /* serach with google */
#define KEY_WMLR LALT(LGUI(KC_Z))       /* rofi run */
#define KEY_WMLW LALT(LGUI(KC_W))       /* rofi windows */
#define KEY_WMLX LALT(LGUI(KC_X))       /* clip menu */
#define KEY_WMLD LALT(LGUI(KC_D))       /* nemo */
#define KEY_WMSC LCTL(LALT(LGUI(KC_K))) /* screenshot */
#define KEY_WWHD LCTL(LGUI(KC_H))       /* hide window */
#define KEY_WHWN LALT(LGUI(LCTL(KC_H))) /* show hidden windows */
#define KEY_FOCM LALT(LCTL(LSFT(KC_M))) /* focus mouse to current node */
/*«*/

/* clang-format off */ 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(/*»*/
    KC_ESC,     KEY_WMSC, KEY_WMSG,      KEY_WMLR, KEY_WMLW,       KEY_WMLX, KEY_WMLC,      KEY_WMLD, KC_NO,   KC_NO,          KC_NO,           KC_NO,           KC_MUTE,       KC_VOLU,
    KC_F8,      KC_F15,   KC_K,          KC_C,     KC_P,           KC_ESC,      KC_NO,      KC_NO,    KC_ENT,  KC_M,           KC_L,            KC_Q,            KC_F19,        KC_VOLD,
    KC_F14,     KC_Z,     KC_U,          KC_S,     KC_T,           KC_B,                              KC_F,    KC_N,           KC_R,            KC_I,            KC_NO,         KC_ESC,
    KC_LCTL,    KC_A,     LT(WMN, KC_W), KC_G,     KC_D,           KC_V,     KEY_WMLB,      KEY_WMLT, KC_J,    KC_H,           KC_X,            KC_Y,            KC_O,          KC_LCTL,
    KC_NO,      KC_LSFT,  KC_NO,         KC_LGUI,  KC_LALT,                                                    KC_LALT,        KC_LGUI,         KC_NO,           KC_RSFT,       KC_NO,
                                                                       KC_TAB, KC_F16,      KEY_CAPS, KC_ENT,
                                                                               KC_DEL,      KC_DEL,
                                                         KEY_SHIFTL, KEY_NUM, KEY_MHR,      KEY_MHR,  KEY_SYM, KEY_SHIFTR
  ),/*«*/ 
 [MHR] = LAYOUT_ergodox_pretty(/*»*/    
    KEY_MWTF, KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,        KC_NO,       KC_NO,      KC_NO,     KC_NO,      KC_NO,       KC_NO,    KC_NO,    
    KC_NO,    KC_NO,     KC_NO,      KC_UP,      KC_NO,      KC_NO,       KC_NO,        KC_NO,       KC_TRNS,    KC_NO,     KC_UP,      KC_NO,       KC_NO,    KC_NO,   
    KC_NO,    KC_NO,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_BTN3,                                KC_NO,      KC_LEFT,   KC_DOWN,    KC_RIGHT,    KC_NO,    KC_NO,   
    KC_TRNS,  KC_NO,     KC_HOME,    KC_NO,      KC_END,     KEY_PASTE_L, KEY_QUIT,     KC_NO,       KEY_COPY_L, KC_HOME,   KC_NO,      KC_END,      KC_NO,    KC_TRNS,
    KC_NO,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                                                        KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,    KC_TRNS,        KEY_DOTA, KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS 
  ),/*«*/
  [NUM] = LAYOUT_ergodox_pretty(/*»*/
    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KEY_LOCK,
    KC_TRNS,  KC_TRNS,  KC_HASH, KC_7,     KC_CIRC,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_AT,    KC_3,     KC_PERC,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_6,    KC_9,     KC_4,     KC_ASTR,                        KC_PLUS,  KC_1,     KC_5,     KC_2,     KEY_000,  KC_TRNS,
    KC_TRNS,  KC_8,     KC_LPRN, KC_COMM,  KC_DOT,   KC_TILDE,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_SLSH,  KC_MINUS, KC_RPRN,  KC_0,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                     KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
                                                              KC_TRNS,    KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  ),/*«*/
 [SYM] = LAYOUT_ergodox_pretty(/*»*/
    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KEY_WMM1,  
    KC_TRNS,  KC_TRNS,  KC_DLR,    KC_LBRC,   KC_EXLM,   KC_F1,    KC_TRNS,      KC_TRNS,  KC_F4,     KC_GRV,   KC_RBRC,  KC_AMPR,  KC_TRNS,  KEY_WMM2, 
    KC_TRNS,  KC_TRNS,  KC_QUES,   KC_DOT,    KC_SCLN,   KC_F2,                            KC_F5,     KC_COLN,  KC_DQUO,  KC_QUOT,  KEY_000,  KEY_WMM3, 
    KC_TRNS,  KC_LCBR,  KC_LT,     KC_PIPE,   KC_BSLS,   KC_F3,    KC_TRNS,      KC_TRNS,  KC_F6,     KC_EQL,   KC_UNDS,  KC_GT,    KC_RCBR,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,
                                                          KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,      KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
  ),/*«*/
 [WMN] = LAYOUT_ergodox_pretty(/*»*/    
    KC_NO,    KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,       KC_NO,    KEY_WMM1,   
    KC_NO,    KC_NO,     KC_NO,      KEY_WMWL,   KEY_WMWR,   KEY_WMWV,    KC_NO,      KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,       KC_NO,    KEY_WMM2, 
    KC_NO,    KC_NO,     KC_NO,      KEY_WSDL,   KEY_WSDR,   KEY_WSDV,                          KC_NO,      KC_NO,     KC_NO,     KC_NO,       KC_NO,    KEY_WMM3,  
    KC_NO,    KEY_WHLF,  KC_TRNS,    KEY_WFUL,   KEY_WNSS,   KEY_WNSW,    KC_NO,      KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,       KC_NO,    KC_NO,
    KC_NO,    KEY_WNRT,  KC_NO,      KEY_WFLT,   KEY_WTLD,                                                  KC_NO,     KC_NO,     KC_NO,       KC_NO,    KC_NO,
                                                                KC_NO,    KC_NO,      KC_NO, KC_NO,
                                                                          KEY_WHWN,   KC_NO,
                                                      KEY_WMLW, KEY_WNEW, KEY_WWHD,   KC_NO, KC_NO, KC_NO
  ),/*«*/
 [DOTA] = LAYOUT_ergodox_pretty(/*»*/
    KC_PAUSE,   KC_Y,     KC_Q,     KC_L,     KC_O,     KC_Z,     KC_3,       KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,  KC_NO,  
    KC_4,       KC_F13,   KC_W,     KC_M,     KC_P,     KC_TAB,   KC_2,       KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,  KC_NO,
    KC_H,       KC_J,     KC_S,     KC_R,     KC_T,     KC_G,                         KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,  KC_NO, 
    KC_ESC,     KC_A,     KC_LALT,  KC_C,     KC_D,     KC_F,     KC_N,       KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,  KC_NO,
    KC_1,       KC_LSFT,  KC_LCTL,  KC_5,     KC_B,                                          KC_NO,  KC_NO,   KC_NO,    KC_NO,  KC_NO,
                                                             KC_K, KC_X,      KEY_DOTA, KC_NO,
                                                                   KC_V,      KC_NO,
                                                   KC_SPC, KC_ENT, KC_E,      KC_NO, KC_NO, KC_NO
  )/*«*/
};
/* clang-format on */

static bool keyboard_locked = false;
static bool caps_enabled = false;
static bool dota_layer_on = false;
static bool mhr_layer_on = false;
static uint16_t mhr_pressed_timer = 0;
static bool mhr_do_1st_tap = true;
static bool mhr_layer_hold = false;
static bool inbetween_key = false;

#define REPEAT_TIMEOUT 400
#define KEY_SECOND_PRESSED_TIMEOUT 200
#define KEY_REPEAT_DEFINES(prefix) /*»*/                           \
  [[maybe_unused]] static uint16_t prefix##_pressed_timer = 0;      \
  [[maybe_unused]] static bool prefix##_layer_on = false;           \
  [[maybe_unused]] static bool prefix##_interrupted = false;        \
  [[maybe_unused]] static bool prefix##_repeat = false;             \
  [[maybe_unused]] static bool prefix##_repeated = false;           \
  [[maybe_unused]] static bool prefix##_do_2nd_tap = false;         \
  [[maybe_unused]] static bool prefix##_second_press = false;       \
  [[maybe_unused]] static uint16_t prefix##_repeat_timeout = 0;     \
  [[maybe_unused]] static uint16_t prefix##_seq_start_timer = 0;    \
  [[maybe_unused]] static uint16_t prefix##_second_press_timer = 0; \
  /*«*/

#define SYM_REPEAT_KEY X_SPC
KEY_REPEAT_DEFINES(sym)

#define NUM_REPEAT_KEY X_E
KEY_REPEAT_DEFINES(num)

#define SHIFTL_REPEAT_KEY X_ENT
#define SHIFTL_HOLD_KEY X_LSFT
KEY_REPEAT_DEFINES(shiftl)

#define SHIFTR_REPEAT_KEY X_BSPC
#define SHIFTR_HOLD_KEY X_RSFT
KEY_REPEAT_DEFINES(shiftr)

#define KEY_MOD_REPEAT(prefix, key) /*»*/                                                        \
  case KEY_##key:                                                                                 \
  {                                                                                               \
    if (record->event.pressed)                                                                    \
    {                                                                                             \
      inbetween_key = false;                                                                      \
      prefix##_layer_on = true;                                                                   \
      SEND_STRING(SS_DOWN(key##_HOLD_KEY));                                                       \
      if (prefix##_do_2nd_tap)                                                                    \
      {                                                                                           \
        prefix##_second_press_timer = timer_read();                                               \
        prefix##_second_press = true;                                                             \
        if (timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT)                             \
        {                                                                                         \
          prefix##_repeat = true;                                                                 \
          prefix##_repeated = false;                                                              \
        }                                                                                         \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
        prefix##_do_2nd_tap = true;                                                               \
        prefix##_second_press = false;                                                            \
        prefix##_seq_start_timer = timer_read();                                                  \
      }                                                                                           \
    }                                                                                             \
    else                                                                                          \
    {                                                                                             \
      if (!prefix##_repeated)                                                                     \
      {                                                                                           \
        SEND_STRING(SS_UP(key##_HOLD_KEY));                                                       \
        if (!prefix##_interrupted)                                                                \
        {                                                                                         \
          if (!prefix##_second_press && timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT) \
          {                                                                                       \
            SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                                \
            inbetween_key = true;                                                                 \
          }                                                                                       \
          else                                                                                    \
          {                                                                                       \
            if (prefix##_second_press &&                                                          \
                timer_elapsed(prefix##_second_press_timer) < REPEAT_TIMEOUT && !inbetween_key)    \
            {                                                                                     \
              SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                              \
              inbetween_key = true;                                                               \
            }                                                                                     \
            prefix##_do_2nd_tap = false;                                                          \
            prefix##_repeat = false;                                                              \
          }                                                                                       \
        }                                                                                         \
        else                                                                                      \
        {                                                                                         \
          prefix##_interrupted = false;                                                           \
          prefix##_do_2nd_tap = false;                                                            \
          prefix##_repeat = false;                                                                \
        }                                                                                         \
        prefix##_layer_on = false;                                                                \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
        prefix##_repeat = false;                                                                  \
        prefix##_repeated = false;                                                                \
        prefix##_do_2nd_tap = false;                                                              \
      }                                                                                           \
    }                                                                                             \
    return false;                                                                                 \
  }                                   /*«*/
#define KEY_LAYER_REPEAT(prefix, key) /*»*/                                                      \
  case KEY_##key:                                                                                 \
  {                                                                                               \
    if (record->event.pressed)                                                                    \
    {                                                                                             \
      prefix##_layer_on = true;                                                                   \
      layer_on(key);                                                                              \
      inbetween_key = false;                                                                      \
      if (prefix##_do_2nd_tap)                                                                    \
      {                                                                                           \
        prefix##_second_press_timer = timer_read();                                               \
        prefix##_second_press = true;                                                             \
        if (timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT && !inbetween_key)           \
        {                                                                                         \
          prefix##_repeat = true;                                                                 \
          prefix##_repeated = false;                                                              \
        }                                                                                         \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
        prefix##_interrupted = false;                                                             \
        prefix##_do_2nd_tap = true;                                                               \
        prefix##_second_press = false;                                                            \
        prefix##_seq_start_timer = timer_read();                                                  \
      }                                                                                           \
    }                                                                                             \
    else                                                                                          \
    {                                                                                             \
      if (!prefix##_repeated)                                                                     \
      {                                                                                           \
        layer_off(key);                                                                           \
        if (!prefix##_interrupted)                                                                \
        {                                                                                         \
          if (!prefix##_second_press && timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT) \
          {                                                                                       \
            SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                                \
            inbetween_key = true;                                                                 \
            SET_LAYER_INTERRUPTED(shiftl);                                                        \
            SET_LAYER_INTERRUPTED(shiftr);                                                        \
          }                                                                                       \
          else                                                                                    \
          {                                                                                       \
            if (prefix##_second_press &&                                                          \
                timer_elapsed(prefix##_second_press_timer) < REPEAT_TIMEOUT)                      \
            {                                                                                     \
              SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                              \
              inbetween_key = true;                                                               \
              SET_LAYER_INTERRUPTED(shiftl);                                                      \
              SET_LAYER_INTERRUPTED(shiftr);                                                      \
            }                                                                                     \
            prefix##_do_2nd_tap = false;                                                          \
            prefix##_repeat = false;                                                              \
          }                                                                                       \
          prefix##_layer_on = false;                                                              \
        }                                                                                         \
        else                                                                                      \
        {                                                                                         \
          prefix##_do_2nd_tap = false;                                                            \
          prefix##_repeat = false;                                                                \
        }                                                                                         \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
        prefix##_repeat = false;                                                                  \
        prefix##_repeated = false;                                                                \
        prefix##_do_2nd_tap = false;                                                              \
      }                                                                                           \
    }                                                                                             \
    return false;                                                                                 \
  }                                   /*«*/
#define SET_LAYER_INTERRUPTED(prefix) /*»*/ \
  if (prefix##_layer_on || prefix##_repeat)  \
  {                                          \
    prefix##_interrupted = true;             \
  } /*«*/

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  if (keyboard_locked && keycode != KEY_LOCK)
  { /*»*/
    return false;
  } /*«*/

  switch (keycode)
  {
    case KEY_LOCK:
    { /*»*/
      if (record->event.pressed)
      {
        if (keyboard_locked)
        {
          keyboard_locked = false;

          // because lock is on num layer
          num_layer_on = false;
          num_repeat = false;
          num_interrupted = false;
          layer_off(NUM);
        }
        else
        {
          keyboard_locked = true;
          num_interrupted = true;
        }
      }
      return false;
    } /*«*/

      KEY_LAYER_REPEAT(sym, SYM);
      KEY_LAYER_REPEAT(num, NUM);
      KEY_MOD_REPEAT(shiftl, SHIFTL);
      KEY_MOD_REPEAT(shiftr, SHIFTR);

    case KEY_MHR:
    { /*»*/
      if (record->event.pressed)
      {
        if (timer_elapsed(mhr_pressed_timer) > 400 && !mhr_do_1st_tap)
        {
          mhr_do_1st_tap = true;
        }
        if (mhr_do_1st_tap)
        {
          mhr_pressed_timer = timer_read();
        }
        if (!mhr_layer_on)
        {
          layer_on(MHR);
          mhr_layer_on = true;
        }
      }
      else
      {
        if (mhr_do_1st_tap)
        {
          mhr_layer_on = false;
          layer_off(MHR);
          mhr_do_1st_tap = false;
          mhr_layer_hold = false;
        }
        else
        {
          if (!mhr_layer_hold)
          {
            mhr_layer_hold = true;
            mhr_do_1st_tap = false;
          }
          else
          {
            mhr_layer_on = false;
            layer_off(MHR);
            mhr_do_1st_tap = true;
            mhr_layer_hold = false;
          }
        }
      }
      return false;
    } /*«*/

    case KEY_CAPS:
    { /*»*/
      if (record->event.pressed)
      {
        if (!caps_enabled)
        {
          SEND_STRING(SS_TAP(X_CAPS));
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          ergodox_right_led_3_on();
          caps_enabled = true;
        }
        else
        {
          SEND_STRING(SS_TAP(X_CAPS));
          ergodox_right_led_1_off();
          ergodox_right_led_2_off();
          ergodox_right_led_3_off();
          caps_enabled = false;
        }
      }
      return false;
    } /*«*/
    case KEY_DOTA:
    { /*»*/
      if (record->event.pressed)
      {
        if (!dota_layer_on)
        {
          layer_move(DOTA);
          dota_layer_on = true;
        }
        else
        {
          layer_clear();
          dota_layer_on = false;
        }
      }
      return false;
    } /*«*/
    case KEY_000:
    { /*»*/
      if (record->event.pressed)
      {
        SEND_STRING("000");
        SET_LAYER_INTERRUPTED(num);
      }
      return false;
    } /*«*/
    default:
    { /*»*/
      if (record->event.pressed)
      {
        inbetween_key = true;
        SET_LAYER_INTERRUPTED(sym);
        SET_LAYER_INTERRUPTED(num);
        SET_LAYER_INTERRUPTED(shiftr);
        SET_LAYER_INTERRUPTED(shiftl);
      }
      return true;
    } /*«*/
  }
}

#define KEY_SCAN_REPEAT_MOD(prefix, key) /*»*/                                      \
  if (prefix##_repeat && !prefix##_interrupted)                                      \
  {                                                                                  \
    if ((timer_elapsed(prefix##_second_press_timer) > KEY_SECOND_PRESSED_TIMEOUT) && \
        timer_elapsed(prefix##_repeat_timeout) > 25)                                 \
    {                                                                                \
      if (!prefix##_repeated)                                                        \
      {                                                                              \
        SEND_STRING(SS_UP(key##_HOLD_KEY));                                          \
        prefix##_layer_on = false;                                                   \
        prefix##_repeated = true;                                                    \
      }                                                                              \
      SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                         \
      prefix##_repeat_timeout = timer_read();                                        \
    }                                                                                \
  }                                        /*«*/
#define KEY_SCAN_REPEAT_LAYER(prefix, key) /*»*/                                    \
  if (prefix##_repeat && !prefix##_interrupted)                                      \
  {                                                                                  \
    if ((timer_elapsed(prefix##_second_press_timer) > KEY_SECOND_PRESSED_TIMEOUT) && \
        timer_elapsed(prefix##_repeat_timeout) > 25)                                 \
    {                                                                                \
      if (!prefix##_repeated)                                                        \
      {                                                                              \
        prefix##_layer_on = false;                                                   \
        layer_off(key);                                                              \
        prefix##_repeated = true;                                                    \
      }                                                                              \
      SEND_STRING(SS_TAP(key##_REPEAT_KEY));                                         \
      prefix##_repeat_timeout = timer_read();                                        \
    }                                                                                \
  } /*«*/

void matrix_scan_user(void)
{ /*»*/
  KEY_SCAN_REPEAT_MOD(shiftr, SHIFTR);
  KEY_SCAN_REPEAT_MOD(shiftl, SHIFTL);
  KEY_SCAN_REPEAT_LAYER(sym, SYM);
  KEY_SCAN_REPEAT_LAYER(num, NUM);
} /*«*/

layer_state_t layer_state_set_user(layer_state_t state)
{ /*»*/

  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  if (caps_enabled)
  {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
  }

  if (LAYER_ON_CHECK(1))
  {
    ergodox_right_led_1_on();
  }

  if (LAYER_ON_CHECK(3))
  {
    ergodox_right_led_2_on();
  }

  if (LAYER_ON_CHECK(2))
  {
    ergodox_right_led_3_on();
  }
  if (LAYER_ON_CHECK(1))
  {
    ergodox_right_led_1_on();
  }

  return state;
}; /*«*/

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record)
{ /*»*/
  switch (keycode)
  {
    case LT(WMN, KC_W):
      return true;
    default:
      return false;
  }
}
/*«*/

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t* record)
{ /*»*/
  switch (keycode)
  {
    case LT(WMN, KC_W):
      return true;
    default:
      return false;
  }
} /*«*/

