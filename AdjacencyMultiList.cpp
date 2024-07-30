#include "AdjacencyMultiList.h"
#include <iostream>

using namespace std;

AdjMultiList* createMultiList(int n)
{
	AdjMultiList* graph = new AdjMultiList;
	graph->node_num = n;
	graph->flag = new int[n];
	graph->head_node_set = new AdjMultiListHeadNode[n];
	graph->edge_num = 0;
	graph->dir = 0;
	for (int i = 0; i < n; i++) {
		graph->flag[i] = false;
		graph->head_node_set[i].next = nullptr;
	}

	return graph;
}

void initAdjMultiList(AdjMultiList* graph, string item_flow[], unsigned int node_num, bool dir)
{
	graph->dir = dir;
	for (int i = 0; i < node_num; i++) {
		graph->head_node_set[i].name = item_flow[i];
		graph->head_node_set[i].source_id = i;
		graph->head_node_set[i].next = nullptr;
	}
	return;
}

static AdjMultiListNode* createAdjMultiListNode(int dest_node_id, int length) {
	AdjMultiListNode* node = new AdjMultiListNode;
	node->length = length;
	node->dest_id = dest_node_id;
	node->next = nullptr;

	return node;
}

void addAdjMultiListEdge(int source_node_id, int dest_node_id, AdjMultiList* graph, int length)
{
	AdjMultiListNode* node = createAdjMultiListNode(dest_node_id, length);
	node->next = graph->head_node_set[source_node_id].next;
	graph->head_node_set[source_node_id].next = node;

	return;
}

static void visitNode(adjMultiListHeadNode* node)
{
	cout << node->name << endl;
}

void DFSAdjMultiListEdgeTraversal(AdjMultiList* graph, int head_node_idx)
{
	AdjMultiListHeadNode* cur = &graph->head_node_set[head_node_idx];
	visitNode(cur);
	graph->flag[head_node_idx] = true;
	for (AdjMultiListNode* i = cur->next; i != nullptr; i = i->next) {
		if (!graph->flag[i->dest_id]) {
			DFSAdjMultiListEdgeTraversal(graph, i->dest_id);
		}
	}
}

void BFSAdjMultiListEdgeTraversal(AdjMultiList* graph, int head_node_idx)
{
	int queue[MAXNODENUM] = { 0 };
	int rear = 0, front = 0;
	queue[front++] = head_node_idx;
	front %= MAXNODENUM;
	graph->flag[head_node_idx] = true;
	while (front != rear) {
		int id = queue[rear++];
		rear %= MAXNODENUM;
		AdjMultiListHeadNode* cur = &graph->head_node_set[id];
		visitNode(cur);
		graph->flag[id] = true;
		for (AdjMultiListNode* i = cur->next; i != nullptr; i = i->next) {
			int temp_id = i->dest_id;
			if (!graph->flag[temp_id]) {
				queue[front++] = temp_id;
				front %= MAXNODENUM;
			}
		}
	}
}
