#include <zephyr/kernel.h>
#include <zmk/event_manager.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/keymap.h>

static int layer_listener(const zmk_event_t *eh) {
    const struct zmk_layer_state_changed *ev = as_zmk_layer_state_changed(eh);
    if (ev) {
        printk("ZMK_LAYER:%d\n", zmk_keymap_highest_layer_active());
    }
    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(layer_reporter, layer_listener);
ZMK_SUBSCRIPTION(layer_reporter, zmk_layer_state_changed);
