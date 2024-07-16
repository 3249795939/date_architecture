#include "HufSeqTab.h"
#include <iostream>
#include <algorithm>

static int selectTwoMinNode(HufSeqTab tree,int* first,int* second,unsigned int length)
{
	//*first最小，*second第二小
	for (int i = 1; i <= length; i++) {
		if (tree[i].parent) {
			continue;	//已被插入到huffman树中
		}
		if (*first == 0) {
			*first = i;
		}
		else if (tree[i].weight <= tree[*first].weight) {
			*second = *first;
			*first = i;
		}
		else if (*second == 0) {
			*second = i;
		}
		else if (tree[i].weight <= tree[*second].weight) {
			*second = i;
		}
	}
	int res = tree[*first].weight + tree[*second].weight;
	return res;
}

HufSeqTab createHufSeqTab(unsigned int length, const int* w)
{
	int size = length * 2 - 1;
	HufSeqTab tree = new HufSeqTabNode[size+1];
	if (tree == nullptr) {
		return nullptr;
	}
	memset(tree, 0, sizeof(HufSeqTabNode) * (size + 1));
	for (int i = 1; i <= length; i++) {
		tree[i].weight = w[i-1];
	}

	for (int i = length + 1; i <= size; i++) {
		int first = 0, second = 0;
		int val = selectTwoMinNode(tree, &first, &second, i - 1);
		tree[i].l_child = first; tree[i].r_child = second;
		tree[i].weight = val;
		tree[first].parent = i; tree[second].parent = i;
	}

	return tree;
}

void releaseHufSeqTab(HufSeqTab tree)
{
	delete[] tree;
}

static HufCode getHufCode(HufSeqTab tree,int id)
{
	const int Max = 100;
	char temp[Max];
	int temp_id = id,cnt = 0;
	while (tree[temp_id].parent) {
		int temp_parent_id = tree[temp_id].parent;
		if (tree[temp_parent_id].l_child == temp_id) {
			temp[cnt++] = '0';
		}
		else {
			temp[cnt++] = '1';
		}
		temp_id = temp_parent_id;
	}
	temp[cnt++] = '1';
	/*for (int i = 0; i < cnt; i++) std::cout << temp[i] << std::endl;*/
	std::reverse(temp, temp + cnt);
	temp[cnt] = '\0';
	HufCode code = new char[cnt+1];
	for (int i = 0; i <= cnt;i++) {
		code[i] = temp[i];
	}

	return code;
}

HufCode* createHufCode(HufSeqTab tree, unsigned int length)
{
	HufCode* codes = new HufCode[length];
	for (int i = 0; i < length; i++) {
		HufCode temp = getHufCode(tree, i + 1);
		codes[i] = temp;
	}

	return codes;
}

void releaseHufCode(HufCode* codes, unsigned int length)
{
	for (int i = 0; i < length; i++) {
		delete[] codes[i];
	}
	delete[] codes;
}