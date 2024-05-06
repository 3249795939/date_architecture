#ifndef DOUBLELINKLOOPLIST_H
#define DOUBLELINKLOOKLIST_H

typedef int Element;
typedef struct doubleLinkLoopNode {
	Element val;
	doubleLinkLoopNode* next;
	doubleLinkLoopNode* pre;
}DoubleLinkLoopNode;

typedef struct doubleLinkLoopList {
	DoubleLinkLoopNode head;
	doubleLinkLoopNode* rear;
	int node_sum;
}DoubleLinkLoopList;

DoubleLinkLoopList* createDoubleLinkLoopList();

DoubleLinkLoopList* initDoubleLinkLoopList(DoubleLinkLoopList* ptr);

static void addNode(DoubleLinkLoopNode* pre, DoubleLinkLoopNode* next,DoubleLinkLoopNode* new_node);

static void delNode(DoubleLinkLoopNode* pre, DoubleLinkLoopNode* next);

void insertDoubleLinkLoopListHeader(DoubleLinkLoopList* ptr, Element item);

void insertDoubleLinkLoopListRear(DoubleLinkLoopList* ptr, Element item);

void insertDoubleLinkLoopListKth(DoubleLinkLoopList* ptr, Element item,int K);

void delDoubleLinkLoopListKth(DoubleLinkLoopList* ptr,int K);

void delDoubleLinkListHeader(DoubleLinkLoopList* ptr);

void delDoubleLinkLoopListRear(DoubleLinkLoopList* ptr);

void DoubleLinkLoopListTraversal(DoubleLinkLoopList* ptr);

void relDoubleLinkLoopList(DoubleLinkLoopList* ptr);

#endif