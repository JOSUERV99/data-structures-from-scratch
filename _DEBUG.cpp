#include "_DS_FromScratch.cpp"

template<class T>
class Object {
	T val;
	Object() : val(0) {}
	Object(T value) : val(value) {}

	//overwriting operators
	friend ostream& operator << (ostream &o,const Object<T> &p) {
    	o << "[" << p.val << "]";
		return o;
	}
};

int main() {

	PriorityQueue<int> pqueue;

	int input[] = {5, 4, 6, 3, 8, 7};

	for (int v : input) 
		pqueue.push(v);

	while ( !pqueue.isEmpty() ) {
		std::cout << pqueue.pop() << std::endl;
		cout << pqueue << ", length: " << pqueue.size() << endl;
	}

	// LinkedList<int> l;

	// int input[] = {5, 4, 6, 3, 8, 7};

	// for (int v : input) 
	// 	l.push_back(v);



	return EXIT_SUCCESS;
}