#ifndef _COMPAT_LINUX_VIRTIO_CONFIG_H
#define _COMPAT_LINUX_VIRTIO_CONFIG_H
#include_next <linux/virtio_config.h>

#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,12,0)
static inline
int virtio_find_vqs(struct virtio_device *vdev, unsigned nvqs,
			struct virtqueue *vqs[], vq_callback_t *callbacks[],
			const char *names[],
			struct irq_affinity *desc)
{
	return vdev->config->find_vqs(vdev, nvqs, vqs, callbacks, names, desc);
}
#endif /* < 4.12 */


#endif	/* _COMPAT_LINUX_VIRTIO_CONFIG_H */
