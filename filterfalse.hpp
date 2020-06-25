#ifndef ITERATORSTRUCT_FILTERFALSE_HPP
#define ITERATORSTRUCT_FILTERFALSE_HPP

template <typename Function, typename T>
class filterfalse {
    const T& my_container;
    const Function& func;
public:
    filterfalse(const Function& f, const T& container): my_container(container) , func(f){}
    class iterator{
        decltype(my_container.begin()) itr;
        const filterfalse& my_obj;
    public:
        iterator(decltype(my_container.begin()) it, const filterfalse& obj): itr(it),my_obj(obj){
            while (itr!=my_obj.my_container.end() && (my_obj.func(*itr))){
                itr++;
            }
        }

        iterator& operator++(){
            ++itr;
            while(itr!=my_obj.my_container.end() && my_obj.func(*itr))++itr ;
            return *this;
        }

        const iterator operator++(int){
            iterator temp = *this;
            ++itr;
            return temp;
        }

        bool operator==(const iterator& it) const{
            return itr==it.itr;
        }

        bool operator!=(const iterator& it) const{
            return itr!=it.itr;
        }

        auto operator*(){
            return *itr;
        }
    };
    iterator begin() const{
        return iterator(my_container.begin(),*this);
    }
    iterator end() const{
        return iterator(my_container.end(),*this);
    }

};


#endif 