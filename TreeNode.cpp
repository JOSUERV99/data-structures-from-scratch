template <class T>
class TreeNode {
public:
	// primitive values
	T value;
	int bf = 0;
	TreeNode<T> *right, *left, *parent;
	
	// builders
	TreeNode(T value): value(value), right(nullptr), left(nullptr), parent(nullptr) {}

	// methods
	T getValue() { return this->value; }


	//overwriting operators
	friend ostream& operator << (ostream &o,const TreeNode<T> &p) {
    	o << p.getValue() << ", ";
    	return o;
	}
};
