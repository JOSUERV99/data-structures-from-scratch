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
	tree.insert(4);	
	tree.insert(6);	
	tree.insert(5);	
	tree.insert(1);

	cout << "Size: " << tree.size() << endl;

	cout << 9 << " " << tree.search(9) << endl;
	cout << 1 << " " << tree.search(1) << endl;

	cout << "PreOrden: " << tree.preOrder() << endl;
	cout << "PostOrden: " << tree.postOrder() << endl;
	cout << "InOrden: "  << tree.inOrder() << endl;

	return EXIT_SUCCESS;
}