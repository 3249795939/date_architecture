#ifndef ADJACENCYMULTILIST_H
#define ADJACENCYMULTILIST_H
#include <string>

constexpr auto MAXNODENUM = 100;
constexpr auto INF = 0x3f3f3f3f;

typedef struct adjMultiListNode {
	int dest_id;
	int length;
	adjMultiListNode* next;
}AdjMultiListNode;

typedef struct adjMultiListHeadNode {
	int source_id;
	std::string name;
	AdjMultiListNode* next;
}AdjMultiListHeadNode;

typedef struct adjMultiList {
	AdjMultiListHeadNode* head_node_set;
	unsigned int node_num;
	unsigned int edge_num;
	bool dir;
	int* flag;
}AdjMultiList;

AdjMultiList* createMultiList(int n);

void initAdjMultiList(AdjMultiList* graph, std::string item_flow[], unsigned int node_num, bool dir);

void addAdjMultiListEdge(int source_node_id, int dest_node_id, AdjMultiList* graph, int length = 0);

void DFSAdjMultiListEdgeTraversal(AdjMultiList* graph, int head_node_idx);

void BFSAdjMultiListEdgeTraversal(AdjMultiList* graph, int head_node_idx);

#endif