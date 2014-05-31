#ifndef __BACKPORT_LINUX_IRQ_H
#define __BACKPORT_LINUX_IRQ_H
#include_next <linux/irq.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,11,0)
static inline u32 irq_get_trigger_type(unsigned int irq)
{
	struct irq_data *d = irq_get_irq_data(irq);
	return d ? irqd_get_trigger_type(d) : 0;
}
#endif

#endif /* __BACKPORT_LINUX_IRQ_H */