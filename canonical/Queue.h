#define __Q__

template <class T>
class Queue {
private:
	int length = 0;
	Node<T> *begin, *end;

public:
	Queue() : length(0), begin(nullptr), end(nullptr) {}

	// methods
	int size(); // size of the list
	bool isEmpty(); // true if the length equals zero

	void push(T); // add an element to the end
	void pop(); // pop and return the last value
	T top(); // return the last value
	T base(); // return the first value

	//overwriting operators
	friend ostream& operator << (ostream &o,const Queue<T> &p) {
    	Node<T> *iter = p.begin;
		o << "[ ";
		while(iter) {
			o << iter->getValue();
			if (iter->next)
				o << ", ";
			iter = iter->next;
		}
		o << " ]" << std::endl;
		return o;
	}
};