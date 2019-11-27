#ifndef _WINDOW_IMPL_H
#define _WINDOW_IMPL_H

struct window_impl_operations = {
    void Redraw();
    void Raise();
    void Lower();
    void Iconify();
    void Deiconfiy();
    void DrawLine();
    void DrawRect();
    void DrawPolygon();
    void DrawText();
};

#endif

