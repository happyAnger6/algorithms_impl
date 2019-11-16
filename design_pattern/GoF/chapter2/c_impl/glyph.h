#ifndef _GLYPH_H
#define _GLYPH_H

struct Glyph{
	const char *name;
	const struct glyph_operations *glyph_op;
	void *private_data;
};

struct Rect;
struct Window;
struct Point;

struct glyph_operations {
	void Draw(struct Glyph*, Window* window);	
	void Bounds(struct Glyph*, Rect* rect);
	void Intersects(struct Glyph*, Point* point);
	void Insert(struct Glyph*, struct Glyph*, int);
	void Remove(struct Glyph*, struct Glyph*);
	void Glyph* Child(struct Glyph*, int);
	void Glyph* Parent(struct Glyph*);
};

#endif

