#ifndef C___RANGE_HPP
#define C___RANGE_HPP

#include <iostream>
#include <string>

#pragma once

namespace itertools{
    class range{
        int _start, _end;

    public:
    typedef int value_type;
     range(int s, int l):_start(s),_end(l){}
            
        class iterator{
            int _num;
        public:
            iterator(int start):
                        _num(start){}
            
            iterator& operator=(const iterator& other){
                if(this != &other)
                    this->_num = other._num;
                return *this;
            };
            iterator& operator ++(){
                ++_num;
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++_num;
                return tmp;
            }
            bool operator ==(const iterator& other) const{
                return (_num == other._num);
            }
            bool operator !=(const iterator& other) const{
                return (_num != other._num);
            }
            int operator *(){
                return _num;
            }
        };


        iterator begin() const
        {
            return iterator(_start);
        }

        iterator end() const
        {
            return iterator(_end);
        }   
         };

}
#endif