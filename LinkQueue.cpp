#include "LinkQueue.h"
#include <iostream>

LinkQueue* createLinkQueue()
{
	LinkQueue* ptr = new LinkQueue;
	ptr->head = nullptr;
	ptr->rear = nullptr;
	ptr->size = 0;
	return ptr;
}

void releaseLinkQueue(LinkQueue* ptr)
{
	if (ptr->head != nullptr) {
		LinkQueueNode* cur = ptr->head;
		while (cur) {
			LinkQueueNode* del_node = cur;
			cur = cur->next;
			delete del_node;
		}
	}
	delete ptr;
}

void LinkQueuePush(LinkQueue* ptr, Element item)
{
	LinkQueueNode* temp = new LinkQueueNode;
	temp->val = item;
	temp->next = nullptr;
	if (ptr->rear == nullptr) {
		ptr->rear = temp;
		ptr->head = temp;
		ptr->size++;
		return;
	}
	ptr->rear->next = temp;
	ptr->rear = ptr->rear->next;
}

Element LinkQueuePop(LinkQueue* ptr)
{
	if (ptr->head == nullptr) {
		std::cout << "NULL";
		return -1;
	}
	LinkQueueNode* cur = ptr->head;
	ptr->head = ptr->head->next;
	int ret = cur->val;
	delete cur;
	return ret;
}