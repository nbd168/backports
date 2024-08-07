#ifndef __BACKPORT_LINUX_STRING_H
#define __BACKPORT_LINUX_STRING_H
#include_next <linux/string.h>

#ifndef memset_after
#define memset_after(obj, v, member)					\
({									\
	u8 *__ptr = (u8 *)(obj);					\
	typeof(v) __val = (v);						\
	memset(__ptr + offsetofend(typeof(*(obj)), member), __val,	\
	       sizeof(*(obj)) - offsetofend(typeof(*(obj)), member));	\
})
#endif

#ifndef memset_startat
#define memset_startat(obj, v, member)					\
({									\
	u8 *__ptr = (u8 *)(obj);					\
	typeof(v) __val = (v);						\
	memset(__ptr + offsetof(typeof(*(obj)), member), __val,		\
	       sizeof(*(obj)) - offsetof(typeof(*(obj)), member));	\
})
#endif

#if LINUX_VERSION_IS_LESS(6,3,0)
#define kvmemdup(src, len, gfp) \
	({								\
		void *__p = kvmalloc(len, gfp);				\
		if (__p)						\
			memcpy(__p, src, len);				\
		__p;							\
	})
#endif

#endif /* __BACKPORT_LINUX_STRING_H */
