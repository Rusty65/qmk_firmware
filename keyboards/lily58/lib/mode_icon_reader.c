#include <stdio.h>
#include <stdbool.h>

char mode_icon[24];

const char *read_mode_icon(bool swap) {
  static char logo[][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x99, 0x9a, 0}, {0xb9, 0xba, 0}}};
  if (swap == true) {
    snprintf(mode_icon, sizeof(mode_icon), "%s\n%s", logo[0][0], logo[0][1]);
  } else {
    snprintf(mode_icon, sizeof(mode_icon), "%s\n%s", logo[1][0], logo[1][1]);
  }

  return mode_icon;
}
