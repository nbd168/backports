#ifndef __BACKPORT_LINUX_THERMAL_H
#define __BACKPORT_LINUX_THERMAL_H
#include_next <linux/thermal.h>
#include <linux/version.h>

#ifdef CONFIG_THERMAL
#if LINUX_VERSION_IS_LESS(5,9,0)
static inline int thermal_zone_device_enable(struct thermal_zone_device *tz)
{ return 0; }
#endif /* < 5.9.0 */
#else /* CONFIG_THERMAL */
#if LINUX_VERSION_IS_LESS(5,9,0)
static inline int thermal_zone_device_enable(struct thermal_zone_device *tz)
{ return -ENODEV; }
#endif /* < 5.9.0 */
#endif /* CONFIG_THERMAL */

#if LINUX_VERSION_IS_LESS(5,9,0)
#define thermal_zone_device_enable LINUX_BACKPORT(thermal_zone_device_enable)
static inline int thermal_zone_device_enable(struct thermal_zone_device *tz)
{ return 0; }

#define thermal_zone_device_disable LINUX_BACKPORT(thermal_zone_device_disable)
static inline int thermal_zone_device_disable(struct thermal_zone_device *tz)
{ return 0; }
#endif /* < 5.9 */

#if LINUX_VERSION_IS_LESS(6,4,0)
#define thermal_zone_device_priv LINUX_BACKPORT(thermal_zone_device_priv)
static inline void *thermal_zone_device_priv(struct thermal_zone_device *tzd)
{
#ifdef CONFIG_THERMAL
	return tzd->devdata;
#else
	return NULL;
#endif
}
#endif

#if LINUX_VERSION_IS_LESS(6,6,0)
#define for_each_thermal_trip LINUX_BACKPORT(for_each_thermal_trip)
static inline int for_each_thermal_trip(struct thermal_zone_device *tz,
					int (*cb)(struct thermal_trip *, void *),
					void *data)
{
	int i, ret;

	if (!tz->num_trips)
		return -ENODATA;

	for (i = 0; i < tz->num_trips; i++) {
		ret = cb(&tz->trips[i], data);
		if (ret)
			return ret;
	}

	return 0;
}
#endif /* < 6.6 */

#endif /* __BACKPORT_LINUX_THERMAL_H */
