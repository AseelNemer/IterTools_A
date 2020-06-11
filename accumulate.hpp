#ifndef ACCU_H
#define ACCU_H
#include <iostream>
#include <vector>
#include <typeinfo>

#include <iterator>

using namespace std;

namespace itertools{

	class plus
    {
    public:
        template <typename T2>
        T2 operator()(T2 a, T2 b) { return a + b; }
    };

	template <typename Container,typename Function = plus>
	class accumulate{
		
		private:
			Container container;
			Function func;

		public:
			accumulate( Container cont, Function func = plus()):container(cont),func(func){}

		class iterator {

			private:
				decltype(*(container.begin())) sum;
				typename Container::iterator pos;
				typename Container::iterator end;
				Function func;

			public:

				iterator(typename Container::iterator p,typename Container::iterator end,Function func): 
					pos(p),end(end),func(func),sum(*pos) {
				}


				decltype(*(container.begin())) operator*() const
            {
                return sum;
            }
				iterator& operator++() {
					++pos;
					if(pos!=end){
						sum=func(sum,*(pos));
					}
					return *this;
				}

				// i++;
				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
					sum=func(sum,*(pos));
					return tmp;
				}

				bool operator==(const iterator& rhs)  {
					return pos == rhs.pos;
				}

				bool operator!=(const iterator& rhs)  {
					return pos != rhs.pos;
				}
			};  // END OF CLASS ITERATOR

			iterator begin() {
				return iterator(container.begin(),container.end(),func);
				
			}

			iterator end() {
				return iterator(container.end(),container.end(),func);
			}


	};
}

#endif
