//
// Created by mhmelshaaer on 22/02/2020.
//

#include <iostream>
#include "Array.h"

#ifndef _EX_CH1_DISJOINTSET_H
#define _EX_CH1_DISJOINTSET_H


struct DisjointSet
{
    unsigned int m_size;
    Array<int> a_parent;
    Array<int> a_set_size;

    void initialize(unsigned int arg_size)
    {
        m_size = arg_size;

        a_parent.initialize(m_size);
        a_set_size.initialize(m_size);

        for(unsigned int i=0; i<m_size; ++i)
            a_parent.add_last(i);

        for(unsigned int i=0; i<m_size; ++i)
            a_set_size.add_last(1);
    }

    void destroy()
    {
        m_size = 0;
        a_parent.destroy();
        a_set_size.destroy();
    }

    unsigned int find(unsigned int set)
    {
        while(a_parent[set] != set)
            set = a_parent[set];

        return set;
    }

    bool set_union(unsigned int arg_set_a, unsigned int arg_set_b)
    {
        unsigned int    root_a = find(arg_set_a),
                root_b = find(arg_set_b);

        if(root_a == root_b) return false;

        if(a_set_size[root_a] < a_set_size[root_b])
        {
            a_parent[root_a] = root_b;
            a_set_size[root_b] += a_set_size[root_a];
        }
        else
        {
            a_parent[root_b] = root_a;
            a_set_size[root_a] += a_set_size[root_b];
        }

        return true;
    }

    unsigned int set_size(unsigned int set)
    {
        return a_set_size[set];
    }
};


#endif //_EX_CH1_DISJOINTSET_H
