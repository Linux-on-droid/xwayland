#ifndef XWAYLAND_GLAMOR_HYBRIS_H
#define XWAYLAND_GLAMOR_HYBRIS_H

#include <xwayland-config.h>

#include <sys/types.h>

#include <xf86drm.h>

#include "xwayland-types.h"

Bool xwl_glamor_init_hybris(struct xwl_screen *xwl_screen);
Bool xwl_glamor_hybris_init_egl(struct xwl_screen *xwl_screen);
Bool xwl_glamor_hybris_init_screen(struct xwl_screen *xwl_screen);

#endif /* XWAYLAND_GLAMOR_HYBRIS_H */
