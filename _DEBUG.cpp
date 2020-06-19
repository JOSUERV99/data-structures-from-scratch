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

	int input[] = {5, 4, 6, 3, 8, 7};

	for (int v : input) 
		tree.insert(v);

	cout << tree.inOrder() << endl;

	tree.remove(5);
	cout << tree.postOrder() << endl;


	return EXIT_SUCCESS;
}