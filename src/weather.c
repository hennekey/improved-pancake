#include <pebble.h>

static TextLayer* initWeatherLayer(GRect bounds) {
  TextLayer *weatherLayer = text_layer_create(GRect(0, 110, bounds.size.w, 25));
  text_layer_set_background_color(weatherLayer, GColorClear);
  text_layer_set_text_color(weatherLayer, GColorBlack);
  text_layer_set_text_alignment(weatherLayer, GTextAlignmentCenter);
  text_layer_set_text(weatherLayer, "Loading...");
  return weatherLayer;
}
