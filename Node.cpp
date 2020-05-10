template <class T>
class Node {
private:
	// primitive values
	T value;
	Node *next;

public:
	// builders
	Node(T value): value(value), next(nullptr) {}
	Node(T value, Node *next): value(value), next(next) {}

	// methods
	T getValue() { return this->value; }
	Node *getNext() { return this->next; }
	void link(Node *node) { this->next = node; }
};
