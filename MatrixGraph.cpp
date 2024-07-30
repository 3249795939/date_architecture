#include "MatrixGraph.h"
#include <exception>
#include <string>
#include <iostream>

void initMatrixGraph(MatrixGraph* graph,std::string MGraVerShowFlow[], unsigned int num_vertex, bool dir, int edge_value)
{
	graph->dir = dir;
	graph->num_vertex = num_vertex;
	graph->num_edge = 0;
	for (int i = 0; i < num_vertex; i++) {
		graph->MatrixGraphVertexSet[i].show = MGraVerShowFlow[i];
		graph->MatrixGraphVertexSet[i].vertex_id = i;
		for (int j = 0; j < graph->num_vertex; j++) {
			graph->Graph[i][j] = edge_value;
		}
	}
}

static bool isEdge(MatrixGraph* graph, int i, int j)
{
	if (graph->Graph[i][j] == INF || graph->Graph[i][j] == 0) {
		return false;
	}

	return true;
}

void addMatrixGraphEdge(MatrixGraph* graph, unsigned int source_node_idx, unsigned dest_node_idx, int val)
{
	if (isEdge(graph,source_node_idx,dest_node_idx)) {
		return;
	}
	graph->Graph[source_node_idx][dest_node_idx] = val;
	if (!graph->dir) {
		graph->Graph[dest_node_idx][source_node_idx] = val;
	}
	graph->num_edge++;
}

static bool flag[MAXVERNUM] = {0};

static void visitNode(MatrixGraphVertex* node)
{
	std::cout << node->show << std::endl;
}

void DFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx)
{
	MatrixGraphVertex* p = &graph->MatrixGraphVertexSet[head_node_idx];

	visitNode(p);
	flag[head_node_idx] = true;
	for (int i = 0; i < graph->num_vertex; i++) {
		if (isEdge(graph, head_node_idx, i)) {
			if (!flag[i]) {
				DFSGraphTraversal(graph, i);
			}
		}
	}
}

void BFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx)
{
	int queue[MAXVERNUM] = {0};
	int front = 0, rear = 0;
	queue[rear++] = head_node_idx;
	rear %= MAXVERNUM;
	flag[head_node_idx] = true;
	while (front != rear) {
		int cur = queue[front++];
		front %= MAXVERNUM;
		visitNode(&graph->MatrixGraphVertexSet[cur]);
		for (int i = 0; i < graph->num_vertex; i++) {
			if (isEdge(graph, cur, i) && !flag[i]) {
				queue[rear++] = i;
				rear %= MAXVERNUM;
				flag[i] = true;
			}
		}
	}
}

void initFlag(void)
{
	memset(flag, 0, sizeof(flag));
}