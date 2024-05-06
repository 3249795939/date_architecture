#ifndef LINKLOOPLIST_H
#define LINKLOOPLIST_H

typedef int Element;
typedef struct linkLoopNode {
	Element val;
	linkLoopNode* next;
}LinkLoopNode;

struct LinkLoopList {
	LinkLoopNode head;
	LinkLoopNode* rear;
	int node_sum;
};

LinkLoopList* createLinkLoopList();

void insertLinkLoopListHeader(LinkLoopList* ptr, Element item);

void insertLinkLoopListRear(LinkLoopList* ptr, Element item);

void LinkLoopListTraversal(LinkLoopList* ptr);

void deleteLinkLoopListHeader(LinkLoopList* ptr);

void deleteKthLinkLoopList(LinkLoopList* ptr,int K);

void releaseLinkLoopList(LinkLoopList* ptr);

#endif