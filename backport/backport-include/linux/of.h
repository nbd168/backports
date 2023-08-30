#ifndef __LINUX_BACKPORT_OF_H
#define __LINUX_BACKPORT_OF_H
#include <linux/version.h>
#include_next <linux/of.h>

#if LINUX_VERSION_IS_LESS(6,3,0)
#define of_property_present of_property_read_bool
#endif

#endif
