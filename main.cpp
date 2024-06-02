#include "BinSearchTree.h"
#include <iostream>

using namespace std;

int main(void) {
	int date[] = { 55,33,45,100,22,88,8,130,120 };
	BinSearchTree* tree = createBinSearchTree();
	for (int i = 0; i < sizeof(date) / sizeof(date[0]); i++) {
		BinSearchTreeNodeInsertRecur(tree, date[i]);
		cout << date[i] << endl;
	}
	puts("");
	BinSearchTreeInOrderTraversal(tree);
	DelBSTreeNode(tree, 100);
	puts("");
	BinSearchTreeInOrderTraversal(tree);
	ReleaseBinSearchTree(tree);
	return 0;
}