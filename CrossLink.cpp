#include "CrossLink.h"
#include <iostream>

CrossLink* createCrossLink(int vertex_num)
{
	CrossLink* g = new CrossLink;
	g->head_node_set = new CrossLinkHeadNode[vertex_num];
	g->vertex_num = vertex_num;
	g->edge_num = 0;
	return g;
}

void initCrossLink(CrossLink* g, std::string* s, int vertex_num)
{
	for (int i = 0; i < vertex_num; i++) {
		g->head_node_set[i].show = s[i];
		g->head_node_set[i].first_in_node = g->head_node_set[i].first_out_node = nullptr;
		g->head_node_set[i].node_id = i;
	}
}

static CrossLinkNode* createCrossLinkNode(int source_node_id, int dest_node_id, int weight)
{
	CrossLinkNode* n = new CrossLinkNode;
	n->in_node_id = source_node_id;
	n->in_node_next = nullptr;
	n->out_node_id = dest_node_id;
	n->out_node_next = nullptr;
	n->weight = weight;
	
	return n;
}

int addCrossLinkEdge(CrossLink* g, int source_node_id, int dest_node_id, int weight)
{
	CrossLinkNode* new_node = createCrossLinkNode(source_node_id, dest_node_id, weight);
	if (new_node == nullptr) {
		return -1;
	}
	new_node->in_node_next = g->head_node_set[source_node_id].first_in_node;
	g->head_node_set[source_node_id].first_in_node = new_node;
	new_node->out_node_next = g->head_node_set[dest_node_id].first_out_node;
	g->head_node_set[dest_node_id].first_out_node = new_node;
	g->edge_num++;
	return 0;
}

int deleteCrossLinkEdge(CrossLink* g, int source_node_id, int dest_node_id)
{
	CrossLinkNode* pre_in = nullptr;
	CrossLinkNode* first_in = g->head_node_set[source_node_id].first_in_node;
	while (first_in && first_in->out_node_id != dest_node_id) {
		pre_in = first_in;
		first_in = first_in->in_node_next;
	}
	if (first_in == nullptr||first_in->out_node_id != dest_node_id) {
		return -1;
	}
	CrossLinkNode* pre_out = nullptr;
	CrossLinkNode* first_out = g->head_node_set[dest_node_id].first_out_node;
	while (first_out && first_out->in_node_id != source_node_id) {
		pre_out = first_out;
		first_out = first_out->out_node_next;
	}
	if (first_out == nullptr||first_out->in_node_id != source_node_id) {
		return -1;
	}
	if (pre_in) {
		pre_in->in_node_next = first_in->in_node_next;
	}
	if (pre_out) {
		pre_out->out_node_next = first_out->out_node_next;
	}
	delete first_in;
	return 0;
}

int getInDegree(CrossLink* g, int node_id)
{
	int idx = 0;
	CrossLinkNode* cur = g->head_node_set[node_id].first_in_node;
	while (cur) {
		cur = cur->in_node_next;
		idx++;
	}
	return idx;
}

int getOutDegree(CrossLink* g, int node_id)
{
	int idx = 0;
	CrossLinkNode* cur = g->head_node_set[node_id].first_out_node;
	while (cur) {
		cur = cur->out_node_next;
		idx++;
	}
	return idx;
}

static void deleteEdge(CrossLink* g, int node_id)
{
	CrossLinkNode* cur = g->head_node_set[node_id].first_in_node;
	while (cur) {
		CrossLinkNode* temp = cur;
		cur = cur->in_node_next;
		delete temp;
	}
}

void releaseAdjLink(CrossLink* g)
{
	for (int i = 0; i < g->vertex_num; i++) {
		deleteEdge(g, i);
	}
	delete[] g->head_node_set;
	delete g;
	g = nullptr;
}
