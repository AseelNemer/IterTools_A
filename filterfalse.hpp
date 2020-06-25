#ifndef ITERATORSTRUCT_FILTERFALSE_HPP
#define ITERATORSTRUCT_FILTERFALSE_HPP
using namespace std;

namespace itertools{
    template <typename F, typename T>
    class filterfalse{
         T m_container;
        F m_function;
    public:
      filterfalse(F func, T container) : m_container(container),
                                           m_function(func) {}

        class iterator{
             typename T::iterator m_begin;
            typename T::iterator m_end;
            F m_ifunction;
            decltype(*(m_container.begin())) m_current_false;
        public:
            iterator(typename T::iterator from, typename T::iterator to, F func) : m_begin(from),
                                                                                   m_end(to),
                                                                                   m_ifunction(func),
                                                                                   m_current_false(*from){}

            iterator(const iterator &other) : m_begin(other.m_begin),
                                              m_end(other.m_end),
                                              m_ifunction(other.m_ifunction){}
            
            iterator& operator=(const iterator& other){
                if(this != &other)
                    this->_num = other._num;
                return *this;
            };
            iterator& operator ++(){
                return *this;
            }
            iterator operator ++(int){
                
                return *this;
            }
           bool operator==(const iterator &other) const
            {
                return m_begin == other.m_begin;
            }
            bool operator!=(const iterator &other) const
            {
                return false;
            }
            decltype(*(m_container.begin())) operator*() const
            {

                return m_current_false;
            }
        };

public:
        
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