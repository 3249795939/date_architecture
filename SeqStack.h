#ifndef SEQSTACK_H
#define SEQSTACK_H

typedef int Element;
struct SeqStack{
	int top;
	Element* stack;
	unsigned int size;
};

SeqStack* createSeqStack(unsigned int size);

void releaseSeqStack(SeqStack* ptr);

Element seqStackPop(SeqStack* ptr);

void seqStackPush(SeqStack* ptr, Element item);

#endif