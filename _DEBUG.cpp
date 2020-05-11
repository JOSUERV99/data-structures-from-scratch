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

	Stack<Object> stck;

	Object o1(1);
	Object o2(2);
	Object o3(3);
	Object o4(4);
	Object o5(5);

	stck.push(o1);
	stck.push(o2);
	stck.push(o3);
	stck.push(o4);
	stck.push(o5);

	std::cout << stck << std::endl;

	stck.pop();
	stck.pop();
	stck.pop();

	std::cout << stck << std::endl;
	std::cout << stck.top() << std::endl;
	std::cout << stck.base() << std::endl;

	return 0;
}