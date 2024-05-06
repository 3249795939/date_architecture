#ifndef SEQTABLE_H
#define SEQTABLE_H

typedef int Element;
typedef unsigned int Size_t;

typedef struct {
	Element* val;
	Size_t size;
	Size_t capacity;
}seqTable;

seqTable* makeEmptySeqTable(Size_t size);	//制造空顺序表

seqTable* enlargeSeqTable(seqTable* seqTablePtr);	//扩大顺序表

seqTable* insertItemAfterSeqTable(seqTable* seqTablePtr, Element item);	//尾插元素

seqTable* insertItemInSeqTable(seqTable* seqTablePtr, Element item, int K);	//任意位置插入元素

Element removeBackItemOfSeqTable(seqTable* seqTablePtr);	//移除尾元素

Element removeKthItem(seqTable* seqTable, int K);	//移除任意元素

int findKthInSeqTable(seqTable* seqTablePtr, Element destination);	//查找目标元素，返回目标元素索引

void deleteSeqTable(seqTable* seqTablePtr);		//删除顺序表

void showSeqTable(seqTable* seqTablePtr);	//遍历顺序表,并输出

#endif