#ifndef SEQUEUE_H
#define SEQUEUE_H

typedef int Element;
struct SeQueue {
	Element* queue;
	int head;
	int front;
	unsigned int size;
	bool flag;			//��־��һ�ε��޸Ĳ����Ա���ȡģ��������ԣ�1Ϊ�룬0Ϊ��
};

SeQueue* createSeQueue(unsigned int size);

void releaseSeQueue(SeQueue* ptr);

Element SeQueuePop(SeQueue* ptr);

void SeQueuePush(SeQueue* ptr, Element item);

#endif