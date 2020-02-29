//////////////////////////////////////////////////////////////////
// Created by elshaaer on 29/02/2020.
//////////////////////////////////////////////////////////////////
// This is the implementation of the second heuristic tour
// problem in CH1 of Skienna Algorithm design manual
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

#include "DisjointSet.h"

void closest_pair(std::pair<double, double> *, int);
bool valid_link(int , int, DisjointSet*, int);
bool same_vertex(int, int, DisjointSet*);
bool is_terminals(int p1, int p2, Array<bool> is_terminal);
void process_edge(int u, int v);


double get_distance(const std::pair<double, double> *, const std::pair<double, double> *);
bool is_closer(const std::pair<double, double> *, int, int, std::pair<double, double>&);

int main()
{

}

void closest_pair(std::pair<double, double> *points, int n)
{
    auto *disjoint_vertex_chains = new DisjointSet;
    disjoint_vertex_chains->initialize(n);

    Array<bool> terminals;
    terminals.initialize(n, true);

    for(int i=0; i<n-1; ++i)
    {
        double d = INT32_MAX;
        int sm = -1, tm = -1;

        for(int j=0; j<n-1; ++j)
            for(int k=j+1; k<n; ++k)
            {
                if(
                        is_terminals(j, k, terminals) &&
                        valid_link(j, k, disjoint_vertex_chains, n) &&
                        get_distance(&points[j], &points[k]) <= d
                        )
                {
                    d = get_distance(&points[j], &points[k]);
                    sm = j; tm = k;
                }
            }

        if (disjoint_vertex_chains->set_size(disjoint_vertex_chains->find(sm)) > 1)
            terminals[sm] = false;

        if (disjoint_vertex_chains->set_size(disjoint_vertex_chains->find(tm)) > 1)
            terminals[tm] = false;

        disjoint_vertex_chains->set_union(sm, tm);
        process_edge(sm, tm);
    }
}

void process_edge(int u, int v)
{
    /**
     * This would be whatever has to be done, like
     * constructing a graph. I will just print out the edge.
     */

    std::cout<<"edge: "<<u<<", "<<v<<std::endl;
}

bool valid_link(int p1, int p2, DisjointSet *links, int n)
{
    return !same_vertex(p1, p2, links);
}

bool same_vertex(int p1, int p2, DisjointSet *links)
{
    return p1 == p2 || links->find(p1) == links->find(p2);
}

bool is_terminals(int p1, int p2, Array<bool> is_terminal) {
    return is_terminal[p1] && is_terminal[p2];
}

bool is_closer(const std::pair<double, double> *points, int point, int comparable_point, std::pair<double, double> &nearest_point)
{
    return  point != comparable_point &&
            get_distance(&points[point], &points[comparable_point]) < get_distance(&points[point], &nearest_point);
}
double get_distance(const std::pair<double, double> *p1, const std::pair<double, double> *p2)
{
    return sqrt(pow(p1->first - p2->first, 2) + pow(p1->second - p2->second, 2));
}
