#define __PQ__ 

#ifndef __LL__
    #include"LinkedList.h"
#endif

template <class T>
class PriorityQueue {
public:
    LinkedList<T> _self;
    PriorityQueue() {}

    int size();
    void push(T value);
    T pop();
    bool isEmpty();

    friend ostream& operator << (ostream &o, const PriorityQueue<T> &p) {
        return std::cout << p._self << std::endl;
    }

private:

};