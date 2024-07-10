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
	����:����һ������
*/
AVLTree* createEmptyAVLTree();

/*
	����:��Ŀ����'tree'�в���һ��valΪitem���½ڵ㣬�ú������Զ�����ڵ㣬�����AVLTree���Ѵ���valΪitem��ֵ��ʲô������
*/
void AVLTreeInsert(AVLTree* tree,int item);

/*
	����:��Ŀ�����ҵ�һ��valΪitem�Ľڵ㣬�����ظĽڵ�ĵ�ַ
*/
AVLTreeNode* AVLTreeNodeFind(AVLTree* tree,int item);

/*
	����:ɾ��Ŀ�������ǰ��valΪitem�Ľڵ㣬��ƽ���޸ĺ����
*/
void AVLTreeNodeDel(AVLTree* tree,int item);

/*
	����:ɾ��Ŀ����
*/
void RelAVLTreeNode(AVLTree* tree);

#endif