#include "AVLTree.h"
#include <iostream>

AVLTree* createEmptyAVLTree()
{
	AVLTree* tree = new AVLTree;
	if (tree == nullptr) {
		printf("false to create AVLTree");
		return nullptr;
	}
	tree->size = 0;
	tree->tree = nullptr;
	return tree;
}

static int GetHeight(AVLTreeNode* ptr)
{
	if (ptr == nullptr) {
		return 0;
	}
	return ptr->deepth;
}

static AVLTreeNode* NodeLLTwist(AVLTreeNode* node)
{
	AVLTreeNode* ptr = node->left;
	AVLTreeNode* temp = ptr->right;
	ptr->right = node;
	node->left = temp;
	node->right = nullptr;
	node->deepth = std:: max(GetHeight(node->left) + 1, GetHeight(node->right) + 1);
	ptr->deepth = std::max(GetHeight(ptr->left) + 1, GetHeight(node->right) + 1);
	return ptr;
}

static AVLTreeNode* NodeRRTwist(AVLTreeNode* node)
{
	AVLTreeNode* ptr = node->right;
	AVLTreeNode* temp = ptr->left;
	ptr->left = node;
	node->right = temp;
	node->left = nullptr;
	node->deepth = std::max(GetHeight(node->left) + 1, GetHeight(node->right) + 1);
	ptr->deepth = std::max(GetHeight(ptr->left) + 1, GetHeight(ptr->right) + 1);
	return ptr;
}

static AVLTreeNode* InsertRecur(AVLTreeNode* root, int item)
{
	if (root == nullptr) {
		AVLTreeNode* ptr = new AVLTreeNode;
		ptr->val = item;		//��ʼ���½ڵ�
		ptr->deepth = 1;
		ptr->left = nullptr;
		ptr->right = nullptr;
		return ptr;
	} else if (item > root->val) {
		root->right = InsertRecur(root->right, item);
	} else if (item < root->val) {
		root->left = InsertRecur(root->left, item);
	}
	root->deepth = std::max(GetHeight(root->left) + 1, GetHeight(root->right) + 1);
	int balance = GetHeight(root->left) - GetHeight(root->right);
	if (balance > 1) {	//L��ʧ��
		AVLTreeNode* temp = root->left;
		if (GetHeight(temp->left) < GetHeight(temp->right)) {		//LR��ʧ��	
			temp = NodeLLTwist(temp);	//ת����LL��ʧ��
		}
		root = NodeLLTwist(root);	//LL��ʧ�⴦��
	} else if (balance < -1) {	//R��ʧ��
		AVLTreeNode* temp = root->right;
		if (GetHeight(temp->left) > GetHeight(temp->right)) {		//RL��ʧ��
			temp = NodeRRTwist(temp);	//ת����RR��ʧ��
		}
		root = NodeRRTwist(root);	//RR��ʧ�⴦��
	}
	return root;
}

void AVLTreeInsert(AVLTree* tree, int item)
{
	InsertRecur(tree->tree, item);
}

static AVLTreeNode* FindDestNode(AVLTreeNode* curNode, int item)
{
	if (curNode == nullptr || curNode->val == item) {
		return curNode;
	} else if (curNode->val > item) {
		return FindDestNode(curNode->left,item);
	} else if (curNode->val < item) {
		return FindDestNode(curNode->right, item);
	}
}

AVLTreeNode* AVLTreeNodeFind(AVLTree* tree, int item)
{
	AVLTreeNode* root = tree->tree;
	return FindDestNode(root, item);
}

static AVLTreeNode* DelTreeNodeProce(AVLTreeNode* destNode)
{
	if (destNode->left != nullptr || destNode->right != nullptr) {
		if (destNode->right != nullptr) {
			AVLTreeNode* temp = destNode->right;
			while (temp->left) {
				temp = temp->left;
			}
			destNode->val = temp->val;
		} else {
			AVLTreeNode* temp = destNode->left;
			while (temp->right) {
				temp = temp->right;
			}
			destNode->val = temp->val;
		}	//�ҵ�������,�ص��ݹ�׶Σ��������̶���ڵ�ɾ��
	} else {
		delete destNode;
		return nullptr;
	}

	return destNode;
}

static bool DelTreeNodeRecur(AVLTreeNode* curNode, int item)
{
	if (curNode == nullptr) {
		return false;
	}
	if (item == curNode->val) {
		curNode = DelTreeNodeProce(curNode);	//�ҵ�Ŀ��ڵ㣬�����ݹ�ڵ㣬����ɾ���ڵ�׶�
		if (curNode->right)DelTreeNodeRecur(curNode->right, curNode->val);
		else DelTreeNodeRecur(curNode->left, curNode->val);
		return true;
	}
	else if (item < curNode->val) {
		DelTreeNodeRecur(curNode->left, item);
	}
	else if (item > curNode->val) {
		DelTreeNodeRecur(curNode->right, item);
	}
	curNode->deepth = std::max(GetHeight(curNode->left) + 1, GetHeight(curNode->right) + 1);		//���½ڵ�߶ȣ�׼������AVLƽ��
	int balance = GetHeight(curNode->left) - GetHeight(curNode->right);
	if (balance > 1) {	//L��ʧ��
		AVLTreeNode* temp = curNode->left;
		if (GetHeight(temp->left) < GetHeight(temp->right)) {		//LR��ʧ��	
			temp = NodeLLTwist(temp);	//ת����LL��ʧ��
		}
		curNode = NodeLLTwist(curNode);	//LL��ʧ�⴦��
	}
	else if (balance < -1) {	//R��ʧ��
		AVLTreeNode* temp = curNode->right;
		if (GetHeight(temp->left) > GetHeight(temp->right)) {		//RL��ʧ��
			temp = NodeRRTwist(temp);	//ת����RR��ʧ��
		}
		curNode = NodeRRTwist(curNode);	//RR��ʧ�⴦��
	}
	//�������̿��Ա�����Ϊһ��ʧ�⴦�������ú�����Ҫ����������balance��curNode��
	//��Ϊʱ�������ҽ�Ϊ�򵥱����ڴ˲����޸ģ�����Ȥ�������г���

	return true;
}

void AVLTreeNodeDel(AVLTree* tree, int item)
{
	AVLTreeNode* root = tree->tree;
	bool flag = DelTreeNodeRecur(root, item);
	if (flag) tree->size--;
}

static void ReleaseTree(AVLTreeNode* root)
{
	if (root == nullptr) {
		return;
	}
	ReleaseTree(root->left);
	ReleaseTree(root->right);
	delete root;
}

void RelAVLTreeNode(AVLTree* tree)
{
	AVLTreeNode* root = tree->tree;
	ReleaseTree(root);
	tree->size = 0;
	delete root;
	root = nullptr;
}