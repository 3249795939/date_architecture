#include "RBTree.h"
#include <iostream>

RBTree* creatEmptyRBTree()
{
	RBTree* cur = new RBTree;
	cur->root = nullptr;
	cur->size_t = 0;
	return cur;
}

static RBTreeNode* createRBNode(KeyType key)
{
	RBTreeNode* cur = new RBTreeNode;
	cur->color = RED;
	cur->leftChild = nullptr;
	cur->rightChild = nullptr;
	cur->parent = nullptr;
	cur->weight = key;

	return cur;
}

static void leftTwist(RBTreeNode* cur)
{
	RBTreeNode* parent = cur->parent;
	RBTreeNode* alter_cur = cur->rightChild;
	RBTreeNode* rlNode = alter_cur->leftChild;
	cur->rightChild = rlNode;
	if (rlNode) {
		rlNode->parent = cur;
	}

	alter_cur->leftChild = cur;
	cur->parent = alter_cur;

	alter_cur->parent = parent;
	if (parent) {
		if (parent->leftChild == cur) {
			parent->leftChild = alter_cur;
		}
		else if (parent->rightChild == cur) {
			parent->rightChild = alter_cur;
		}
	}

	return;
}

static void rightTwist(RBTreeNode* cur)
{
	RBTreeNode* parent = cur->parent;
	RBTreeNode* alter_cur = cur->leftChild;
	RBTreeNode* lrNode = cur->leftChild->rightChild;

	cur->leftChild = lrNode;
	if (lrNode) {
		lrNode->parent = cur;
	}

	alter_cur->rightChild = cur;
	cur->parent = alter_cur;

	alter_cur->parent = parent;
	if (parent) {
		if (parent->leftChild == cur) {
			parent->leftChild = alter_cur;
		}
		else if (parent->rightChild == cur) {
			parent->rightChild = alter_cur;
		}
	}

	return;
}

static void fixUpInsertTree(RBTree* tree, RBTreeNode* cur)
{
	RBTreeNode* parent = cur->parent; RBTreeNode* grand = nullptr;
	RBTreeNode* uncle = nullptr;

	while (parent && parent->color == RED) {
		grand = parent->parent;
		if (parent == grand->leftChild) {
			uncle = grand->rightChild;
		}
		else if (parent == grand->rightChild) {
			uncle = grand->leftChild;
		}

		if (uncle && uncle->color == RED) {
			uncle->color = BLACK;
			parent->color = BLACK;
			grand->color = RED;

			cur = grand;
			parent = cur->parent;

			continue;
		}
		//uncle为黑色时只能是空节点
		if (parent == grand->leftChild) {
			if (cur == parent->rightChild) {
				leftTwist(parent);
				parent = cur;
				cur = parent->leftChild;
			}
			grand->color = RED;
			parent->color = BLACK;
			rightTwist(grand);
		}
		else if (parent == grand->rightChild) {
			if (cur == parent->leftChild) {
				rightTwist(parent);
				parent = cur;
				cur = parent->rightChild;
			}
			grand->color = RED;
			parent->color = BLACK;
			leftTwist(grand);
		}
	}

	tree->root->color = BLACK;

	return;
}

void insertRBTreeNode(RBTree* tree, KeyType key)
{
	RBTreeNode* cur = createRBNode(key);

	RBTreeNode* temp = tree->root; RBTreeNode* pre = nullptr;

	while (temp) {		//左小右大
		pre = temp;
		if (temp->weight > key) {
			temp = temp->leftChild;
		}
		else if (temp->weight < key) {
			temp = temp->rightChild;
		}
		else {
			printf("the node is existing/n");
		}
	}
	if (pre == nullptr) {
		tree->root = cur;
	}
	else {
		cur->parent = pre;
		if (pre->weight > key) {
			pre->leftChild = cur;
		}
		else {
			pre->rightChild = cur;
		}
	}

	fixUpInsertTree(tree, cur);

	tree->size_t++;

	return;
}

