//
// Created by mhmelshaaer on 22/02/2020.
//

#include <iostream>

#ifndef _EX_CH1_ARRAY_H
#define _EX_CH1_ARRAY_H


template<class Type>
struct Array
{
    int m_n, m_size;
    Type *p_elements;

    void initialize(unsigned int arg_size, int val=0)
    {
        m_size = arg_size;
        m_n = 0;
        p_elements = new Type[m_size];
        memset(p_elements, val, sizeof(Type) * m_size);
    }

    void destroy()
    {
        m_size = m_n = 0;
        delete[] p_elements;
    }

    void add_last(Type value)
    {
        if(m_n >= m_size)
        {
            m_size *= 2;
            Type *p_temp_elements = new Type[m_size];

            for(int i=0; i<m_n; ++i)
                p_temp_elements[i] = p_elements[i];

            p_elements = p_temp_elements;
        }

        p_elements[m_n++] = value;
    }

    void delete_last()
    {
        // You can make custom exception
        m_n > 0? --m_n: throw 1;
    }

    Type &operator[](unsigned int index)
    {
        if (index >= 0 && index <= m_size)
            return p_elements[index];
        throw 1;
    }

    void print(unsigned int n)
    {
        for(unsigned int i = 0; i < n; ++i)
            std::cout<<p_elements[i]<<", ";
        std::cout<<std::endl;
    }
};


#endif //_EX_CH1_ARRAY_H
