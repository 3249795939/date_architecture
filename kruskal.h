#pragma once

#include "common.h"
#include "MatrixGraph.h"

EdgeSet* initEdgeSet(MatrixGraph* ptr);

int SortEdgeSet(EdgeSet* ptr, int num);

int Kruskal(const MatrixGraph* graph, const EdgeSet* edges, int num, EdgeSet* result);