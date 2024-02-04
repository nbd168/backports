#ifndef __BACKPORT_KERNEL_H
#define __BACKPORT_KERNEL_H
#include_next <linux/kernel.h>
/* needed to include BUILD_BUG_ON_ZERO on <= 4.12 */
#include <linux/bug.h>
#include <linux/version.h>


#if LINUX_VERSION_IS_LESS(4,6,0)
#define kstrtobool LINUX_BACKPORT(kstrtobool)
int __must_check kstrtobool(const char *s, bool *res);
#define kstrtobool_from_user LINUX_BACKPORT(kstrtobool_from_user)
int __must_check kstrtobool_from_user(const char __user *s, size_t count, bool *res);
#endif

#endif /* __BACKPORT_KERNEL_H */
