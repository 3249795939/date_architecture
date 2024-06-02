#include <iostream>
#include "BinSearchTree.h"

BinSearchTree* createBinSearchTree()
{
	BinSearchTree* ptr = new BinSearchTree;
	if (ptr == nullptr) {
		std::cout << "false to create";
		return nullptr;
	}
	ptr->count = 0;
	ptr->root = nullptr;

	return ptr;
}

static BinSearchTreeNode* insertRecur(BinSearchTreeNode* &root,BinSearchTreeNode* new_node)
{
	if (root == nullptr) {
		root = new_node;
		std::cout << "Insert Done ";
	} else {
		if (new_node->val < root->val) {
			insertRecur(root->left, new_node);
		} else {
			insertRecur(root->right, new_node);
		}
	}
	return root;
}

static BinSearchTreeNode* createTreeNode(int val)
{
	BinSearchTreeNode* node = new BinSearchTreeNode;
	node->val = val;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void BinSearchTreeNodeInsertRecur(BinSearchTree* ptr,int element)
{
	BinSearchTreeNode* new_node = createTreeNode(element);
	ptr->count++;
	insertRecur(ptr->root, new_node);
}

static void visitNode(BinSearchTreeNode* ptr)
{
	std::cout << ptr->val << ' ';
}

static void inOrderTraversal(BinSearchTreeNode* ptr)
{
	if (ptr != nullptr) {
		inOrderTraversal(ptr->left);
		visitNode(ptr);
		inOrderTraversal(ptr->right);
	}
}

void BinSearchTreeInOrderTraversal(BinSearchTree* ptr)
{
	inOrderTraversal(ptr->root);
}

static BinSearchTreeNode* GetMinimalPastNode(BinSearchTreeNode* node)
{
	while (node && node->left) {
		node = node->left;
	}
	return node;
}

static BinSearchTreeNode* DelNode(BinSearchTree* ptr,BinSearchTreeNode* tree,int e)
{
	if (tree == nullptr) {
		return nullptr;
	}
	if (tree->val < e) {
		tree->right = DelNode(ptr, tree->right, e);
	}
	else if (tree->val > e) {
		tree->left = DelNode(ptr, tree->left, e);
	}else {
		if (tree->left == nullptr) {
			BinSearchTreeNode* tmp = tree->right;
			ptr->count--;
			delete tree;
			return tmp;
		}
		if (tree->right == nullptr) {
			BinSearchTreeNode* tmp = tree->left;
			ptr->count--;
			delete tree;
			return tmp;
		}
		BinSearchTreeNode* tmp = GetMinimalPastNode(tree->right);
		tree->val = tmp->val;
		DelNode(ptr, tree->right, tmp->val);
	}
	return tree;
}

void DelBSTreeNode(BinSearchTree* ptr, int e)
{
	if (ptr->root) {
		DelNode(ptr, ptr->root, e);
	}
}

static void ReleaseBST(BinSearchTreeNode* tree)
{
	if (!tree) {
		return;
	}
	ReleaseBST(tree->left);
	ReleaseBST(tree->right);
	delete tree;
}

void ReleaseBinSearchTree(BinSearchTree* ptr)
{
	ReleaseBST(ptr->root);
	ptr->count = 0;
	delete ptr;
}