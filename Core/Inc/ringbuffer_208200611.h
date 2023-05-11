/* **********************************
 *	Ring buffer
 *	by 邓君卓 208200611
 *
 *	本来想用来做历史记录和返回功能的，后来觉得没啥意义就没做
 * ********************************** */
#ifndef _H_RINGBUFFER_
#define _H_RINGBUFFER_
#define _A_208200611_

#define RBSize 10

struct RingBuffer{
	void *Items[RBSize];
	int head;
}typedef RingBuffer;

void* RBGetCurrentItem(RingBuffer*);
void RBMoveNext(RingBuffer*);
void RBWrite(RingBufer*,void* Item);

#endif
