#ifndef __BACKPORT_DROPREASON_CORE_H
#define __BACKPORT_DROPREASON_CORE_H

#include <linux/version.h>

#if LINUX_VERSION_IS_GEQ(6,4,0)
#include_next <net/dropreason-core.h>
#elif LINUX_VERSION_IS_GEQ(6,0,0)
#include <net/dropreason.h>
#else
#include <linux/skbuff.h>
#endif

#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(5,18,0)
#define SKB_NOT_DROPPED_YET SKB_DROP_REASON_MAX
#endif

#if LINUX_VERSION_IS_LESS(6,2,0)
#define SKB_CONSUMED SKB_DROP_REASON_NOT_SPECIFIED
#endif

#if LINUX_VERSION_IS_LESS(6,4,0)
#define SKB_DROP_REASON_SUBSYS_MASK			0xffff0000
#define SKB_DROP_REASON_SUBSYS_SHIFT			16
#endif

#endif
