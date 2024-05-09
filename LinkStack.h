#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int Element;
typedef struct linkStackNode {
	Element val;
	linkStackNode* next;
}LinkStackNode;

struct LinkStack {
	LinkStackNode* top;
	unsigned int size;
};

LinkStack* createLinkStack();

void releaseLinkStack(LinkStack* ptr);

Element LinkStackPop(LinkStack* ptr);

void LinkStackPush(LinkStack* ptr, Element item);

#endif