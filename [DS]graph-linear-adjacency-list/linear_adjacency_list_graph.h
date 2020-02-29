#include <iostream>
#include <cstring>

using namespace std;

#ifndef LINEAR_ADJACENCY_LIST_GRAPH_H
#define LINEAR_ADJACENCY_LIST_GRAPH_H



class linear_adjacency_list_graph
{
    private:
        int last;       //position of new edge to be inserted
        int *head;      //head of the list of connected nodes
        int *next,      //index of the next connected node in the to[]
            *to,
            *cost;

    public:
        linear_adjacency_list_graph();
        linear_adjacency_list_graph(int _nodes_number, int _edges);
        virtual ~linear_adjacency_list_graph();

        void add_edge(int u, int v, int c);
        void node_adjacency_list(int _node);



};

#endif // LINEAR_ADJACENCY_LIST_GRAPH_H
