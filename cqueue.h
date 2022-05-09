#ifndef __CQUEUE_H__
#define __CQUEUE_H__

/*
 * Note:	This is a FIFO circular queue.
 *			Items are being added to the "tail",
 *			and items are being taken off of the "head".
 */

typedef struct {
	void *elems;
	size_t elem_size;
	volatile size_t count;
	size_t size;
	size_t pos_head;
	size_t pos_tail;
	void(*free_callback)(void *);
} cqueue_s;

void mcu_util_cqueue_init(cqueue_s *s, size_t init_size, size_t elem_size, void(*free_callback)(void *));
void mcu_util_cqueue_close(cqueue_s *s);
void mcu_util_cqueue_enque(cqueue_s *s, void *elem_addr);
void mcu_util_cqueue_deque(cqueue_s *s, void *elem_addr);
void mcu_util_cqueue_reset(cqueue_s *s);
void mcu_util_cqueue_peek(cqueue_s *s, void *elem_addr);
void mcu_util_cqueue_remove(cqueue_s *s, void *elem_addr);
uint8_t mcu_util_cqueue_is_empty(cqueue_s *s);
uint8_t mcu_util_cqueue_is_full(cqueue_s *s);
size_t mcu_util_cqueue_get_size(cqueue_s *s);

#endif
