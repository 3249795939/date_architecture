#ifndef HUFSEQTAB_H 
#define	HUFSEQTAB_H

typedef struct{
	int weight;
	int l_child; int r_child;
	int parent;
}HufSeqTabNode,*HufSeqTab;

HufSeqTab createHufSeqTab(unsigned int length,const int* w);	//已知一组符号的权值，创造一个哈夫曼树

void releaseHufSeqTab(HufSeqTab tree);

typedef char* HufCode;

HufCode* createHufCode(HufSeqTab tree, unsigned int length);

void releaseHufCode(HufCode* codes, unsigned int length);

#endif