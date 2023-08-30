#ifndef __BACKPORT_DROPREASON_H
#define __BACKPORT_DROPREASON_H

#include <linux/version.h>

#if LINUX_VERSION_IS_GEQ(6,0,0)
#include_next <net/dropreason.h>
#else
#include <net/dropreason-core.h>
#endif

#if LINUX_VERSION_IS_LESS(6,4,0)
/**
 * enum skb_drop_reason_subsys - subsystem tag for (extended) drop reasons
 */
enum skb_drop_reason_subsys {
	/** @SKB_DROP_REASON_SUBSYS_CORE: core drop reasons defined above */
	SKB_DROP_REASON_SUBSYS_CORE,

	/**
	 * @SKB_DROP_REASON_SUBSYS_MAC80211_UNUSABLE: mac80211 drop reasons
	 * for unusable frames, see net/mac80211/drop.h
	 */
	SKB_DROP_REASON_SUBSYS_MAC80211_UNUSABLE,

	/**
	 * @SKB_DROP_REASON_SUBSYS_MAC80211_MONITOR: mac80211 drop reasons
	 * for frames still going to monitor, see net/mac80211/drop.h
	 */
	SKB_DROP_REASON_SUBSYS_MAC80211_MONITOR,

	/** @SKB_DROP_REASON_SUBSYS_NUM: number of subsystems defined */
	SKB_DROP_REASON_SUBSYS_NUM
};

struct drop_reason_list {
	const char * const *reasons;
	size_t n_reasons;
};

#define drop_reasons_register_subsys LINUX_BACKPORT(drop_reasons_register_subsys)
static inline void
drop_reasons_register_subsys(enum skb_drop_reason_subsys subsys,
			     const struct drop_reason_list *list)
{
}

#define drop_reasons_unregister_subsys LINUX_BACKPORT(drop_reasons_unregister_subsys)
static inline void
drop_reasons_unregister_subsys(enum skb_drop_reason_subsys subsys)
{
}
#endif /* <6.4 */

#endif
