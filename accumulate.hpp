#ifndef _ACCUMULATE__H
#define  _ACCUMULATE__H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>


namespace itertools
{
    class plus 
    {
    public:
        template <typename T2>
        T2 operator()  (T2 a, T2 b) const{ return a + b; }
    };

template<typename  R, typename Function = plus  > 
class accumulate{

 R my_container;
 Function function ;

public:
accumulate( R cont,Function func = plus()) :my_container(cont),function(func){};




public : 
class iterator{

private:

typename R::iterator begin;
typename R::iterator end;
typename R::value_type data;
Function my_function;
public:
iterator(typename R::iterator beg,typename R::iterator las,Function my_func):begin(beg),end(las),data(*beg),my_function(my_func){};


iterator(const iterator &other):begin(other.begin),end(other.end),data(other.data),my_function(other.my_function){};


auto operator*(){
	return data;
}

bool operator==(const iterator& other){
	return begin == other.begin;
	 
}
bool operator!=(const iterator& other){
	return begin != other.begin;


}
iterator& operator=(const iterator& other)
{
	if(this != &other)
	{
		this->data=other.data;
		this->begin=other.begin;
		this->end=other.end;
		this->my_function=other.my_function;
	}
	return *this;
};
   //++i

iterator& operator++() { 
	++begin;
	if(begin != end){
        data=my_function(data,*begin);      
	}
	return *this;
}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
const iterator operator++(int) {
	iterator tmp= *this;
	++begin;
	if(begin != end){
        accumulate::iterator::data=my_function(data,*begin);      
	} 
	return tmp;
}


};



	iterator begin() {
		return iterator{my_container.begin(),my_container.end(),function};
	}
	
	iterator end() {
		return iterator{my_container.end(),my_container.end(),function};
	}





};
//-----------------------------------------------------------------------------------------------------------






}
#endif