RBTreeNode* searchNode(const RBTree* tree, KeyType key)
{
	RBTreeNode* cur = tree->root;
	while (cur) {
		if (cur->weight > key && cur->leftChild) {
			cur = cur->leftChild;
		}
		else if (cur->weight < key && cur->rightChild) {
			cur = cur->rightChild;
		}
		else if (cur->weight == key) {
			return cur;
		}
		else {
			break;
		}
	}

	return nullptr;
}

static void fixUpDelete(RBTree* tree,RBTreeNode* cur,RBTreeNode* parent)
{
	RBTreeNode* bro;
	while (cur != tree->root && (!cur || cur->color == BLACK)) {
		if (cur == parent->leftChild) {
			bro = parent->rightChild;		//黑高相等,cur为黑色时,bro一定存在
			if (bro->color == RED) {
				bro->color = BLACK;
				parent->color = RED;
				leftTwist(parent);
				bro = parent->rightChild;
			}

			if (bro->color == BLACK) {
				if ((!bro->leftChild || bro->leftChild->color == BLACK) && (!bro->rightChild || bro->rightChild->color == BLACK)) {
					bro->color = RED;
					cur = parent;
					parent = cur->parent;
				}
			}
			else {
				if (bro->leftChild && bro->leftChild->color == RED) {
					bro->leftChild->color = BLACK;
					bro->color = RED;
					rightTwist(bro);
					bro = parent->rightChild;
				}
				
				bro->color = parent->color;
				bro->rightChild->color = BLACK;
				parent->color = BLACK;
				leftTwist(parent);
				cur = tree->root;		//终止指令，下同
			}
		}
		else if (cur == parent->rightChild) {
			bro = parent->leftChild;
			if (bro->color == RED) {
				bro->color = BLACK;
				parent->color = RED;
				rightTwist(parent);
				bro = parent->leftChild;
			}

			if (bro->color == BLACK) {
				if ((!bro->leftChild || bro->leftChild->color == BLACK) && (!bro->rightChild || bro->rightChild->color == BLACK)) {
					bro->color = RED;
					cur = parent;
					parent = cur->parent;
				}
			}
			else {
				if (bro->rightChild && bro->rightChild->color == RED) {
					bro->rightChild->color = BLACK;
					bro->color = RED;
					leftTwist(bro);
					bro = parent->leftChild;
				}

				bro->color = parent->color;
				bro->leftChild->color = BLACK;
				parent->color = BLACK;
				rightTwist(parent);
				cur = tree->root;
			}
		}
	}

	if (cur) {
		cur->color = BLACK;
	}
}

static void deleteNode(RBTree* tree, RBTreeNode* node)
{
	RBTreeNode* parent = nullptr;
	RBTreeNode* cur = nullptr; RBTreeNode* rep_cur = nullptr;
	if (!node->leftChild || !node->rightChild) {
		cur = node;
		parent = node->parent;
	}
	else {
		cur = node->leftChild;
		while (cur && cur->rightChild) {
			cur = cur->rightChild;
		}
		parent = cur->parent;
	}
	if (cur->leftChild) {
		rep_cur = cur->leftChild;
	}
	else {
		rep_cur = cur->rightChild;
	}

	if (rep_cur) {
		rep_cur->parent = parent;
	}

	if (parent == nullptr) {
		tree->root = rep_cur;
	}
	else if (parent->leftChild == cur) {
		parent->leftChild = rep_cur;
	}
	else if (parent->rightChild == cur) {
		parent->rightChild = rep_cur;
	}

	if (cur->weight != node->weight) {
		node->weight = cur->weight;
	}

	if (cur->color == BLACK) {
		fixUpDelete(tree, rep_cur, parent);
	}

	delete cur;
	tree->size_t--;

	return;
}

void deleteRBTreeNode(RBTree* tree, KeyType key)
{
	RBTreeNode* cur = searchNode(tree, key);
	deleteNode(tree, cur);

	return;
}