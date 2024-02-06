#ifndef __BACKPORT_LINUX_NETLINK_H
#define __BACKPORT_LINUX_NETLINK_H
#include_next <linux/netlink.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,14,0)
struct nla_bitfield32 {
	__u32 value;
	__u32 selector;
};
#endif

#ifndef NL_SET_ERR_MSG_ATTR
#define NL_SET_ERR_MSG_ATTR(extack, attr, msg) do {	\
	static const char __msg[] = msg;		\
	struct netlink_ext_ack *__extack = (extack);	\
							\
	if (__extack) {					\
		__extack->_msg = __msg;			\
		__extack->bad_attr = (attr);		\
	}						\
} while (0)
#endif


#ifndef NL_SET_BAD_ATTR
#define NL_SET_BAD_ATTR(extack, attr) do {		\
	if ((extack))					\
		(extack)->bad_attr = (attr);		\
} while (0)
#endif /* NL_SET_BAD_ATTR */

#if LINUX_VERSION_IS_LESS(5,0,0)
static inline void nl_set_extack_cookie_u64(struct netlink_ext_ack *extack,
					    u64 cookie)
{
	u64 __cookie = cookie;

	memcpy(extack->cookie, &__cookie, sizeof(__cookie));
	extack->cookie_len = sizeof(__cookie);
}
#endif

#endif /* __BACKPORT_LINUX_NETLINK_H */
