#ifndef _MONOGLYPH_H
#define _MONOGLYPH_H

struct MonoGlyph{
	struct Glyph* pComponent;
	struct glyph_operations *gly_ops;
};


#endif
