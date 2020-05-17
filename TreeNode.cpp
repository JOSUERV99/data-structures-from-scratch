template <class T>
class TreeNode {
public:
	// primitive values
	T value;
	TreeNode<T> *right, *left, *parent;
	
	// builders
	TreeNode(T value): value(value), right(nullptr), left(nullptr), parent(nullptr) {}
		
	// // destructor
	// ~TreeNode() {
	// 	delete right;
	// 	delete left;
	// 	delete parent;
	// }

	// methods
	T getValue() { return this->value; }


	//overwriting operators
	friend ostream& operator << (ostream &o,const TreeNode<T> &p) {
    	o << p.getValue() << ", ";
    	return o;
	}
};
