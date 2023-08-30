#ifndef __BACKPORT_DEVICE_CLASS_H
#define __BACKPORT_DEVICE_CLASS_H
#include <linux/version.h>
#include_next <linux/device/class.h>

#if LINUX_VERSION_IS_LESS(6,4,0)

#undef class_create
#define class_create(name)			\
({						\
    static struct lock_class_key __key;		\
    __class_create(THIS_MODULE, name, &__key);	\
})

#endif

#endif
