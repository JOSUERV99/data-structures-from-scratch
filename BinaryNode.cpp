template <class T>
class BinaryNode {
public:
	// primitive values
	T value;
	BinaryNode<T> *right, *left;
	
	// builders
	BinaryNode(T value): value(value), right(nullptr), left(nullptr) {}

	// methods
	T getValue() { return this->value; }
};
