#include "ThreadedBinTree.h"
#include <iostream>

ThreadedBinTree* createThreadedBinTree(ThreadedBinTreeNode* tree)
{
	ThreadedBinTree* ptr = new ThreadedBinTree;
	if (tree) {
		ptr->root = tree;
		ptr->count = 0;
		std::cout << "Create Down";
	}
	return ptr;
}

static void delThreadedBinTree(ThreadedBinTreeNode* root)
{
	if (root) {
		if (!root->LTag)delThreadedBinTree(root->left);
		if (!root->RTag)delThreadedBinTree(root->right);
		delete root;
	}
}

void releaseThreadedBinTree(ThreadedBinTree* ptr)
{
	delThreadedBinTree(ptr->root);
	std::cout << "Release Down";
}

ThreadedBinTreeNode* createThreadedBinTreeNode(Element item)
{
	ThreadedBinTreeNode* node = new ThreadedBinTreeNode;
	if (node) {
		node->val = item;
		node->LTag = false;
		node->RTag = false;
		node->left = nullptr;
		node->right = nullptr;
	}
	std::cout << "New Node";
	return node;
}

void insert(ThreadedBinTree* tree, ThreadedBinTreeNode* parent, ThreadedBinTreeNode* left, ThreadedBinTreeNode* right)
{
	if (parent) {
		if (left) {
			tree->count++;
			parent->left = left;
			parent->LTag = false;
		}
		if (right) {
			tree->count++;
			parent->right = right;
			parent->RTag = false;
		}
	}
	std::cout << "Insert Down";
}

void visitThreadedBinTreeNode(ThreadedBinTreeNode* node)
{
	if (node) {
		std::cout << node->val;
	}
}

static ThreadedBinTreeNode* pre = nullptr;
static void inOrderTheadingBinTree(ThreadedBinTreeNode* root)
{
	if (root) {
		inOrderTheadingBinTree(root->left);
		if (root->left == nullptr) {
			root->left = pre;
			root->LTag = true;
		}
		if (pre&&pre->right == nullptr) {
			pre->right = root;
			pre->RTag = true;
		}
		pre = root;
		inOrderTheadingBinTree(root->right);
	}
}

void inOrderThreadedTree(ThreadedBinTree* tree)
{
	inOrderTheadingBinTree(tree->root);
}

void inOrderThreadedBinTreeTraversal(ThreadedBinTree* tree)
{
	ThreadedBinTreeNode* cur = tree->root;
	while (cur) {
		while (!cur->LTag) {
			cur = cur->left;
		}
		visitThreadedBinTreeNode(cur);
		std::cout << " ";
		while (cur->RTag) {
			cur = cur->right;
			visitThreadedBinTreeNode(cur);
			std::cout << " ";
		}
		cur = cur->right;	//由于是中序线索遍历，当遍历到坐标该处时说明现在的cur前驱节点已全部遍历，及左节点全部遍历
	}
}