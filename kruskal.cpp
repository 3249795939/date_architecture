#include "kruskal.h"
#include <iostream>
#include <algorithm>

EdgeSet* initEdgeSet(MatrixGraph* ptr)
{
    int num = ptr->num_edge; int n = 0;
    EdgeSet* res = new EdgeSet[num];
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            int length = ptr->Graph[i][j];
            if (length != 0 && length != INF) {
                res[n].dest_id = i;
                res[n].source_id = j;
                res[n].weight = length;
                n++;
            }
        }
    }
    return res;
}

static void quick_sort(EdgeSet* ptr, int l, int r)
{
    if (l >= r) {
        return;
    }
    int i = l,j = r;
    while (i < j) {
        while (i < j && ptr[i].weight <= ptr[j].weight) {
            i++;
        }
        while (i < j && ptr[i].weight >= ptr[j].weight) {
            j--;
        }
        std::swap(ptr[i], ptr[j]);
    }
    int mid = j;
    quick_sort(ptr, l, mid);
    quick_sort(ptr, mid + 1, r);
}

int SortEdgeSet(EdgeSet* ptr,int num)
{
    quick_sort(ptr, 0, num);
    return 0;
}

static int getRoot(int* set,int id)
{
    if (set[id] != id) {
        set[id] = getRoot(set, set[id]);        //µİ¹éÂ·¾¶Ñ¹Ëõ
    }

    return set[id];
}

int Kruskal(const MatrixGraph* graph, const EdgeSet* edges, int num, EdgeSet* result)
{
    int num_edge = graph->num_vertex - 1;
    int* set = new int[graph->num_vertex];
    EdgeSet* result = new EdgeSet[num_edge];
    for (int i = 0; i < graph->num_vertex; i++) {
        set[i] = i;
    }
    int n = 0;
    for (int i = 0; i < num; i++) {
        int source_id = edges[i].source_id;
        int dest_id = edges[i].dest_id;
        int a = getRoot(set, source_id);
        int b = getRoot(set, dest_id);
        if (a != b) {
            set[a] = b;
            result[n].dest_id = a;
            result[n].source_id = b;
            result[n].weight = edges[i].weight;
            n++;
            if (n == num_edge) {
                break;
            }
        }
    }
    return n;
}
