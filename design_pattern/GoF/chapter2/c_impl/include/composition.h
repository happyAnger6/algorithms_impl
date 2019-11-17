#ifndef _COMPOSITION_H
#define _COMPOSITION_H

#include "glyph.h"
#include "compositor.h"

struct Composition{
	struct Compositor *pCompose;
};

struct composition_operations {
	void Insert(struct Composition*, Glyph*, int i);
};

#endif
