#ifndef __BACKPORT_LINUX_STRING_H
#define __BACKPORT_LINUX_STRING_H
#include_next <linux/string.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,6,0)
int match_string(const char * const *array, size_t n, const char *string);
#endif /* LINUX_VERSION_IS_LESS(4,5,0) */

#endif /* __BACKPORT_LINUX_STRING_H */
