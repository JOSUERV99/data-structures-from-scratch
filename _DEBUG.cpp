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

	auto lst = tree.preOrder();
	for ( auto i = lst->begin; i != lst->end; i = i->next )
		std::cout << i->getValue() << (i->next != lst->end ? "," : " " );

	return EXIT_SUCCESS;
}