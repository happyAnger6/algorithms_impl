#include "rectangle.h"

struct Rect{
	struct Point x;
	struct Point y;
};

void rectangle_draw(struct Glyph *this, Window *window)
{
	struct Rect* rect = (struct Rect*)this->private_data;	
}

const struct glyph_operations rectangle_glyph_operations = {
	.Draw = rectangle_draw,
};
