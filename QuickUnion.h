#ifndef QUICKUNION_H
#define QUICKUNION_N

typedef struct {
	int* val;		//该集合的所有元素
	int* parentID;	//该集合所有元素的父ID
	int n;			//该集合的ID
	unsigned int* size;		//该集合内所有连通块的大小
}QuickUnionSet;

QuickUnionSet* createQuickUnionSet(unsigned int size);

void initQuickUnionSet(QuickUnionSet* set, const int* val, unsigned int n);

void releaseQuickUnionSet(QuickUnionSet* set);

bool isSameSet(QuickUnionSet* set, int a, int b);

void unionQuickUnionSet(QuickUnionSet* set, int a, int b);

#endif