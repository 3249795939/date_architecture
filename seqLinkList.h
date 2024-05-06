#ifndef SEQLINKLIST_H
#define SEQLINKLIST_H

typedef int Element;
//1.0 defination of seqLinkNode

typedef struct seqLinkNode{
	Element val;
	seqLinkNode* next;
}seqLinkNode;

//2.0 defination of seqLinkList

typedef struct {
	seqLinkNode head;
	int linkSize;
}seqLinkList;

//3.0 linkList's interface
//3.1 head's initialization and free

seqLinkList* createSeqLinkList();

void releaseSeqLinkList(seqLinkList* seq_link_list);

//3.2 way of inserting into List

int insertSeqLinkHeader(seqLinkList* seq_link_list,Element item);
int insertSeqLinkPos(seqLinkList* seq_link_list, int K,Element item);

//3.3 traversal of seqLinkList

void showSeqLinkList(seqLinkList* seq_link_list);

//3,4 delete of seqLinkList

void deleteSeqLinkListHeader(seqLinkList* seq_link_list);
void deleteSeqLinkListPos(seqLinkList* seq_link_list, int K);

//3.5 search of seqLinkList

int findKthSeqLinkList(seqLinkList* seq_link_list,Element destination);

//�Ƽ���Ŀ��leetcode 21.�ϲ����飨���˽���ݹ�ͱ�����ʵϰһ�£�206.��ת�������˽���ݹ�ͱ�����ʵϰһ�£�

#endif