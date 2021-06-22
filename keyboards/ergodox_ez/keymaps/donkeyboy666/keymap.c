/* vim: set foldlevel=0: */

#include QMK_KEYBOARD_H
#include "version.h"

#define LAYER_ON_CHECK(layer) (state & (1 << (layer)))
#define ____ KC_NO

enum custom_keycodes /*»*/
{
  KEY_LOCK = EZ_SAFE_RANGE,
  KEY_NAVR,
  KEY_NAVL,
  KEY_WMN,
  KEY_SYM,
  KEY_NUM,
  KEY_000,
  KEY_VFTG,
  KEY_CAPS,
  KEY_SHIFTR,
  KEY_SHIFTL,
}; /*«*/

enum layers /*»*/
{
  BASE,
  NUM,
  SYM,
  NAV,
  WMN,
  UTI,
}; /*«*/

/*  shortcuts »*/
#define KEY_COPY_L LCTL(LSFT(KC_C))         /* copy for terminal */
#define KEY_FOCM LALT(LCTL(LSFT(KC_M)))     /* focus mouse to current node */
#define KEY_PASTE_L LCTL(LSFT(KC_V))        /* paste for terminal */
#define KEY_QUIT LALT(KC_Q)                 /* quit window */
#define KEY_WEBB LSFT(LCTL(KC_TAB))         /* browser previous tab */
#define KEY_WEBF LCTL(KC_TAB)               /* browser next tab */
#define KEY_WFLT LALT(RGUI(KC_SPC))         /* float */
#define KEY_WFUL LALT(RGUI(KC_ENT))         /* fullscreen */
#define KEY_WHLF LALT(RGUI(KC_H))           /* hide window */
#define KEY_WHWN LALT(LGUI(LCTL(KC_H)))     /* show hidden windows */
#define KEY_WMLB LALT(LGUI(KC_S))           /* browser */
#define KEY_WMLC LALT(LGUI(KC_E))           /* cctv */
#define KEY_WMLD LALT(LGUI(KC_D))           /* nemo */
#define KEY_WMLR LALT(LGUI(KC_Z))           /* rofi run */
#define KEY_WMLT LALT(LGUI(KC_A))           /* terminal */
#define KEY_WMLW LALT(LGUI(KC_W))           /* rofi windows */
#define KEY_WMLX LALT(LGUI(KC_X))           /* clip menu */
#define KEY_WMM1 LALT(LGUI(KC_F1))          /* monitor only */
#define KEY_WMM2 LALT(LGUI(KC_F2))          /* monitor and tv */
#define KEY_WMM3 LALT(LGUI(KC_F3))          /* tv only */
#define KEY_WMSC LCTL(LALT(LGUI(KC_K)))     /* screenshot */
#define KEY_WMSG LALT(LGUI(KC_G))           /* serach with google */
#define KEY_WMWL LALT(LCTL(LSFT(KC_LEFT)))  /* move window to previous desktop */
#define KEY_WMWR LALT(LCTL(LSFT(KC_RIGHT))) /* move window to next desktop */
#define KEY_WMWV LALT(LCTL(LSFT(KC_DOWN)))  /* move window to next monitor*/
#define KEY_WNEW LALT(LCTL(KC_N))           /* go to first empty desktop current monitor */
#define KEY_WNRT LALT(LCTL(LSFT(KC_R)))     /* rotate nodes */
#define KEY_WNSS LALT(LCTL(LSFT(KC_N)))     /* cycle between nodes current desktop */
#define KEY_WNSW LALT(LCTL(LSFT(KC_T)))     /* swap nodes */
#define KEY_WSDL LALT(LCTL(KC_LEFT))        /* previous desktop */
#define KEY_WSDR LALT(LCTL(KC_RIGHT))       /* next desktop */
#define KEY_WSDV LALT(LCTL(KC_UP))          /* swtich to next monitor desktop */
#define KEY_WTLD LALT(RGUI(KC_T))           /* tile window */
#define KEY_WWHD LCTL(LGUI(KC_H))           /* hide window */
/*«*/

