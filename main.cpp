#include <iostream>
#include <string>
#include "MatrixGraph.h"

using namespace std;

string view[10] = { "v0","v1" ,"v2" ,"v3" ,"v4" ,"v5" ,"v6" ,"v7" ,"v8" ,"v9" };

int main(void)
{
	MatrixGraph g;
	initMatrixGraph(&g, view, 10, 0, 0);
	initFlag();
	for (int i = 0; i < 10; i++) {
		cout << g.MatrixGraphVertexSet[i].show << ':' << g.MatrixGraphVertexSet[i].vertex_id << endl;;
	}
	for (int i = 1; i < 8; i++) {
		addMatrixGraphEdge(&g, 0, i);
	}
	addMatrixGraphEdge(&g, 1, 9);
	addMatrixGraphEdge(&g, 9, 8);
	for (int i = 0; i < g.num_vertex; i++) {
		for (int j = 0; j < g.num_vertex; j++) {
			cout << g.Graph[i][j] << ' ';
		}
		cout << endl;
	}
	DFSGraphTraversal(&g, 0);
}