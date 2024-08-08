#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <string>

constexpr auto MAXNODENUM = 100;
constexpr auto INF = 0x3f3f3f3f;

typedef struct adjListNode {
	int dest_id;
	int length;
	adjListNode* next;
}AdjListNode;

typedef struct adjListHeadNode {
	int source_id;
	std::string name;
	AdjListNode* next;
}AdjListHeadNode;

typedef struct adjList {
	AdjListHeadNode* head_node_set;
	unsigned int node_num;
	unsigned int edge_num;
	bool dir;
	int* flag;
}AdjList;

AdjList* createList(int n);

void initAdjList(AdjList* graph, std::string item_flow[], unsigned int node_num, bool dir);

void addAdjListEdge(int source_node_id, int dest_node_id, AdjList* graph, int length = 0);

void DFSAdjListEdgeTraversal(AdjList* graph, int head_node_idx);

void BFSAdjListEdgeTraversal(AdjList* graph, int head_node_idx);

#endif