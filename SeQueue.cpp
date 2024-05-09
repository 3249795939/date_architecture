#include "SeQueue.h"
#include <iostream>

SeQueue* createSeQueue(unsigned int size)
{
	SeQueue* ptr = new SeQueue;
	ptr->flag = 0;
	ptr->queue = new Element[size];
	ptr->head = 0;
	ptr->front = 0;
	ptr->size = size;
	return ptr;
}

void releaseSeQueue(SeQueue* ptr)
{
	delete[ptr->size] ptr->queue;
	delete ptr;
}

Element SeQueuePop(SeQueue* ptr)
{
	if (ptr->head == ptr->front && ptr->flag == 0) {
		std::cout << "NULL";
		return -1;
	}
	int ret = ptr->queue[ptr->head];
	ptr->head = (ptr->head + 1) % ptr->size;
	ptr->flag = 0;
	return ret;
}

void SeQueuePush(SeQueue* ptr, Element item)
{
	if (ptr->head == ptr->front && ptr->flag == 1) {
		std::cout << "FULL";
		return;
	}
	ptr->queue[ptr->front] = item;
	ptr->front = (ptr->front + 1) % ptr->size;
	ptr->flag = 1;
}