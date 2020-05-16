template <class T>
class BinaryTree {
private:
	
	int nodesAmount;
	TreeNode<T> *root;

	void _insert(TreeNode<T>*&, TreeNode<T>*, TreeNode<T>*);
	void _remove(TreeNode<T>*, TreeNode<T>*, TreeNode<T>*);
	void _preOrder(TreeNode<T>*&, LinkedList<T>&);
	void _postOrder(TreeNode<T>*&, LinkedList<T>&);
	void _inOrder(TreeNode<T>*&, LinkedList<T>&);
	bool _search(TreeNode<T>*&, T);

public:

	BinaryTree(): root(nullptr), nodesAmount(0) {}

	void insert(T value);
	void remove(T value);
	
	LinkedList<T> preOrder();
	LinkedList<T> inOrder();
	LinkedList<T> postOrder();
	bool search(T);

	int deep(T value);
	int size();
	bool contains(T value);
};

template <class T>
int BinaryTree<T>::size() {	
	return nodesAmount;
}

template <class T>
bool BinaryTree<T>::search(T value) {	
	return _search(this->root, value);
}

template <class T>
bool BinaryTree<T>::_search(TreeNode<T>*& node, T value) {	
	if (!node) 
		return false;
	if (node->getValue() == value)
		return true;
	if ( node->getValue() > value ) 
		return _search( node->left, value );
	else 
		return _search( node->right, value );
}

template <class T>
void BinaryTree<T>::insert(T value) {	
	TreeNode<T> *node = new TreeNode<T>(value);
	_insert(this->root, nullptr, node);
}

template <class T>
void BinaryTree<T>::_insert(TreeNode<T>*& node, TreeNode<T>* parent, TreeNode<T>* value) {	

	if (!node) {
		node = value;
		node->parent = parent;
		nodesAmount++;
		return;
	}

	if ( node->getValue() > value->getValue() ) 
		_insert( node->left, node, value );
	else 
		_insert( node->right, node, value );
}

template <class T>
LinkedList<T> BinaryTree<T>::preOrder() {
	LinkedList<T> list;
	_preOrder(root, list);
	return list;
}

template <class T>
void BinaryTree<T>::_preOrder(TreeNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		list.push_back(root->getValue());
		_preOrder(root->left, list);
		_preOrder(root->right, list);
	}
}

template <class T>
LinkedList<T> BinaryTree<T>::postOrder() {
	LinkedList<T> list;
	_postOrder(root, list);
	return list;
}

template <class T>
void BinaryTree<T>::_postOrder(TreeNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		_postOrder(root->left, list);
		_postOrder(root->right, list);
		list.push_back(root->getValue());
	}
}

template <class T>
LinkedList<T> BinaryTree<T>::inOrder() {
	LinkedList<T> list;
	_inOrder(root, list);
	return list;
}

template <class T>
void BinaryTree<T>::_inOrder(TreeNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		_inOrder(root->left, list);
		list.push_back(root->getValue());
		_inOrder(root->right, list);
	}
}