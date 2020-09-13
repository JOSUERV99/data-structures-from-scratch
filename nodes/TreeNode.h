#define __TN__

template <class T>
class TreeNode {
public:
	// primitive values
	T value;
	TreeNode<T> *right, *left, *parent;
	
	// builders
	TreeNode(T value): value(value), right(nullptr), left(nullptr), parent(nullptr) {}

	// methods
	T val() { return this->value; }


	//overwriting operators
	friend ostream& operator << (ostream &o,const TreeNode<T> &p) {
    	o << p.val() << ", ";
    	return o;
	}
};
