#include"LinkedList.h"

template<class T>
T LinkedList<T>::first() {
	if ( isEmpty() )
		exit(1);
	
	return begin->getValue();
}

template<class T>
T LinkedList<T>::last() {
	if ( isEmpty() )
		exit(1);
	
	return end->getValue();
}

template <class T>
int LinkedList<T>::size() {
	return length;
}

template <class T>
int LinkedList<T>::count(T value) {

	if ( isEmpty() )
		return 0;

	int aparissons = 0;

	Node<T>* iter = begin;
	while(iter) {
		if (iter->getValue() == value)
			aparissons++;
		iter = iter->next;
	}

	return aparissons;
}

template <class T>
bool LinkedList<T>::contains(T value) {

	if ( isEmpty() )
		return false;

	Node<T> *iter = begin;
	while(iter) {
		if (iter->getValue() == value)
			return true;
		iter = iter->next;
	}

	return false;
}

template <class T>
bool LinkedList<T>::isEmpty() {
	return length == 0;
}

template <class T>
void LinkedList<T>::push_back(T value) {

	if ( isEmpty() ) {
		begin = end = new Node<T>(value);
		length++;
		return;
	}
	
	end->next = new Node<T>(value);
	end = end->next;
	length++;
}

template <class T>
void LinkedList<T>::setValue(int index, T value) {

	if (index >= 0 && index < length) {

		Node<T> *iter = begin;
		while(index--) iter = iter->next;
		iter->value = value;
	} 
}

template <class T>
void LinkedList<T>::erase(T value) {

	if ( isEmpty() )
		return;

	Node<T> *current = begin, *previous = nullptr;

	while (current && current->getValue() != value) {
		previous = current;
		current = current->next;
	}
	
	if (current) {
		
		if (current != begin)
			previous->next = current->next;
		else
			begin = begin->next;

		delete current;
		length--;
	}
}

template <class T>
void LinkedList<T>::clear() {
	Node<T> *iter = begin;
	while(length--) {
		Node<T> *target = iter;
		iter = iter->next;
		delete target;
	}

	begin = end = nullptr;
}

template <class T>
LinkedList<T> LinkedList<T>::subList(int startIndex, int endIndex) {
	
	LinkedList<T> newList;

	if ( startIndex > endIndex || begin == nullptr || length <= endIndex ) 
		return newList;

	int counter = 0;
	Node<T> *iter = begin;

	while(counter++ != startIndex)
		iter = iter->next;

	newList.begin = iter;
	while(counter++ != endIndex) {
		iter = iter->next;
		newList.begin->next = iter;
	}

	return newList;
}