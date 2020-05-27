template <class T>
class AVLNode {
public:
	// primitive values
	int bf;
	T value;
	AVLNode<T> *left, *right, *parent;

	// builders
	AVLNode(T value): value(value), right(nullptr), left(nullptr), parent(nullptr), bf(0) {}

	// methods
	T val() { return this->value; }
};
