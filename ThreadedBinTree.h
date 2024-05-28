#ifndef THREADEDBINTREE_H
#define THREADEDBINTREE_H
//���ṩ��ͨ����ʵ��

typedef int Element;
typedef struct threadedBinTreeNode {
	Element val;
	threadedBinTreeNode* left;
	threadedBinTreeNode* right;
	bool LTag;		//1Ϊ������0Ϊʵ�ʹ�ϵ
	bool RTag;
}ThreadedBinTreeNode;

typedef struct {
	int count;	//�ڵ���
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