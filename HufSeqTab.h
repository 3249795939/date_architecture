#ifndef HUFSEQTAB_H 
#define	HUFSEQTAB_H

typedef struct{
	int weight;
	int l_child; int r_child;
	int parent;
}HufSeqTabNode,*HufSeqTab;

HufSeqTab createHufSeqTab(unsigned int length,const int* w);	//��֪һ����ŵ�Ȩֵ������һ����������

void releaseHufSeqTab(HufSeqTab tree);

typedef char* HufCode;

HufCode* createHufCode(HufSeqTab tree, unsigned int length);

void releaseHufCode(HufCode* codes, unsigned int length);

#endif