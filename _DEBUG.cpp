#include "_DS_FromScratch.cpp"

class Object {
	int val;
	Object() : val(0) {}
	Object(int value) : val(value) {}

	//overwriting operators
	friend ostream& operator << (ostream &o,const Object &p) {
    	o << "[" << p.val << "]";
		return o;
	}
};

int main() {

	BinaryTree<int> tree;

	tree.insert(5);
	tree.insert(1);
	tree.insert(7);
	tree.insert(9);
	tree.insert(6);
	tree.insert(2);
	tree.insert(0);

	cout << "InOrden: "  << tree.inOrder() << endl;
	
	tree.remove(7);
	
	cout << "InOrden: "  << tree.inOrder() << endl;

	return EXIT_SUCCESS;
}