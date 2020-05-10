template <class T>
class Node {
public:
	// primitive values
	T value;
	Node *next;
	
	// builders
	Node(T value): value(value), next(nullptr) {}
	Node(T value, Node *next): value(value), next(next) {}

	// methods
	T getValue() { return this->value; }
	void link(Node *node) { this->next = node; }
};
