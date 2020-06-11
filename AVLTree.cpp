template <class T>
class AVLTree : public BinaryTree<T> {
private:
	// attributes
	int nodesAmount;

	// recursive functions
	void _insert(AVLNode<T>*& root, AVLNode<T>* parent, AVLNode<T>* value);
	void _remove(AVLNode<T>*& root, T value);
	void _refreshBalance(AVLNode<T>*&);
	int  _height(AVLNode<T> *tree);

public:
	// testing
	AVLNode<T> *root; //////////////////////

	// builders
	AVLTree(): nodesAmount(0), root(nullptr) {}

	// main functions
	void remove(T value);
	void insert(T value);
	int size();

	void _inOrder(AVLNode<T>* &root, LinkedList<T> &list);
	LinkedList<T> inOrder();
	
	void leftRotate (AVLNode<T>*& node);
	void rightRotate(AVLNode<T>*& node);

	AVLNode<T> *rotateRight(AVLNode<T>* node);

};

template<class T>
void AVLTree<T>::_refreshBalance(AVLNode<T>* &node) {
	if (node) {
		_refreshBalance(node->left);
		_refreshBalance(node->right);
		node->bf = _height(node->left) - _height(node->right);
	}
}

template<class T>
int AVLTree<T>::size() {
	return nodesAmount;
}

template <class T>
LinkedList<T> AVLTree<T>::inOrder() {
	LinkedList<T> list;
	_inOrder(root, list);
	return list;
}

template <class T>
void AVLTree<T>::_inOrder(AVLNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		_inOrder(root->left, list);
		list.push_back(root->bf);
		list.push_back(root->val());
		_inOrder(root->right, list);
	}
}

template<class T> 
void AVLTree<T>::rightRotate(AVLNode<T>*& node) {

	AVLNode<T>* oldRoot = node;
	AVLNode<T>* newRoot = node->left;

	oldRoot->left = newRoot->right;
	newRoot->right = oldRoot;
	node = newRoot;	 

	// TODO: check this
	oldRoot->bf++;
	newRoot->bf--;

	_refreshBalance(node);                                   
}

template<class T> 
void AVLTree<T>::leftRotate(AVLNode<T>*& node) {

	AVLNode<T>* oldRoot = node;
	AVLNode<T>* newRoot = node->right;

	oldRoot->right = newRoot->left;
	newRoot->left = oldRoot;
	node = newRoot;	   

	// TODO: check this
	oldRoot->bf--;
	newRoot->bf++;

	_refreshBalance(node);                                   
}

template<class T>
int AVLTree<T>::_height(AVLNode<T>* tree) {
	return tree ? 1 + _height(tree->left) + _height(tree->right): 0;
}

template <class T>
void AVLTree<T>::_insert(AVLNode<T>*& root, AVLNode<T>* parent, AVLNode<T>* newNode) {

	if (!root)  {
		root = newNode;
		root->parent = parent;
		root->bf = 0;
		nodesAmount++;
		return;
	}

	if (root->val() < newNode->val()) {
		_insert(root->right, root, newNode);
		root->bf++;
	} 
	else {
		_insert(root->left, root, newNode);
		root->bf--;
	}

	if (root->bf == 2) {

		if (root->right->bf == -1) {

			rightRotate( root->right );
			leftRotate(  root );

		} else {

			leftRotate(  root );
		}

	} else  if (root->bf == -2) {

		if (root->left->bf == -1) {

			leftRotate( root->left );
			rightRotate(  root );

		} else {

			rightRotate( root );
		}

	}
}

template <class T>
void AVLTree<T>::insert(T value) {
	AVLNode<T> *node = new AVLNode<T>(value);
	_insert(root, nullptr, node);
}

template<class T>
void AVLTree<T>::_remove(AVLNode<T>* &node, T value) {

}

template<class T>
void AVLTree<T>::remove(T value) {
	_remove(root, value);
}


