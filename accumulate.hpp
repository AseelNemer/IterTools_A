#ifndef ACCU_H
#define ACCU_H
#include <iostream>
#include <vector>
#include <typeinfo>

#include <iterator>

using namespace std;

namespace itertools
{

    class plus
    {
    public:
        template <typename T2>
        T2 operator()(T2 a, T2 b) { return a + b; }
    };

    template <typename T, typename F = plus>
    class accumulate
    {
    private:
        T m_container;
        F m_function;

    public:
        /* the iterator */
        class iterator
        {
        public:
            iterator(typename T::iterator from, typename T::iterator to, F func) : m_begin(from),
                                                                                   m_end(to),
                                                                                   m_ifunction(func),
                                                                                   m_current_sum(*from) {}
            iterator(const iterator &other) : m_begin(other.m_begin),
                                              m_end(other.m_end),
                                              m_ifunction(other.m_ifunction),
                                              m_current_sum(other.m_current_sum) {}
            decltype(*(m_container.begin())) operator*() const
            {
                return m_current_sum;
            }
            iterator &operator++()
            {
                
                return *this;
            }
            bool operator!=(const iterator &other) const
            {
                return false
				;
            }

        private:
            typename T::iterator m_begin;
            typename T::iterator m_end;
            F m_ifunction;
            decltype(*(m_container.begin())) m_current_sum;
        };

    public:
        /* accumulate methods - decleration */
        accumulate(T container, F func = plus()) : m_container(container),
                                                   m_function(func) {}
        iterator begin()
        {
            return iterator{m_container.begin(), m_container.end(), m_function};
        }
        iterator end()
        {
            return iterator{m_container.end(), m_container.end(), m_function};
        }
    };
} 
#endif