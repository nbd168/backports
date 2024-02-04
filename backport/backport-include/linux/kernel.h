#ifndef __BACKPORT_KERNEL_H
#define __BACKPORT_KERNEL_H
#include_next <linux/kernel.h>
/* needed to include BUILD_BUG_ON_ZERO on <= 4.12 */
#include <linux/bug.h>

#endif /* __BACKPORT_KERNEL_H */
