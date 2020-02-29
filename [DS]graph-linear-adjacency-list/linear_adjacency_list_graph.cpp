#include "linear_adjacency_list_graph.h"

linear_adjacency_list_graph::linear_adjacency_list_graph(){}
linear_adjacency_list_graph::linear_adjacency_list_graph(int _nodes_number, int _edges)
{
    last=0;

    head=new int[_nodes_number];
    next=new int[_edges];
    to  =new int[_edges];
    cost=new int[_edges];

    memset(head,-1,_nodes_number);
}
linear_adjacency_list_graph::~linear_adjacency_list_graph()
{
    delete head;
    delete next;
    delete to;
    delete cost;
}


void linear_adjacency_list_graph::add_edge(int u, int v, int c)
{
    next[last]  =head[u];
    to  [last]  =v;
    cost[last]  =c;
    head[u]     =last;

    last++;
}
void linear_adjacency_list_graph::node_adjacency_list(int _node)
{
    cout<<"Adjacency list of node: "<<_node<<endl;
    for(int i=this->head[_node]; i!=-1; i=next[i])
    {
        cout<<"Node: "<<to[i]<<" cost: "<<cost[i]<<endl;
    }
}
