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
