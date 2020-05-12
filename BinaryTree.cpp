template <class T>
class BinaryTree {
private:
	int nodesAmount;
	TreeNode<T> *root;

	void _insert(TreeNode<T>*, TreeNode<T>*, TreeNode<T>*);
	void _remove(TreeNode<T>*, TreeNode<T>*, TreeNode<T>*);
	void _preOrder(TreeNode<T>*, LinkedList<T>**);

public:
	BinaryTree(): root(nullptr), nodesAmount(0) {}

	void insert(T value);
	void remove(T value);
	
	LinkedList<T> *preOrder();
	LinkedList<T> inOrder();
	LinkedList<T> postOrder();

	int deep(T value);
	bool contains(T value);
};

template <class T>
void BinaryTree<T>::insert(T value) {	
	_insert(root, nullptr, new TreeNode<T>(value));
}

template <class T>
void BinaryTree<T>::_insert(TreeNode<T>* root, TreeNode<T>* parent, TreeNode<T>* value) {	

	if (!root) {
		root = value;
		root->parent = parent;
		nodesAmount++;
		return;
	}

	if (root->getValue() < value->getValue()) 
		_insert( root->right, root, value );
	else 
		_insert( root->left, root, value );
}

template <class T>
LinkedList<T> *BinaryTree<T>::preOrder() {
	LinkedList<T> *list = new LinkedList<T>();
	_preOrder(root, &list);
	return list;
}

template <class T>
void BinaryTree<T>::_preOrder(TreeNode<T>* root, LinkedList<T> **list) {
	if (!root) {
		return;
	} else {
		_preOrder(root->left, list);
		(*list)->push_back(root->getValue());
		_preOrder(root->right, list);
		std::cout << (*list)->size();
	}
}