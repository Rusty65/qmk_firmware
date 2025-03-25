
LTO_ENABLE = yes            # Link Time Optimization enabled
TRI_LAYER_ENABLE = yes		# Enable tri layers
LAYER_LOCK_ENABLE = yes		# enable locking layers
TAP_DANCE_ENABLE = no		#Allow tapping keys to do something
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no      	# Mouse keys
EXTRAKEY_ENABLE = yes      	# Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = yes           # OLED display
WPM_ENABLE = yes           	# WPM counter
OS_DETECTION_ENABLE = yes	#OS dectection
EXTRAFLAGS += -flto       	#Link time optimization - https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/layer_state_reader.c \
		./lib/mode_icon_reader.c \
		#./lib/host_led_state_reader.c \
		#./lib/rgb_state_reader.c \
        #./lib/logo_reader.c \
        #./lib/keylogger.c \
        #./lib/timelogger.c \
