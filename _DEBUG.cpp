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

	int input[] = {5, 4, 6, 8};

	for (int v : input) {
		tree.insert(v);
	}

	cout << tree.inOrder() << endl;

	tree.insert(9);

	cout << tree.inOrder() << endl;


	return EXIT_SUCCESS;
}