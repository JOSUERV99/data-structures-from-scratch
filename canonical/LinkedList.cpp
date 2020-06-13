template <class T>
class LinkedList {
public:
	// attributes
	int length;
	Node<T> *begin, *end;

	// builders
	LinkedList(): length(0), begin(nullptr), end(nullptr) {} // default builder

	// methods
	int size(); // size of the list
	int count(T); // count all the aparissons of the given T element

	bool contains(T); // true if contains the T element
	bool isEmpty(); // true if the length equals zero

	void push_back(T); // add an element to the end
	void push_front(T); // add an element to the begin
	T pop_back(); // pop and return the last value
	T pop_front(); // pop and return the first value

	void setValue(int, T); // change the T element of the node on the given index
	void erase(T); // erase the T element
	void clear(); // clear the list, delete every node

	LinkedList<T> subList(int,int); // return a sublist of the range

	// overwriting operators
	friend ostream& operator << (ostream &o,const LinkedList<T> &p) {
    	Node<T> *iter = p.begin;
		o << "[ ";
		while(iter) {
			o << iter->getValue();
			if (iter->next)
				o << ", ";
			iter = iter->next;
		}
		o << " ]";
		return o;
	}
};

template <class T>
int LinkedList<T>::size() {
	return length;
}

template <class T>
int LinkedList<T>::count(T value) {
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
	if (!begin)
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
	if (!begin) {
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
		while(index--) 
			iter = iter->next;

		iter->value = value;
	}
}

template <class T>
void LinkedList<T>::erase(T value) {

	if (!begin)
		return;

	Node<T> *iter = begin;

	if (begin->getValue() == value) {
		begin = begin->next;
	} else {
		Node<T> *previous = nullptr;
		while (iter) {
			if (iter->getValue() == value)
				break;

			previous = iter;
			iter = iter->next;
		}

		if (!iter)
			return;

		previous->next = iter->next;
	}
	
	if (iter) {
		length--;
		delete iter;
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
	if ( startIndex > endIndex || begin == nullptr || length <= endIndex ) {
		return newList;
	}

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