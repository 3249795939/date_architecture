#include "seqTable.h"
#include <cstdlib>
#include <iostream>

seqTable* makeEmptySeqTable(Size_t size)
{
	seqTable* head = nullptr;
	head = (seqTable*)malloc(sizeof(seqTable));
	if (head == nullptr)
	{
		std::cout << "malloc failure!";
		return nullptr;
	}
	head->val = (Element*)malloc(size * sizeof(Element));
	head->size = 0;
	head->capacity = size;

	return head;
}

seqTable* enlargeSeqTable(seqTable* seqTablePtr)
{
	if (seqTablePtr == nullptr || seqTablePtr->capacity == 0) return seqTablePtr;
	seqTablePtr->capacity *= 2;
	Element* tempPtr = (Element*)malloc(seqTablePtr->capacity * sizeof(Element));
	for (int i = 0; i < seqTablePtr->size; i++)
	{
		tempPtr[i] = seqTablePtr->val[i];
	}
	Element* Ptr = seqTablePtr->val;
	seqTablePtr->val = tempPtr;
	free(Ptr);

	return seqTablePtr;
}

seqTable* insertItemAfterSeqTable(seqTable* seqTablePtr, Element item)
{
	if (seqTablePtr->size < seqTablePtr->capacity)
	{
		seqTablePtr->val[seqTablePtr->size++] = item;
	}
	else
	{
		std::cout << "lack of space,insert failure!" << std::endl;
	}
	return seqTablePtr;
}

seqTable* insertItemInSeqTable(seqTable* seqTablePtr, Element item, int K)
{
	if (seqTablePtr->size == seqTablePtr->capacity)
	{
		std::cout << "lack of space,insert failure" << std::endl;
	}
	if (K > seqTablePtr->size)
	{
		std::cout << "invalid position" << std::endl;
	}
	else
	{
		for (int i = seqTablePtr->size; i > K; i--)
		{
			seqTablePtr->val[i] = seqTablePtr->val[i - 1];
		}
		seqTablePtr->val[K] = item;
	}

	return seqTablePtr;
}

Element removeBackItemOfSeqTable(seqTable* seqTablePtr)
{
	if (seqTablePtr->size > 0) {
		seqTablePtr->size--;
		return seqTablePtr->val[seqTablePtr->size];
	}

	return -1;
}

Element removeKthItem(seqTable* seqTablePtr, int K)
{
	if (K >= seqTablePtr->size) {
		return -1;
	}
	for (int i = K + 1; i < seqTablePtr->size; i++) seqTablePtr->val[i - 1] = seqTablePtr->val[i];
	seqTablePtr->size--;
}

int findKthInSeqTable(seqTable* seqTablePtr, Element destination)
{
	for (int i = 0; i < seqTablePtr->size; i++)
	{
		if (seqTablePtr->val[i] == destination) return i;
	}
	return -1;
}

void deleteSeqTable(seqTable* seqTablePtr)
{
	if (seqTablePtr == nullptr)
	{
		return;
	}
	free(seqTablePtr->val);
	free(seqTablePtr);
	return;
}

void showSeqTable(seqTable* seqTablePtr)
{
	if (seqTablePtr->size == 0) {
		std::cout << "NULL";
		return;
	}
	for (int i = 0; i < seqTablePtr->size; i++)
	{
		std::cout << seqTablePtr->val[i] << ' ';
	}
	return;
}