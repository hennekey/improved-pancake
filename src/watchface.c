#include <pebble.h>
#include "time.c"
#include "weather.c"

static Window *window;
static TextLayer *timeLayer;
static TextLayer *weatherLayer;

static void tickHandler(struct tm *tickTime, TimeUnits unitsChanged) {
  updateTime(tickTime, timeLayer);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  timeLayer = initTimeLayer(bounds);
  weatherLayer = initWeatherLayer(bounds);
  layer_add_child(window_layer, text_layer_get_layer(timeLayer));
  layer_add_child(window_layer, text_layer_get_layer(weatherLayer));
}

static void window_unload(Window *window) {
  text_layer_destroy(timeLayer);
  text_layer_destroy(weatherLayer);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
  time_t temp = time(NULL);
  updateTime(localtime(&temp), timeLayer);
  tick_timer_service_subscribe(MINUTE_UNIT, tickHandler);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
