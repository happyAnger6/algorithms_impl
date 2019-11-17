#include "compositor.h"

static const struct compositor_operations array_compositor_ops = {
	.Compositor = array_compositor,
	.Compose = array_compose,
	.SetComposition = array_setcomposition,
};

static void array_compositor(struct Compositor * pComp)
{
	pComp->composo_op = &array_compositor_ops;	
}

static void array_compose(struct Compositor *)
{

}

static void array_setcomposition(struct Compositor *)
{

}

