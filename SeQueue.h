#ifndef SEQUEUE_H
#define SEQUEUE_H

typedef int Element;
struct SeQueue {
	Element* queue;
	int head;
	int front;
	unsigned int size;
	bool flag;			//标志上一次的修改操作以避免取模结果二义性，1为入，0为出
};

SeQueue* createSeQueue(unsigned int size);

void releaseSeQueue(SeQueue* ptr);

Element SeQueuePop(SeQueue* ptr);

void SeQueuePush(SeQueue* ptr, Element item);

#endif