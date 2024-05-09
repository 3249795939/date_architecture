#include "LinkStack.h"
#include <iostream>

LinkStack* createLinkStack()
{
	LinkStack* ptr = new LinkStack;
	ptr->size = 0;
	ptr->top = nullptr;
	return ptr;
}

void releaseLinkStack(LinkStack* ptr)
{
	if (ptr->size) {
		LinkStackNode* cur = ptr->top;
		while (ptr->size) {
			LinkStackNode* temp = cur;
			cur = cur->next;
			delete temp;
			ptr->size--;
		}
	}
	delete ptr;
	ptr = nullptr;
}

Element LinkStackPop(LinkStack* ptr)
{
	if (ptr->top == nullptr) {
		std::cout << "Stack is empty";
		return -1;
	}
	LinkStackNode* del_node = ptr->top;
	Element ret = del_node->val;
	ptr->top = ptr->top->next;
	delete del_node;
	ptr->size--;
	return ret;
}

void LinkStackPush(LinkStack* ptr, Element item)
{
	LinkStackNode* new_node = new LinkStackNode;
	new_node->next = nullptr;
	new_node->val = item;
	if (ptr->top == nullptr) {
		ptr->top = new_node;
		ptr->size++;
		return;
	}
	new_node->next = ptr->top;;
	ptr->top = new_node;
	ptr->size++;
}