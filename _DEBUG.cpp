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

	AVLTree<int> tree;


	tree.insert(1);
	tree.insert(2);
	tree.insert(3);


	cout << tree.inOrder() << endl;

	tree.rotateLeft(tree.root);

	cout << tree.inOrder() << endl;


	return EXIT_SUCCESS;
}