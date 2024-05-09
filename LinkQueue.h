#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef int Element;
typedef struct linkQueueNode {
	Element val;
	linkQueueNode* next;
}LinkQueueNode;

struct LinkQueue {
	LinkQueueNode* head;
	LinkQueueNode* rear;
	unsigned int size;
};

LinkQueue* createLinkQueue();

void releaseLinkQueue(LinkQueue* ptr);

void LinkQueuePush(LinkQueue* ptr, Element item);

Element LinkQueuePop(LinkQueue* ptr);

#endif