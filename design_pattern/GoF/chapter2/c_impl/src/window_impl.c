#include "window_impl.h"


static const struct window_impl_operations Micro_Window_Impl = {
    void mirco_window_redraw();
    void mirco_window_raise();
    void mirco_window_lower();
    void mirco_window_iconify();
    void mirco_window_deiconify();
    void mirco_window_drawline();
    void mirco_window_drawrect();
    void mirco_window_drawpolygon();
    void mirco_window_drawtext();
};
