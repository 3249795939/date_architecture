#pragma once

enum RBColor{RED,BLACK};

typedef int KeyType;

struct RBTreeNode {
	RBTreeNode* parent;
	RBTreeNode* leftChild;
	RBTreeNode* rightChild;
	KeyType weight;
	char color;
};

struct RBTree {
	RBTreeNode* root;
	int size_t;
};

RBTree* creatEmptyRBTree();

void insertRBTreeNode(RBTree* tree, KeyType key);

RBTreeNode* searchNode(const RBTree* tree, KeyType);

void deleteRBTreeNode(RBTree* tree, KeyType key);