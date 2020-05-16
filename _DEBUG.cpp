#include "_DS_FromScratch.cpp"

class Object {
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

	BinaryTree<int> tree;

	tree.insert(5);	
	tree.insert(4);	
	tree.insert(6);	
	tree.insert(5);	
	tree.insert(1);	

	cout << tree.size() << endl;

	auto lst = tree.preOrder();
	for ( auto i = lst.begin; i != nullptr; i = i->next )
		std::cout << i->getValue() << ",";

	return EXIT_SUCCESS;
}