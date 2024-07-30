#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include <string>
constexpr auto MAXVERNUM = 100;
constexpr auto INF = 0x3f3f3f3f;
//本图不考虑不连通点

typedef struct {
	int vertex_id;	//顶点编号
	std::string show;		//顶点值
}MatrixGraphVertex;

typedef int MatrixGraphEdge;

typedef struct {
	MatrixGraphEdge Graph[MAXVERNUM][MAXVERNUM];		//图矩阵
	MatrixGraphVertex MatrixGraphVertexSet[MAXVERNUM];		//顶点集合
	bool dir;	//是否为有向图
	unsigned int num_edge = 0;		//边数量
	unsigned int num_vertex = 0;		//约束顶点数量
}MatrixGraph;

void initMatrixGraph(MatrixGraph* graph, std::string MGraVerShowFlow[], unsigned int num_vertex, bool dir, int edge_value);

void addMatrixGraphEdge(MatrixGraph* graph, unsigned int source_node_idx, unsigned dest_node_idx, int val = 1);

void DFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx);

void BFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx);

void initFlag(void);

#endif