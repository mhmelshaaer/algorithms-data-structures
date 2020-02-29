//////////////////////////////////////////////////////////////////
// Created by elshaaer on 29/02/2020.
//////////////////////////////////////////////////////////////////
// This is the implementation of the first heuristic tour
// problem in CH1 of Skienna Algorithm design manual
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cmath>

std::pair<double, double> **nearest_neighbor(std::pair<double, double> *, int);
int get_nearest(std::pair<double, double> *,const bool *, int, int);

double get_distance(const std::pair<double, double> *, const std::pair<double, double> *);
bool is_closer(const std::pair<double, double> *, int, int, std::pair<double, double>&);

int main()
{



}

std::pair<double, double>** nearest_neighbor(std::pair<double, double> *points, int n)
{
    auto *visited = new bool[n];
    auto **nearestNeighbor = new std::pair<double, double >*[n];
    memset(visited, 0, n);

    int i=0;
    int pNearest = 0;
    visited[i] = true;
    nearestNeighbor[i] = &points[pNearest];

    while(++i<n)
    {
        pNearest = get_nearest(points, visited, n, pNearest);
        visited[pNearest] = true;
        nearestNeighbor[i] = &points[pNearest];
    }

    return nearestNeighbor;
}

int get_nearest(std::pair<double, double> *points,const bool *visited, int n, int p)
{
    auto pNearest= std::pair<double, double>(INT16_MAX, INT16_MAX);
    int index=-1;
    int i = 0;
    while(i<n)
    {
        if (!visited[i] && is_closer(points, p, i, pNearest))
        {
            pNearest = points[i];
            index = i;
        }

        ++i;
    }

    return index;
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