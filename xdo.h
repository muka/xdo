#ifndef _XDO_H
#define _XDO_H

typedef enum {
    VALUE_IGNORE,
    VALUE_SAME,
    VALUE_DIFFERENT
} value_cmp_t;

typedef struct {
    value_cmp_t wid;
    value_cmp_t class;
    value_cmp_t desktop;
    uint8_t evt_code;
} config_t;

xcb_connection_t *dpy;
int default_screen;
xcb_window_t root;
xcb_ewmh_connection_t *ewmh;
config_t cfg;

void init(void);
int usage(void);
int version(void);
void setup(void);
void finish(void);
void get_atom(char *, xcb_atom_t *);
void get_active_window(xcb_window_t *);
bool get_class(xcb_window_t, char *, size_t);
bool get_desktop(xcb_window_t, uint32_t *);
bool get_current_desktop(uint32_t *);
void window_close(xcb_window_t);
void window_kill(xcb_window_t);
void window_hide(xcb_window_t);
void window_show(xcb_window_t);
void window_activate(xcb_window_t);
void fake_input(xcb_window_t, uint8_t, uint8_t);
void key_press_release(xcb_window_t);
void button_press_release(xcb_window_t);

#endif
