#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

typedef struct binSearchTreeNode {
	int val;
	binSearchTreeNode* right;
	binSearchTreeNode* left;
}BinSearchTreeNode;

typedef struct {
	BinSearchTreeNode* root;
	unsigned int count;
}BinSearchTree;

BinSearchTree* createBinSearchTree();

void BinSearchTreeNodeInsertRecur(BinSearchTree* ptr,int element);	//µ›πÈ–¥∑®

void BinSearchTreeInOrderTraversal(BinSearchTree* ptr);

void DelBSTreeNode(BinSearchTree* ptr, int e);

void ReleaseBinSearchTree(BinSearchTree* ptr);

#endif