#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_SYMBOLS (1 << 1)
#define L_NUMBERS (1 << 2)
#define L_NAVIGATION (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_NUMBERS | L_SYMBOLS)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
    case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case L_SYMBOLS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SYMBOLS");
    break;
  case L_NUMBERS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: NUMBERS");
    break;
  case L_NAVIGATION:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: NAVIGATION");
    break;
  case L_ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
    break;
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
