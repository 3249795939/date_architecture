#ifndef QUICKUNION_H
#define QUICKUNION_N

typedef struct {
	int* val;		//�ü��ϵ�����Ԫ��
	int* parentID;	//�ü�������Ԫ�صĸ�ID
	int n;			//�ü��ϵ�ID
	unsigned int* size;		//�ü�����������ͨ��Ĵ�С
}QuickUnionSet;

QuickUnionSet* createQuickUnionSet(unsigned int size);

void initQuickUnionSet(QuickUnionSet* set, const int* val, unsigned int n);

void releaseQuickUnionSet(QuickUnionSet* set);

bool isSameSet(QuickUnionSet* set, int a, int b);

void unionQuickUnionSet(QuickUnionSet* set, int a, int b);

#endif