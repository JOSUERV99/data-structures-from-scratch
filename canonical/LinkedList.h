#define __LL__

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

	T last(); // return the last values
	T first(); // return the first value

	void setValue(int, T); // change the T element of the node on the given index
	void erase(T); // erase the T element
	void clear(); // clear the list, delete every node

	LinkedList<T> subList(int,int); // return a sublist of the range

    // to string method (useful for testing but you need to implement the operator << for the structure)
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