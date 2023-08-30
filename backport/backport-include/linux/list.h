#ifndef __BACKPORT_LINUX_LIST_H
#define __BACKPORT_LINUX_LIST_H
#include_next <linux/list.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(6,3,0)
/**
 * list_count_nodes - count nodes in the list
 * @head:	the head for your list.
 */
static inline size_t list_count_nodes(struct list_head *head)
{
	struct list_head *pos;
	size_t count = 0;

	list_for_each(pos, head)
		count++;

	return count;
}
#endif /* < 6.3 */

#endif
