#include <zephyr/kernel.h>
#include <zmk/event_manager.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/events/position_state_changed.h>
#include <zmk/keymap.h>

static int layer_listener(const zmk_event_t *eh) {
    const struct zmk_layer_state_changed *ev = as_zmk_layer_state_changed(eh);
    if (ev) {
        printk("ZMK_LAYER:%d\n", zmk_keymap_highest_layer_active());
    }
    return ZMK_EV_EVENT_BUBBLE;
}

static int position_listener(const zmk_event_t *eh) {
    const struct zmk_position_state_changed *ev = as_zmk_position_state_changed(eh);
    if (ev) {
        printk("ZMK_KEY_%s:%d\n", ev->state ? "DOWN" : "UP", ev->position);
    }
    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(layer_reporter, layer_listener);
ZMK_SUBSCRIPTION(layer_reporter, zmk_layer_state_changed);

ZMK_LISTENER(position_reporter, position_listener);
ZMK_SUBSCRIPTION(position_reporter, zmk_position_state_changed);
