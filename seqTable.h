#ifndef SEQTABLE_H
#define SEQTABLE_H

typedef int Element;
typedef unsigned int Size_t;

typedef struct {
	Element* val;
	Size_t size;
	Size_t capacity;
}seqTable;

seqTable* makeEmptySeqTable(Size_t size);	//�����˳���

seqTable* enlargeSeqTable(seqTable* seqTablePtr);	//����˳���

seqTable* insertItemAfterSeqTable(seqTable* seqTablePtr, Element item);	//β��Ԫ��

seqTable* insertItemInSeqTable(seqTable* seqTablePtr, Element item, int K);	//����λ�ò���Ԫ��

Element removeBackItemOfSeqTable(seqTable* seqTablePtr);	//�Ƴ�βԪ��

Element removeKthItem(seqTable* seqTable, int K);	//�Ƴ�����Ԫ��

int findKthInSeqTable(seqTable* seqTablePtr, Element destination);	//����Ŀ��Ԫ�أ�����Ŀ��Ԫ������

void deleteSeqTable(seqTable* seqTablePtr);		//ɾ��˳���

void showSeqTable(seqTable* seqTablePtr);	//����˳���,�����

#endif