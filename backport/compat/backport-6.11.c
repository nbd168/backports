// SPDX-License-Identifier: GPL-2.0

#include <linux/export.h>
#include <linux/netdevice.h>

#if LINUX_VERSION_IS_LESS(6,11,0)

static void init_dummy_netdev_core(struct net_device *dev)
{
	dev->reg_state = NETREG_DUMMY;
	INIT_LIST_HEAD(&dev->napi_list);
	set_bit(__LINK_STATE_PRESENT, &dev->state);
	set_bit(__LINK_STATE_START, &dev->state);
	dev_net_set(dev, &init_net);
}

struct net_device *alloc_netdev_dummy(int sizeof_priv)
{
	return alloc_netdev(sizeof_priv, "dummy#", NET_NAME_UNKNOWN,
			    init_dummy_netdev_core);
}
EXPORT_SYMBOL_GPL(alloc_netdev_dummy);

#endif /* <6.11 */
