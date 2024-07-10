#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct AVLTreeNode {
	int val;
	int deepth;
	AVLTreeNode* left;
	AVLTreeNode* right;
}AVLTreeNode;

struct AVLTree {
	AVLTreeNode* tree;
	unsigned long int size;
};

/*
	功能:创造一个空树
*/
AVLTree* createEmptyAVLTree();

/*
	功能:往目标树'tree'中插入一个val为item的新节点，该函数会自动创造节点，如果该AVLTree中已存在val为item的值将什么都不做
*/
void AVLTreeInsert(AVLTree* tree,int item);

/*
	功能:在目标树找到一个val为item的节点，并返回改节点的地址
*/
AVLTreeNode* AVLTreeNodeFind(AVLTree* tree,int item);

/*
	功能:删除目标树中最靠前的val为item的节点，并平衡修改后的树
*/
void AVLTreeNodeDel(AVLTree* tree,int item);

/*
	功能:删除目标树
*/
void RelAVLTreeNode(AVLTree* tree);

#endif