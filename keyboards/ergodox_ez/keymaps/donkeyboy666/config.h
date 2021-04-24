/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define FIRMWARE_VERSION u8"yE03P/xLwN0"
//#define RETRO_TAPPING
#undef TAPPING_TERM
#define TAPPING_TERM 300

#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#undef LED_BRIGHTNESS_LO
#define LED_BRIGHTNESS_LO 1
#undef LED_BRIGHTNESS_HI
#define LED_BRIGHTNESS_HI 255
#undef LED_BRIGHTNESS_DEFAULT
#define LED_BRIGHTNESS_DEFAULT (LED_BRIGHTNESS_LO)
