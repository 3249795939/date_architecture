#include "seqLinkList.h"
#include <iostream>

seqLinkList* createSeqLinkList()
{
	seqLinkList* head = new seqLinkList;
	if (head == nullptr) {
		return nullptr;
	}
	head->head.val = 0;
	head->head.next = nullptr;
	head->linkSize = 0;
	return head;
}

void releaseSeqLinkList(seqLinkList* seq_link_list)
{
	seqLinkNode* p = new seqLinkNode;
	seqLinkNode* pre_ptr = new seqLinkNode;
	p = &seq_link_list->head;
	pre_ptr = p->next;
	while (pre_ptr != nullptr) {
		p->next = pre_ptr->next;
		delete pre_ptr;
		pre_ptr = p->next;
	}
	delete seq_link_list;
	seq_link_list = nullptr;
	std::cout << "All Down!";
}

int insertSeqLinkHeader(seqLinkList* seq_link_list,Element item)
{
	seqLinkNode* p = &seq_link_list->head;
	if (p == nullptr) {
		return 1;
	}
	seqLinkNode* newNode = new seqLinkNode;
	if (newNode == nullptr) {
		return 1;
	}
	newNode->val = item;
	newNode->next = p->next;
	p->next = newNode;
	(seq_link_list->linkSize)++;
	return 0;
}

int insertSeqLinkPos(seqLinkList* seq_link_list, int k, Element item)
{
	if (k >= seq_link_list->linkSize) {
		return 1;
	}
	seqLinkNode* tempNode = new seqLinkNode;
	if (tempNode == nullptr) {
		return 1;
	}
	tempNode = &seq_link_list->head;
	for (int i = 0; i < k; i++) {
		tempNode = tempNode->next;
	}
	seqLinkNode* insertNode = new seqLinkNode;
	insertNode->val = item;
	insertNode->next = tempNode->next;
	tempNode->next = insertNode;
	seq_link_list->linkSize++;

	return 0;
}

void showSeqLinkList(seqLinkList* seq_link_list)
{

	seqLinkNode* p = &seq_link_list->head;
	if (p == nullptr) {
		std::cout << "NULL";
		return;
	}
	while (p->next != nullptr) {
		p = p->next;
		std::cout << p->val << ' ';
	}

	return;
}

void deleteSeqLinkListHeader(seqLinkList* seq_link_list)
{
	seqLinkNode* p = new seqLinkNode;
	p = &seq_link_list->head;
	if (p->next == nullptr) {
		return;
	}
	p = p->next;
	seq_link_list->head.next = p->next;
	delete p;
	seq_link_list->linkSize--;
}

void deleteSeqLinkListPos(seqLinkList* seq_link_list,int K)
{
	if (K >= seq_link_list->linkSize) {
		return;
	}
	seqLinkNode* p = new seqLinkNode;
	p = &seq_link_list->head;
	for (int i = 0; i < K - 1; i++) {
		p = p->next;
	}
	seqLinkNode* temp_ptr = p->next;
	p->next = temp_ptr->next;
	delete temp_ptr;
	seq_link_list->linkSize--;
}

int findKthSeqLinkList(seqLinkList* seq_link_list, Element destination)
{
	auto p = &seq_link_list->head;
	int K = -1;
	while (p->next != nullptr) {
		p = p->next;
		K++;
		if (p->val == destination) {
			return K;
		}
	}
	return -1;
}