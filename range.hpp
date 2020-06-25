#ifndef ITERATORSTRUCT_RANGE_HPP
#define ITERATORSTRUCT_RANGE_HPP
using namespace std;

namespace itertools{
    class range{
        int _start, _end;

    public:
     range(int s, int l)
            {
                _start = s;
                _end = l;
            }
       

        class iterator{
            int _num;
        public:
            iterator(int start = 0)
                    {
                        _num = start;
                    }
            
            iterator& operator=(const iterator& other){
                if(this != &other)
                    this->_num = other._num;
                return *this;
            };
            iterator& operator ++(){
                _num++;
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                _num++;
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (_num == other._num);
            }
            bool operator !=(const iterator& other) {
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