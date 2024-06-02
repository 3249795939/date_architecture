#include "LinkLoopList.h"
#include <cstdlib>
#include <iostream>

LinkLoopList* createLinkLoopList()
{
	LinkLoopList* p = new LinkLoopList;
	p->rear = &p->head;
	p->node_sum = 0;
	p->head.val = 0;
	p->head.next = &p->head;
	std::cout << "successfully create";
	return p;
}

void insertLinkLoopListHeader(LinkLoopList* ptr, Element item)
{
	LinkLoopNode* new_node = new LinkLoopNode;
	new_node->val = item;
	new_node->next = ptr->head.next;
	ptr->head.next = new_node;
	ptr->node_sum++;
	std::cout << "Header Insert successfully";
}

void insertLinkLoopListRear(LinkLoopList* ptr, Element item)
{
	LinkLoopNode* new_node = new LinkLoopNode;
	new_node->val = item;
	new_node->next = ptr->rear->next;
	ptr->rear->next = new_node;
	ptr->rear = new_node;
	ptr->node_sum++;
	std::cout << "Rear Insert successfully";
}

void LinkLoopListTraversal(LinkLoopList* ptr)
{
	LinkLoopNode* temp_node = ptr->head.next;
	if (temp_node == &ptr->head) {
		std::cout << "NULL";
		return;
	}
	while (temp_node != &ptr->head) {
		std::cout << temp_node->val << ' ';
		temp_node = temp_node->next;
	}
}

void deleteLinkLoopListHeader(LinkLoopList* ptr)
{
	if (ptr->head.next == &ptr->head) {
		std::cout << "NULL";
		return;
	}
	LinkLoopNode* pre = &ptr->head;
	LinkLoopNode* del_node = ptr->head.next;
	pre->next = del_node->next;
	if (ptr->rear == del_node) {
		ptr->rear = &ptr->head;
	}
	delete del_node;
	ptr->node_sum--;
	std::cout << "Done!";
}

void deleteKthLinkLoopList(LinkLoopList* ptr, int K)
{
	if (K > ptr->node_sum) {
		K %= ptr->node_sum;
	}
	LinkLoopNode* cur = &ptr->head;
	LinkLoopNode* pre = &ptr->head;
	while (K--) {
		pre = cur;
		cur = cur->next;
	}
	if (ptr->rear == cur) {
		ptr->rear = pre;
	}
	pre->next = cur->next;
	delete cur;
	--ptr->node_sum;
}

void releaseLinkLoopList(LinkLoopList* ptr)
{
	LinkLoopNode* cur = ptr->head.next;
	LinkLoopNode* del_node = nullptr;
	while (cur->next != &ptr->head) {
		del_node = cur;
		cur = cur->next;
		delete del_node;
	}
	delete ptr;
	ptr = nullptr;
	std::cout << "All Done!!!";
}