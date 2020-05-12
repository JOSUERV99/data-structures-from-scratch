#include "_DS_FromScratch.cpp"

class Object {
public:
	int val;
	Object() : val(0) {}
	Object(int value) : val(value) {}

	//overwriting operators
	friend ostream& operator << (ostream &o,const Object &p) {
    	o << p.val;
		return o;
	}
};

int main() {

	Queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	while(!queue.isEmpty()) {
		std::cout << "Size: " << queue.size() << " -> "<< queue.base() << std::endl;
		queue.pop();
	}

	std::cout << queue.size() << std::endl;

	return 0;
}