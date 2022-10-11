#ifndef __BACKPORT_NETDEVICE_H
#define __BACKPORT_NETDEVICE_H
#include_next <linux/netdevice.h>
#include <linux/version.h>
#include <backport/magic.h>

#if LINUX_VERSION_IS_LESS(4,15,0)
static inline int _bp_netdev_upper_dev_link(struct net_device *dev,
					    struct net_device *upper_dev)
{
	return netdev_upper_dev_link(dev, upper_dev);
}
#define netdev_upper_dev_link3(dev, upper, extack) \
	netdev_upper_dev_link(dev, upper)
#define netdev_upper_dev_link2(dev, upper) \
	netdev_upper_dev_link(dev, upper)
#define netdev_upper_dev_link(...) \
	macro_dispatcher(netdev_upper_dev_link, __VA_ARGS__)(__VA_ARGS__)
#endif

#if LINUX_VERSION_IS_LESS(4,19,0)
static inline void netif_receive_skb_list(struct sk_buff_head *head)
{
	struct sk_buff *skb, *next;

	skb_queue_walk_safe(head, skb, next) {
		__skb_unlink(skb, head);
		netif_receive_skb(skb);
	}
}
#endif

#if LINUX_VERSION_IS_LESS(5,0,0)
static inline int backport_dev_open(struct net_device *dev, struct netlink_ext_ack *extack)
{
	return dev_open(dev);
}
#define dev_open LINUX_BACKPORT(dev_open)
#endif

#if LINUX_VERSION_IS_LESS(5,10,0)
#define dev_fetch_sw_netstats LINUX_BACKPORT(dev_fetch_sw_netstats)
void dev_fetch_sw_netstats(struct rtnl_link_stats64 *s,
			   const struct pcpu_sw_netstats __percpu *netstats);

#define netif_rx_any_context LINUX_BACKPORT(netif_rx_any_context)
int netif_rx_any_context(struct sk_buff *skb);

static inline void dev_sw_netstats_rx_add(struct net_device *dev, unsigned int len)
{
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->rx_bytes += len;
	tstats->rx_packets++;
	u64_stats_update_end(&tstats->syncp);
}

#endif /* < 5.10 */

#if LINUX_VERSION_IS_LESS(5,10,0)
static inline void dev_sw_netstats_tx_add(struct net_device *dev,
					  unsigned int packets,
					  unsigned int len)
{
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->tx_bytes += len;
	tstats->tx_packets += packets;
	u64_stats_update_end(&tstats->syncp);
}
#endif /* < 5.10 */

#if LINUX_VERSION_IS_LESS(5,10,0)
#define dev_sw_netstats_rx_add LINUX_BACKPORT(dev_sw_netstats_rx_add)
static inline void dev_sw_netstats_rx_add(struct net_device *dev, unsigned int len)
{
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->rx_bytes += len;
	tstats->rx_packets++;
	u64_stats_update_end(&tstats->syncp);
}
#endif /* < 5.10 */

#if LINUX_VERSION_IS_LESS(5,11,0)
#define dev_sw_netstats_tx_add LINUX_BACKPORT(dev_sw_netstats_tx_add)
static inline void dev_sw_netstats_tx_add(struct net_device *dev,
					  unsigned int packets,
					  unsigned int len)
{
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->tx_bytes += len;
	tstats->tx_packets += packets;
	u64_stats_update_end(&tstats->syncp);
}
#endif /* < 5.11 */

#if LINUX_VERSION_IS_LESS(5,11,0)
#define dev_get_tstats64 LINUX_BACKPORT(dev_get_tstats64)
void dev_get_tstats64(struct net_device *dev, struct rtnl_link_stats64 *s);
#endif /* < 5.11 */

#if LINUX_VERSION_IS_LESS(5,15,0)
#define get_user_ifreq LINUX_BACKPORT(get_user_ifreq)
int get_user_ifreq(struct ifreq *ifr, void __user **ifrdata, void __user *arg);
#define put_user_ifreq LINUX_BACKPORT(put_user_ifreq)
int put_user_ifreq(struct ifreq *ifr, void __user *arg);
#endif

#if LINUX_VERSION_IS_LESS(5,15,0)
static inline void backport_dev_put(struct net_device *dev)
{
	if (dev)
		dev_put(dev);
}
#define dev_put LINUX_BACKPORT(dev_put)

static inline void backport_dev_hold(struct net_device *dev)
{
	if (dev)
		dev_hold(dev);
}
#define dev_hold LINUX_BACKPORT(dev_hold)
#endif /* < 5.15 */

#endif /* __BACKPORT_NETDEVICE_H */
