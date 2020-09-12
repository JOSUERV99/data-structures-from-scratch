#include "PriorityQueue.h"

template <class T>
void PriorityQueue<T>::push(T value) {
    _self.push_back(value);
}

template <class T>
bool PriorityQueue<T>::isEmpty(){
    return _self.isEmpty();
}

template <class T>
T PriorityQueue<T>::pop() {
    
    if ( isEmpty() )
        exit(1);

    T value =  _self.begin->getValue();
    
    for (auto *iter = _self.begin; iter != nullptr; iter=iter->next) 
    {    
        auto current = iter->getValue();
        value = value < current ? current : value;
    }

    _self.erase(value);

    return value;
}

template <class T>
int PriorityQueue<T>::size() {
    return _self.length;
}





