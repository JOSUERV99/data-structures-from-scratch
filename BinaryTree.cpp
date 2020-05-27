template <class T>
class BinaryTree {
private:
	// main components
	TreeNode<T> *root;
	int nodesAmount;

	// recursive functions
	void _insert   (TreeNode<T>*& root, TreeNode<T>* parent, TreeNode<T>* value);
	void _preOrder (TreeNode<T>*& root, LinkedList<T>& collection);
	void _postOrder(TreeNode<T>*& root, LinkedList<T>& collection);
	void _inOrder  (TreeNode<T>*& root, LinkedList<T>& collection);
	void _remove   (TreeNode<T>*& root, T value);
	bool _search   (TreeNode<T>*& root, T value);

	// auxiliar functions
	TreeNode<T>* _changeRoot_Right(TreeNode<T>*& node);
	TreeNode<T>* _changeRoot_Left(TreeNode<T>*& node);

public:
	// builders
	BinaryTree(): root(nullptr), nodesAmount(0) {}

	// main functions
	void insert  (T value);
	void remove  (T value);
	bool search  (T value);
	bool contains(T value);

	// utils
	LinkedList<T>  preOrder();
	LinkedList<T>   inOrder();
	LinkedList<T> postOrder();

	int deep(T value);
	int size();
};

template <class T>
int BinaryTree<T>::size() {	
	return nodesAmount;
}

template <class T>
void BinaryTree<T>::remove(T value) {
	_remove(this->root, value);
}

template <class T>
TreeNode<T>* BinaryTree<T>::_changeRoot_Right(TreeNode<T>*& node) {
	auto *iter = node->right;

	while (iter->left) iter = iter->left;

	if (iter == node->right) {
		iter->left = node->left;
	} 
	else {
		iter->parent->left = iter->right;
		iter->right = node->right;
		iter->left = node->left;
	}

	return iter;
}

template <class T>
TreeNode<T>* BinaryTree<T>::_changeRoot_Left(TreeNode<T>*& node) {
	auto *iter = node->left;

	while (iter->right) iter = iter->right;

	if (iter == node->left) {
		iter->right = node->right;
	} 
	else {
		iter->parent->right = iter->left;
		iter->left = node->left;
		iter->right = node->right;
	}
	return iter;
}

template <class T>
void BinaryTree<T>::_remove(TreeNode<T>* &node, T value) {
	
	if (!node) {
		return;
	}

	if (node->val() == value) {
		TreeNode<T> *iter = nullptr;

		if (node->left || node->right) {
			if (node->right) 
				iter = _changeRoot_Right(node);
			 else 
				iter = _changeRoot_Left(node);
		} 

		delete node;
		node = iter;
		nodesAmount--;
		return;
	}

	if (node->val() < value) {
		_remove( node->right, value );
	} else {
		_remove( node->left,  value );
	}
}

template <class T>
bool BinaryTree<T>::search(T value) {	
	return _search(this->root, value);
}

template <class T>
bool BinaryTree<T>::_search(TreeNode<T>*& node, T value) {	
	if (!node) 
		return false;
	if (node->val() == value)
		return true;
	if ( node->val() > value ) 
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

	if ( node->val() > value->val() ) 
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
		list.push_back(root->val());
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
		list.push_back(root->val());
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
		list.push_back(root->val());
		_inOrder(root->right, list);
	}
}