#include "SeqStack.h"
#include <iostream>

SeqStack* createSeqStack(unsigned int size)
{
	SeqStack* ptr = new SeqStack;
	ptr->stack = new Element[size];
	ptr->top = -1;
	ptr->size = size;
	return ptr;
}

void releaseSeqStack(SeqStack* ptr)
{
	delete[] ptr->stack;
	delete  ptr;
}

Element seqStackPop(SeqStack* ptr)
{
	if (ptr->top == -1) {
		std::cout << "Stack NULL";
		return -1;
	}
	return ptr->stack[ptr->top--];
}

void seqStackPush(SeqStack* ptr, Element item)
{
	if (ptr->top == ptr->size) {
		std::cout << "Stack Full";
		return;
	}
	ptr->stack[++ptr->top] = item;
}