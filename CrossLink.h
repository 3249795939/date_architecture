#ifndef CROSSLINK_H
#define CROSSLINK_H

constexpr int INF = 0x3f3f3f3f;

typedef struct crossLinkNode {
	int in_node_id;						//��ڵ�
	crossLinkNode* in_node_next;		//��һ����ڵ㣬�����
	int out_node_id;						//���ڵ�
	crossLinkNode* out_node_next;		//��һ�����ڵ㣬������
	int weight;
}CrossLinkNode;

#include <string>

typedef struct crossLinkHeadNode {
	int node_id = -1;
	std::string show;
	CrossLinkNode* first_in_node = nullptr;
	CrossLinkNode* first_out_node = nullptr;
}CrossLinkHeadNode;

typedef struct crossLink {
	CrossLinkHeadNode* head_node_set;
	int vertex_num;
	int edge_num;
}CrossLink;

CrossLink* createCrossLink(int vertex_num);

void initCrossLink(CrossLink* g, std::string* s, int vertex_num);

int addCrossLinkEdge(CrossLink* g, int source_node_id, int dest_node_id, int weight = INF);

int deleteCrossLinkEdge(CrossLink* g, int source_node_id, int dest_node_id);

int getInDegree(CrossLink* g, int node_id);

int getOutDegree(CrossLink* g, int node_id);

void releaseAdjLink(CrossLink* g);

#endif // CROSSADJLINK_H