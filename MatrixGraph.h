#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include <string>
constexpr auto MAXVERNUM = 100;
constexpr auto INF = 0x3f3f3f3f;
//��ͼ�����ǲ���ͨ��

typedef struct {
	int vertex_id;	//������
	std::string show;		//����ֵ
}MatrixGraphVertex;

typedef int MatrixGraphEdge;

typedef struct {
	MatrixGraphEdge Graph[MAXVERNUM][MAXVERNUM];		//ͼ����
	MatrixGraphVertex MatrixGraphVertexSet[MAXVERNUM];		//���㼯��
	bool dir;	//�Ƿ�Ϊ����ͼ
	unsigned int num_edge = 0;		//������
	unsigned int num_vertex = 0;		//Լ����������
}MatrixGraph;

void initMatrixGraph(MatrixGraph* graph, std::string MGraVerShowFlow[], unsigned int num_vertex, bool dir, int edge_value);

void addMatrixGraphEdge(MatrixGraph* graph, unsigned int source_node_idx, unsigned dest_node_idx, int val = 1);

void DFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx);

void BFSGraphTraversal(MatrixGraph* graph, unsigned int head_node_idx);

void initFlag(void);

#endif