#include "Prim.h"
#include <iostream>

int Prim(MatrixGraph* g, int start_id, EdgeSet* result)
{
    int num_edge = g->num_vertex - 1;
    bool* mark = new bool[g->num_vertex];       //是否被标记为已确定节点（即在当前构造树中）
    int* visit = new int[g->num_vertex];        //该节点在最小生成树中的父节点
    int* dist = new int[g->num_vertex];         //距离集合的距离
    int res = 0;                                //最小生成树的权值
    int idx = 0;

    //初始化辅助数组

    for (int i = 0; i < g->num_vertex; i++) {
        mark[i] = false;
        visit[i] = -1;
        dist[i] = INF;
    }

    //初始起点节点

    mark[start_id] = true;
    for (int i = 0; i < g->num_vertex; i++) {
        if (dist[i] > g->Graph[start_id][i]) {
            dist[i] = g->Graph[start_id][i];
            visit[i] = start_id;
        }
    }

    //循环找边，构造最小生成树

    int cur_node = start_id;
    int cur_dist = INF;

    for (int i = 0; i < num_edge; i++) {
        cur_dist = INF;
        for (int j = 0; j < g->num_vertex; j++) {
            if (mark[j] && cur_dist < cur_dist) {
                cur_node = j;
                cur_dist = cur_dist;
            }
        }
        //将该点标记，放入构造树中
        mark[cur_node] = true;
        //拿该点去更新其他未标记点
        for (int j = 0; j < g->num_vertex; j++) {
            if (!mark[j] && dist[j] > g->Graph[cur_node][j]) {
                dist[j] = g->Graph[cur_node][j];
            }
        }
        //更新权值和边集数组
        res += cur_dist;
        result[idx].dest_id = visit[cur_node];
        result[idx].source_id = cur_node;
        result[idx].weight = cur_dist;
        idx++;
    }

    return res;
}
