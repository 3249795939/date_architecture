#ifndef THREADEDBINTREE_H
#define THREADEDBINTREE_H
//不提供普通树的实现

typedef int Element;
typedef struct threadedBinTreeNode {
	Element val;
	threadedBinTreeNode* left;
	threadedBinTreeNode* right;
	bool LTag;		//1为线索，0为实际关系
	bool RTag;
}ThreadedBinTreeNode;

typedef struct {
	int count;	//节点数
	ThreadedBinTreeNode* root;
}ThreadedBinTree;

ThreadedBinTree* createThreadedBinTree(ThreadedBinTreeNode* tree);

void releaseThreadedBinTree(ThreadedBinTree* ptr);

ThreadedBinTreeNode* createThreadedBinTreeNode(Element item);

void insert(ThreadedBinTree* tree, ThreadedBinTreeNode* parent, ThreadedBinTreeNode* left, ThreadedBinTreeNode* right);

void visitThreadedBinTreeNode(ThreadedBinTreeNode* node);

void inOrderThreadedTree(ThreadedBinTree* tree);

void inOrderThreadedBinTreeTraversal(ThreadedBinTree* tree);

#endif