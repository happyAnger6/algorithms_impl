#ifndef _COMPOSITOR_H
#define _COMPOSITOR_H

#include "glyph.h"

struct Composition;

struct Compositor{
	struct compositor_operations *composo_op;
	struct Composition *pComposition;
	void *private_data;
};

struct compositor_operatins{
	void Compositor(struct Compositor *);
	void Compose(struct Compositor *);
	void SetComposition(struct Compositor *, struct Composition*);
};


#endif