/* clang-format off */ 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(/*»*/
KC_ESC, ____,         ____,         ____,         ____,          ____,     KEY_WMLC,    ____,  ____,   ____,           ____,          ____,          KC_MUTE,       KC_VOLU,
____,   ____,         KC_K,         KC_C,         KC_P,          KEY_WMLR, ____,        ____,  KC_ENT, KC_M,           KC_L,          KC_Q,          ____,          KC_VOLD,
____,   ____,         KC_U,         KC_S,         KC_T,          KC_B,                         KC_F,   KC_N,           KC_R,          KC_I,          KC_ESC,        ____, 
KC_ESC, LCTL_T(KC_A), LT(WMN,KC_W), LT(UTI,KC_G), KEY_NAVL,      KC_V,     ____,        ____,  KC_J,   KEY_NAVR,       LT(UTI,KC_X),  LT(WMN, KC_Y), RCTL_T(KC_O),  KC_ESC,
____,   KC_LSFT,      ____,         KC_LGUI,      LALT_T(KC_TAB),                                      RALT_T(KC_ENT), KC_RGUI, ____, KC_NO,         ____, 
                                                                        ____,  ____,    ____,  ____, 
                                                                               ____,    ____, 
                                                       KEY_NUM, KC_E, ____,    ____,    KEY_SYM, KEY_SHIFTR
  ),/*«*/ 

 [SYM] = LAYOUT_ergodox_pretty(/*»*/
    ____,     ____,     ____,      ____,      ____,      ____,     ____,         ____,     ____,      ____,     ____,     ____,     ____,     KEY_WMM1,  
    ____,     ____,     KC_HASH,   KC_LBRC,   KC_PERC,   KC_NO,    ____,         ____,     KC_NO,     KC_GRV,   KC_RBRC,  KC_EXLM,  ____,     KEY_WMM2, 
    ____,     KC_TRNS,  KC_QUES,   KC_ASTR,   KC_SCLN,   KC_TILDE,                         KC_NO,     KC_COLN,  KC_DQUO,  KC_QUOT,  KEY_000,  KEY_WMM3, 
    KC_TRNS,  KC_LT,    KC_LCBR,   KC_PIPE,   KC_DOT,    KC_BSLS,  ____,         ____,     KC_NO,     KC_SLSH,  KC_UNDS,  KC_RCBR,  KC_GT,    KC_TRNS,
    ____,     KC_TRNS,   ____,     KC_TRNS,   KC_TRNS,                                                KC_TRNS,  KC_TRNS,  ____,     KC_TRNS,  RESET,
                                                          ____,    ____,         ____,    ____,   
                                                                   ____,         ____,   
                                                 KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
  ),/*«*/

  [NUM] = LAYOUT_ergodox_pretty(/*»*/
    ____,     ____,     ____,    ____,     ____,     ____,     ____,      ____,     ____,     ____,     ____,     ____,     ____,     KEY_LOCK,
    ____,     ____,     KC_DLR,  KC_7,     KC_CIRC,  ____,     ____,      ____,     ____,     KC_AT,    KC_3,     KC_AMPR,    ____,     ____,   
    ____,     KC_NO,    KC_6,    KC_9,     KC_4,     KC_Z,                          KC_PLUS,  KC_1,     KC_5,     KC_2,     KEY_000,  ____,   
    KC_TRNS,  KC_8,     KC_LPRN, KC_COMM,  KC_DOT,   KC_BSLS,  ____,       ____,    KC_TRNS,  KC_EQL,   KC_MINUS, KC_RPRN,  KC_0,     KC_TRNS,
    ____,     KC_TRNS,  ____,    KC_TRNS,  KC_TRNS,                                           KC_TRNS,  KC_TRNS,  ____,     KC_TRNS,  ____,
                                                      ____,    ____,       ____,    ____,   
                                                               ____,       ____,   
                                             KC_TRNS, KC_TRNS, ____,       ____,    KC_TRNS, KC_TRNS
  ),/*«*/

 [NAV] = LAYOUT_ergodox_pretty(/*»*/    
    ____,     ____,      ____,    ____,     ____,        ____,     ____,     ____,  ____,       ____,      ____,       ____,        ____,     ____,    
    ____,     ____,      KC_NO,   KC_UP,    KC_NO,       KC_NO,    ____,     ____,  KC_TRNS,    KC_NO,     KC_UP,      KC_NO,       KC_NO,    KC_TRNS,   
    ____,     KC_NO,     KC_LEFT, KC_DOWN,  KC_RIGHT,    KC_NO,                     KC_NO,      KC_LEFT,   KC_DOWN,    KC_RIGHT,    KC_NO,    KC_NO,  
    KC_TRNS,  KC_TAB,    KC_HOME, KC_NO,   KC_END,       KC_NO,    ____,     ____,  KC_NO,      KC_HOME,   KC_NO,      KC_END,      KC_TRNS,  KC_TRNS,
    ____,     KC_TRNS,   ____,    KC_TRNS,  KC_TRNS,                                            KC_TRNS,   KC_TRNS,    ____,        KC_TRNS,  ____,
                                                          ____,    ____,     ____, ____,
                                                                   ____,     ____,
                                              KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS 
  ),/*«*/

 [UTI] = LAYOUT_ergodox_pretty(/*»*/    
    ____,     ____,      ____,     ____,     ____,     ____,        ____,     ____,   ____,       ____,      ____,       ____,        ____,     ____,    
    ____,     ____,      KEY_WMSC, KC_NO,    KEY_WMSG, KC_NO,       ____,     ____,   KC_TRNS,    KC_NO,     KC_WH_U,    KC_NO,       KC_NO,    KC_TRNS,   
    ____,     KC_NO,     KEY_VFTG, KC_NO,    KC_NO,    KC_BTN3,                       KC_NO,      KC_NO,     KC_WH_D,    KC_NO,       KC_NO,    KC_NO,  
    KC_TRNS,  KEY_WMLX,  KEY_WEBB, KC_TRNS,  KEY_WEBF, KEY_PASTE_L, ____,     ____,   KEY_COPY_L, KC_ENT,    KC_NO,      KC_DEL,      KC_TRNS,  KC_TRNS,
    ____,     KEY_WMLD,  ____,     KC_TRNS,  KC_TRNS,                                             KC_TRNS,   KC_TRNS,    ____,        KC_TRNS,  ____,
                                                           ____,    ____,     ____, ____,
                                                                    ____,     ____,
                                                  KC_TRNS, KC_TRNS, ____,     ____, KC_TRNS, KC_TRNS 
  ),/*«*/

 [WMN] = LAYOUT_ergodox_pretty(/*»*/    
    ____,     ____,     ____,    ____,     ____,      ____,     ____,      ____, ____,     ____,     ____,     ____,      ____,   KEY_WMM1,   
    ____,     ____,     KC_NO,   KEY_WMWL, KEY_WMWR,  KEY_WHWN, ____,      ____, KEY_WHLF, KEY_QUIT, KC_WH_U,  KC_NO,     ____,   KEY_WMM2, 
    ____,     KEY_WFLT, KC_NO,   KEY_WSDL, KEY_WSDR,  KEY_WWHD,                  KC_NO,    KEY_WSDL, KC_WH_D,  KEY_WSDR,  KC_NO,  KEY_WMM3,  
    KEY_WTLD, KEY_WMWV, KC_TRNS, KEY_WFUL, KEY_WNSS,  KEY_WNSW, ____,      ____, KC_NO,    KC_TAB,   KC_ENT,    KC_TRNS,   KC_NO,  KC_NO,
    ____,     KEY_WNRT, ____,    ____,     KEY_WSDV,                             ____,     ____,     ____,     KC_NO,     ____, 
                                                      ____,     ____,      ____, ____, 
                                                                ____,      ____, 
                                        KEY_WNEW, KEY_WMLW, KEY_QUIT,      ____,  KEY_WMLB, KEY_WMLT
  )/*«*/
};
/* clang-format on */

