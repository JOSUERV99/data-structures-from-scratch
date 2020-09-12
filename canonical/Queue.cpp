#ifndef __Q__
	#include"Queue.h"
#endif

template <class T>
int Queue<T>::size() {
	return length;
}

template <class T>
bool Queue<T>::isEmpty() {
	return length <= 0;
}

template <class T>
void Queue<T>::push(T value) {
	if (!begin) 
		begin = end = new Node<T>(value);
	else {
		end->next = new Node<T>(value);
		end->next->parent = end;
		end = end->next;
	}
	length++;
}

template <class T>	
void Queue<T>::pop() {
	if (!isEmpty()) {
		Node<T>* iter = begin;
		if (begin->next) {
			begin  = begin->next;
		}
		delete iter;
		length--;
	}
}

template <class T>	
T Queue<T>::top() {
	T retValue;
	if (!end){
		return retValue;
	}
	else 
		return end->getValue();
}

template <class T>	
T Queue<T>::base() {
	T retValue;
	if (!begin)
		return retValue;
	else 
		return begin->getValue();
}
