#ifndef __BP_LINUX_BITMAP_H
#define __BP_LINUX_BITMAP_H
#include_next <linux/bitmap.h>

#if LINUX_VERSION_IS_LESS(5,13,0)
struct device;
/* Managed variants of the above. */
#define devm_bitmap_alloc LINUX_BACKPORT(devm_bitmap_alloc)
unsigned long *devm_bitmap_alloc(struct device *dev,
				 unsigned int nbits, gfp_t flags);

#define devm_bitmap_zalloc LINUX_BACKPORT(devm_bitmap_zalloc)
unsigned long *devm_bitmap_zalloc(struct device *dev,
				  unsigned int nbits, gfp_t flags);

#endif

#endif /* __BP_LINUX_BITMAP_H */
