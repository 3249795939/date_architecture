#include "DoubleLinkLoopList.h"
#include <iostream>

DoubleLinkLoopList* createDoubleLinkLoopList()
{
	DoubleLinkLoopList* ptr = new DoubleLinkLoopList;
	std::cout << "Create Done";
	return ptr;
}

DoubleLinkLoopList* initDoubleLinkLoopList(DoubleLinkLoopList* ptr)
{
	ptr->head.pre = &ptr->head;
	ptr->head.next = &ptr->head;
	ptr->rear = &ptr->head;
	ptr->node_sum = 0;
	std::cout << "Init Done";
	return ptr;
}

void addNode(DoubleLinkLoopNode* pre, DoubleLinkLoopNode* next,DoubleLinkLoopNode* new_node)
{
	pre->next = new_node;
	new_node->pre = pre;
	next->pre = new_node;
	new_node->next = next;
}

void delNode(DoubleLinkLoopNode* pre, DoubleLinkLoopNode* next)
{
	DoubleLinkLoopNode* temp_node = pre->next;
	pre->next = pre->next->next;
	next->pre = next->pre->pre;
	delete temp_node;
}

void insertDoubleLinkLoopListHeader(DoubleLinkLoopList* ptr, Element item)
{
	DoubleLinkLoopNode* new_node = new DoubleLinkLoopNode;
	new_node->val = item;
	if (&ptr->head == ptr->head.next) {
		ptr->rear = new_node;
	}
	addNode(&ptr->head, ptr->head.next,new_node);
	ptr->node_sum++;
	std::cout << "Insert Header successfully";
}

void insertDoubleLinkLoopListRear(DoubleLinkLoopList* ptr, Element item)
{
	DoubleLinkLoopNode* new_node = new DoubleLinkLoopNode;
	new_node->val = item;
	if (&ptr->head == ptr->head.next) {
		ptr->rear = new_node;
	}
	addNode(ptr->rear, ptr->rear->next,new_node);
	ptr->node_sum++;
	ptr->rear = new_node;
	std::cout << "Insert Rear successfully";
}

void insertDoubleLinkLoopListKth(DoubleLinkLoopList* ptr, Element item,int K)
{
	if (K > ptr->node_sum) {
		K %= ptr->node_sum;
	}
	DoubleLinkLoopNode* new_node = new DoubleLinkLoopNode;
	new_node->val = item;
	DoubleLinkLoopNode* cur = &ptr->head;
	if (K == ptr->node_sum) {
		ptr->rear = new_node;
	}
	while (K--) {
		cur = cur->next;
	}
	addNode(cur, cur->next, new_node);
	ptr->node_sum++;
	std::cout << "Insert Kth successfully";
}

void delDoubleLinkLoopListKth(DoubleLinkLoopList* ptr, int K)
{
	if (ptr->head.next == &ptr->head) {
		std::cout << "NULL";
		return;
	}
	if (K > ptr->node_sum) {
		K %= ptr->node_sum;
	}
	DoubleLinkLoopNode* cur = &ptr->head;
	if (K == ptr->node_sum) {
		ptr->rear = ptr->rear->pre;
	}
	while (K--) {
		cur = cur->next;
	}
	delNode(cur->pre, cur->next);
	ptr->node_sum--;
	std::cout << "del Kth successfully";
}

void delDoubleLinkListHeader(DoubleLinkLoopList* ptr)
{
	if (ptr->head.next == &ptr->head) {
		std::cout << "NULL";
		return;
	}
	if (ptr->node_sum == 1) {
		ptr->rear = &ptr->head;
	}
	ptr->node_sum--;
	delNode(&ptr->head, ptr->head.next);
	std::cout << "Header Delete Successfully";
}

void delDoubleLinkLoopListRear(DoubleLinkLoopList* ptr)
{
	if (ptr->head.next == &ptr->head) {
		std::cout << "NULL";
	}
	ptr->node_sum--;
	ptr->rear = ptr->rear->pre;
	delNode(ptr->rear, ptr->rear->next->next);
	std::cout << "Rear Delete successfully";
}

void DoubleLinkLoopListTraversal(DoubleLinkLoopList* ptr)
{
	DoubleLinkLoopNode* cur = ptr->head.next;
	if (cur == cur->next) {
		std::cout << "NULL";
	}
	while (cur != &ptr->head)
	{
		std::cout << cur->val << ' ';
		cur = cur->next;
	}
}

void relDoubleLinkLoopList(DoubleLinkLoopList* ptr)
{
	DoubleLinkLoopNode* cur = ptr->head.next;
	while (cur != &ptr->head) {
		DoubleLinkLoopNode* delNode = cur;
		cur = cur->next;
		delete(delNode);
	}
	delete ptr;
	std::cout << "Release Done";
}