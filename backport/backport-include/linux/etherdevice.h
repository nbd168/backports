#ifndef _BACKPORT_LINUX_ETHERDEVICE_H
#define _BACKPORT_LINUX_ETHERDEVICE_H
#include_next <linux/etherdevice.h>
#include <linux/version.h>
#include <linux/property.h>

#if LINUX_VERSION_IS_LESS(5,15,0)
/**
 * eth_hw_addr_set - Assign Ethernet address to a net_device
 * @dev: pointer to net_device structure
 * @addr: address to assign
 *
 * Assign given address to the net_device, addr_assign_type is not changed.
 */
static inline void eth_hw_addr_set(struct net_device *dev, const u8 *addr)
{
	ether_addr_copy(dev->dev_addr, addr);
}
#endif /* LINUX_VERSION_IS_LESS(5,15,0) */

#if LINUX_VERSION_IS_LESS(5,16,0)
static inline int backport_device_get_mac_address(struct device *dev, char *addr)
{
	if (!device_get_mac_address(dev, addr, ETH_ALEN))
		return -ENOENT;

	return 0;
}
#define device_get_mac_address LINUX_BACKPORT(device_get_mac_address)
#endif /* LINUX_VERSION_IS_LESS(5,16,0) */

#endif /* _BACKPORT_LINUX_ETHERDEVICE_H */
