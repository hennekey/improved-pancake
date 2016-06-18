#include <pebble.h>

static TextLayer* initTimeLayer(GRect bounds) {
  TextLayer *timeLayer = text_layer_create(GRect(0, 52, bounds.size.w, 50));
  text_layer_set_text_color(timeLayer, GColorBlack);
  text_layer_set_font(timeLayer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(timeLayer, GTextAlignmentCenter);
  return timeLayer;
}

static void updateTime(struct tm *tickTime, TextLayer* timeLayer) {
  static char s_buffer[8];
  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tickTime);

  text_layer_set_text(timeLayer, s_buffer);
}
