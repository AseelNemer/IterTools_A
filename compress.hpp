
#ifndef ITERATORSTRUCT_COMPRESS_HPP
#define ITERATORSTRUCT_COMPRESS_HPP

#pragma once
#include <iostream>


namespace itertools
{

    template <class T1, class T2>
    class compress
    {
    
        const T1& m_container;
        const T2& m_bool_container;

    public:
    compress(const T1& container,const  T2& bool_container):
    m_container(container),
    m_bool_container(bool_container)
    {}



        /* the iterator */
        class iterator
        {
            
            const compress& comp;
            decltype(m_container.begin()) iterObj;
            decltype(m_bool_container.begin()) iterBool;
        public:
            iterator(const compress& compress_func,
            decltype(m_container.begin()) iter_Obj,
            decltype(m_bool_container.begin()) iter_Bool) :
            iterObj(iter_Obj), comp(compress_func)
            {
                if(iterBool!=compress_func.m_bool_container.end()) iterBool=iter_Bool;
                while(iterBool!=comp.m_bool_container.end() && *iterBool == false) {
                    iterObj++;
                    iterBool++;
                }
            }


            iterator(const iterator &other) : iterObj(other.iterObj),
                                              iterBool(other.iterBool),
                                             comp(other.comp) {}



             iterator& operator++(){
                ++iterObj;
                ++iterBool;
                while(iterBool!=comp.m_bool_container.end() && !(*iterBool)) {
                    iterObj++;
                    iterBool++;
                }
                return *this; 
            }

        const iterator operator++(int){
                iterator temp = *this;
                while(iterBool!=comp.m_bool_container.end() && !(*iterBool)) {
                    iterObj++;
                    iterBool++;
                }
                return temp;
            }

            bool operator==(const iterator& it) const{
                return iterObj == it.iterObj;
                
            }

            bool operator!=(const iterator& it) const{
                return (iterObj != it.iterObj);
                
            }

            auto operator*(){
                return *iterObj;
            }

        
        };

        /* compress methods - decleration */
       // compress(T1 container, T2 bool_container) : m_container(container),
         //                                           m_bool_container(bool_container) {}
        iterator begin() const
        {
            return iterator(*this,m_container.begin(), m_bool_container.begin());
        }
        iterator end() const
        {
            return iterator(*this,m_container.end(), m_bool_container.end());
        }
    };
} 
#endif