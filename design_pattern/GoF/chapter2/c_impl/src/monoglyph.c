#include "glyph.h"
#include "monoglyph.h"

void monoglyph_draw(struct Glyph*, Window* window)
{

}

const static struct glyph_operations mono_glyph_ops = {
	.Draw = monoglyph_draw,
}; 
