#ifndef __BACKPORT_LINUX_STRING_H
#define __BACKPORT_LINUX_STRING_H
#include_next <linux/string.h>
#include <linux/args.h>

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

#if LINUX_VERSION_IS_LESS(6,9,0)
#undef strscpy
#define __strscpy0(dst, src, ...)	\
	strscpy(dst, src, sizeof(dst) + __must_be_array(dst))
#define __strscpy1(dst, src, size)	strscpy(dst, src, size)
#define strscpy(dst, src, ...) \
	CONCATENATE(__strscpy, COUNT_ARGS(__VA_ARGS__))(dst, src, __VA_ARGS__)

#undef strscpy_pad
#define __strscpy_pad0(dst, src, ...)	\
	strscpy_pad(dst, src, sizeof(dst) + __must_be_array(dst))
#define __strscpy_pad1(dst, src, size)	strscpy_pad(dst, src, size)
#define strscpy_pad(dst, src, ...)	\
	CONCATENATE(__strscpy_pad, COUNT_ARGS(__VA_ARGS__))(dst, src, __VA_ARGS__)

#endif /* <6.9 */

#endif /* __BACKPORT_LINUX_STRING_H */
