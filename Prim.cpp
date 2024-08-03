#include "Prim.h"
#include <iostream>

int Prim(MatrixGraph* g, int start_id, EdgeSet* result)
{
    int num_edge = g->num_vertex - 1;
    bool* mark = new bool[g->num_vertex];       //�Ƿ񱻱��Ϊ��ȷ���ڵ㣨���ڵ�ǰ�������У�
    int* visit = new int[g->num_vertex];        //�ýڵ�����С�������еĸ��ڵ�
    int* dist = new int[g->num_vertex];         //���뼯�ϵľ���
    int res = 0;                                //��С��������Ȩֵ
    int idx = 0;

    //��ʼ����������

    for (int i = 0; i < g->num_vertex; i++) {
        mark[i] = false;
        visit[i] = -1;
        dist[i] = INF;
    }

    //��ʼ���ڵ�

    mark[start_id] = true;
    for (int i = 0; i < g->num_vertex; i++) {
        if (dist[i] > g->Graph[start_id][i]) {
            dist[i] = g->Graph[start_id][i];
            visit[i] = start_id;
        }
    }

    //ѭ���ұߣ�������С������

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
        //���õ��ǣ����빹������
        mark[cur_node] = true;
        //�øõ�ȥ��������δ��ǵ�
        for (int j = 0; j < g->num_vertex; j++) {
            if (!mark[j] && dist[j] > g->Graph[cur_node][j]) {
                dist[j] = g->Graph[cur_node][j];
            }
        }
        //����Ȩֵ�ͱ߼�����
        res += cur_dist;
        result[idx].dest_id = visit[cur_node];
        result[idx].source_id = cur_node;
        result[idx].weight = cur_dist;
        idx++;
    }

    return res;
}