static bool keyboard_locked = false;
static bool caps_enabled = false;
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
#define SYM_HOLD_KEY X_RSFT
KEY_REPEAT_DEFINES(SYM)

#define NAV_REPEAT_KEY_D X_D
#define NAV_REPEAT_KEY_H X_H
#define NAV_HOLD_KEY X_RSFT
KEY_REPEAT_DEFINES(NAV)

#define NUM_REPEAT_KEY X_ENT
#define NUM_HOLD_KEY X_RSFT
KEY_REPEAT_DEFINES(NUM)

#define SHIFTL_REPEAT_KEY X_ENT
#define SHIFTL_HOLD_KEY X_LSFT
KEY_REPEAT_DEFINES(SHIFTL)

#define SHIFTR_REPEAT_KEY X_BSPC
#define SHIFTR_HOLD_KEY X_RSFT
KEY_REPEAT_DEFINES(SHIFTR)
static bool shift_is_on = false;

#define KEY_MOD_REPEAT(prefix) /*»*/                                                             \
  case KEY_##prefix:                                                                              \
  {                                                                                               \
    if (record->event.pressed)                                                                    \
    {                                                                                             \
      inbetween_key = false;                                                                      \
      prefix##_layer_on = true;                                                                   \
      SEND_STRING(SS_DOWN(prefix##_HOLD_KEY));                                                    \
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
        SEND_STRING(SS_UP(prefix##_HOLD_KEY));                                                    \
        if (!prefix##_interrupted)                                                                \
        {                                                                                         \
          if (!prefix##_second_press && timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT) \
          {                                                                                       \
            SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                             \
            inbetween_key = true;                                                                 \
          }                                                                                       \
          else                                                                                    \
          {                                                                                       \
            if (prefix##_second_press &&                                                          \
                timer_elapsed(prefix##_second_press_timer) < REPEAT_TIMEOUT && !inbetween_key)    \
            {                                                                                     \
              SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                           \
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
  }                              /*«*/
#define KEY_LAYER_REPEAT(prefix) /*»*/                                                           \
  case KEY_##prefix:                                                                              \
  {                                                                                               \
    if (record->event.pressed)                                                                    \
    {                                                                                             \
      if (SHIFTR_layer_on)                                                                        \
      {                                                                                           \
        SHIFTR_interrupted = true;                                                                \
        shift_is_on = true;                                                                       \
      }                                                                                           \
      prefix##_layer_on = true;                                                                   \
      layer_on(prefix);                                                                           \
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
        layer_off(prefix);                                                                        \
        if (!prefix##_interrupted)                                                                \
        {                                                                                         \
          if (!prefix##_second_press && timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT) \
          {                                                                                       \
            if (shift_is_on && !SHIFTR_layer_on)                                                  \
            {                                                                                     \
              SEND_STRING(SS_DOWN(prefix##_HOLD_KEY));                                            \
            }                                                                                     \
            SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                             \
            inbetween_key = true;                                                                 \
            if (shift_is_on && !SHIFTR_layer_on)                                                  \
            {                                                                                     \
              SEND_STRING(SS_UP(prefix##_HOLD_KEY));                                              \
            }                                                                                     \
          }                                                                                       \
          else                                                                                    \
          {                                                                                       \
            if (prefix##_second_press &&                                                          \
                timer_elapsed(prefix##_second_press_timer) < REPEAT_TIMEOUT)                      \
            {                                                                                     \
              if (shift_is_on && !SHIFTR_layer_on)                                                \
              {                                                                                   \
                SEND_STRING(SS_DOWN(prefix##_HOLD_KEY));                                          \
              }                                                                                   \
              SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                           \
              inbetween_key = true;                                                               \
              if (shift_is_on && !SHIFTR_layer_on)                                                \
              {                                                                                   \
                SEND_STRING(SS_UP(prefix##_HOLD_KEY));                                            \
              }                                                                                   \
            }                                                                                     \
            prefix##_do_2nd_tap = false;                                                          \
            prefix##_repeat = false;                                                              \
          }                                                                                       \
          shift_is_on = false;                                                                    \
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
  }                                            /*«*/
#define KEY_LAYER_REPEAT_WITH_KEY(prefix, key) /*»*/                                           \
  if (record->event.pressed)                                                                    \
  {                                                                                             \
    if (SHIFTL_layer_on || SHIFTR_layer_on)                                                     \
    {                                                                                           \
      SHIFTR_interrupted = true;                                                                \
      shift_is_on = true;                                                                       \
    }                                                                                           \
    prefix##_layer_on = true;                                                                   \
    layer_on(prefix);                                                                           \
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
      layer_off(prefix);                                                                        \
      if (!prefix##_interrupted)                                                                \
      {                                                                                         \
        if (!prefix##_second_press && timer_elapsed(prefix##_seq_start_timer) < REPEAT_TIMEOUT) \
        {                                                                                       \
          if (shift_is_on && (!SHIFTR_layer_on || !SHIFTL_layer_on))                            \
          {                                                                                     \
            register_code(KC_LSFT);                                                             \
          }                                                                                     \
          SEND_STRING(SS_TAP(key));                                                             \
          inbetween_key = true;                                                                 \
          if (shift_is_on && !SHIFTR_layer_on)                                                  \
          {                                                                                     \
            unregister_code(KC_LSFT);                                                           \
          }                                                                                     \
        }                                                                                       \
        else                                                                                    \
        {                                                                                       \
          if (prefix##_second_press &&                                                          \
              timer_elapsed(prefix##_second_press_timer) < REPEAT_TIMEOUT)                      \
          {                                                                                     \
            if (shift_is_on && !SHIFTR_layer_on)                                                \
            {                                                                                   \
              SEND_STRING(SS_DOWN(X_LSFT));                                                     \
            }                                                                                   \
            SEND_STRING(SS_TAP(key));                                                           \
            inbetween_key = true;                                                               \
            NAV_interrupted = true;                                                             \
            if (shift_is_on && !SHIFTR_layer_on)                                                \
            {                                                                                   \
              SEND_STRING(SS_UP(X_LSFT));                                                       \
            }                                                                                   \
          }                                                                                     \
          prefix##_do_2nd_tap = false;                                                          \
          prefix##_repeat = false;                                                              \
        }                                                                                       \
        shift_is_on = false;                                                                    \
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
  return false; /*«*/

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
          NUM_layer_on = false;
          NUM_repeat = false;
          NUM_interrupted = false;
          layer_off(NUM);
        }
        else
        {
          keyboard_locked = true;
          NUM_interrupted = true;
        }
      }
      return false;
    } /*«*/

      KEY_MOD_REPEAT(SHIFTR);
      KEY_LAYER_REPEAT(SYM);
      KEY_LAYER_REPEAT(NUM);

    case KEY_NAVL:
      KEY_LAYER_REPEAT_WITH_KEY(NAV, X_D);
    case KEY_NAVR:
      KEY_LAYER_REPEAT_WITH_KEY(NAV, X_H);

      KEY_MOD_REPEAT(SHIFTL);

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
    case KEY_VFTG:
    { /*»*/
      if (record->event.pressed)
      {
        SEND_STRING("za");
        SET_LAYER_INTERRUPTED(NUM);
      }
      return false;
    } /*«*/
    case KEY_000:
    { /*»*/
      if (record->event.pressed)
      {
        SEND_STRING("000");
        SET_LAYER_INTERRUPTED(NUM);
      }
      return false;
    } /*«*/
    default:
    { /*»*/
      if (record->event.pressed)
      {
        inbetween_key = true;
        SET_LAYER_INTERRUPTED(SYM);
        SET_LAYER_INTERRUPTED(NUM);
        SET_LAYER_INTERRUPTED(NAV);
        SET_LAYER_INTERRUPTED(SHIFTR);
        SET_LAYER_INTERRUPTED(SHIFTL);
      }
      return true;
    } /*«*/
  }
}

#define KEY_SCAN_REPEAT_MOD(prefix) /*»*/                                           \
  if (prefix##_repeat && !prefix##_interrupted)                                      \
  {                                                                                  \
    if ((timer_elapsed(prefix##_second_press_timer) > KEY_SECOND_PRESSED_TIMEOUT) && \
        timer_elapsed(prefix##_repeat_timeout) > 25)                                 \
    {                                                                                \
      if (!prefix##_repeated)                                                        \
      {                                                                              \
        SEND_STRING(SS_UP(prefix##_HOLD_KEY));                                       \
        prefix##_layer_on = false;                                                   \
        prefix##_repeated = true;                                                    \
      }                                                                              \
      SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                      \
      prefix##_repeat_timeout = timer_read();                                        \
    }                                                                                \
  }                                   /*«*/
#define KEY_SCAN_REPEAT_LAYER(prefix) /*»*/                                         \
  if (prefix##_repeat && !prefix##_interrupted)                                      \
  {                                                                                  \
    if ((timer_elapsed(prefix##_second_press_timer) > KEY_SECOND_PRESSED_TIMEOUT) && \
        timer_elapsed(prefix##_repeat_timeout) > 25)                                 \
    {                                                                                \
      if (!prefix##_repeated)                                                        \
      {                                                                              \
        prefix##_layer_on = false;                                                   \
        layer_off(prefix);                                                           \
        prefix##_repeated = true;                                                    \
      }                                                                              \
      SEND_STRING(SS_TAP(prefix##_REPEAT_KEY));                                      \
      prefix##_repeat_timeout = timer_read();                                        \
    }                                                                                \
  } /*«*/

void matrix_scan_user(void)
{ /*»*/
  KEY_SCAN_REPEAT_MOD(SHIFTR);
  KEY_SCAN_REPEAT_MOD(SHIFTL);
  KEY_SCAN_REPEAT_LAYER(SYM);
  KEY_SCAN_REPEAT_LAYER(NUM);
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
    case RCTL_T(KC_O):
      return true;
    case LCTL_T(KC_O):
      return true;
    case LCTL_T(KC_A):
      return true;
    case LT(UTI, KC_X):
      return true;
    case LT(UTI, KC_G):
      return true;
    case LT(NAV, KC_H):
      return true;
    case LT(NAV, KC_D):
      return true;
    case LT(WMN, KC_Y):
      return true;
    case LT(WMN, KC_W):
      return true;
    default:
      return true;
  }
} /*«*/

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t* record)
{ /*»*/
  switch (keycode)
  {
    case RCTL_T(KC_O):
      return true;
    case LCTL_T(KC_O):
      return true;
    case LCTL_T(KC_A):
      return true;
    case LT(UTI, KC_X):
      return true;
    case LT(UTI, KC_G):
      return true;
    case LT(NAV, KC_H):
      return true;
    case LT(NAV, KC_D):
      return true;
    case LT(WMN, KC_Y):
      return true;
    case LT(WMN, KC_W):
      return true;
    default:
      return true;
  }
} /*«*/
