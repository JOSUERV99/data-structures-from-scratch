template <class T>
class AVLTree : public BinaryTree<T> {
private:
	// attributes
	int nodesAmount;

	// recursive functions
	bool _insert(AVLNode<T>*& root, AVLNode<T>* parent, AVLNode<T>* value);
	bool _remove(AVLNode<T>*& root, T value);
	void _refreshBalance(AVLNode<T>*&);
	int  _height(AVLNode<T> *tree);
	bool _update(AVLNode<T>*& root);

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
		node->bf = _height(node->right) - _height(node->left) ;
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
		list.push_back(root->val());
		list.push_back(root->bf);
		_inOrder(root->right, list);
	}
}

template<class T> 
void AVLTree<T>::rightRotate(AVLNode<T>*& node) {

	auto* oldRoot = node;
	auto* newRoot = node->left;

	oldRoot->left = newRoot->right;
	newRoot->right = oldRoot;
	node = newRoot;	 

	node->bf = 0;
   oldRoot->bf = 0;                                 
}

template<class T> 
void AVLTree<T>::leftRotate(AVLNode<T>*& node) {

	auto* oldRoot = node;
	auto* newRoot = node->right;

	oldRoot->right = newRoot->left;
	newRoot->left = oldRoot;
	node = newRoot;	   
   
   node->bf = 0;
   oldRoot->bf = 0;                          
}

template<class T>
int AVLTree<T>::_height(AVLNode<T>* tree) {
	return tree ? 1 + _height(tree->left) + _height(tree->right): 0;
}

template <class T>
bool AVLTree<T>::_update(AVLNode<T>*& root) {

	if (root->bf == 2) {

		if (root->right->bf < 0) {

			rightRotate( root->right );
			leftRotate(  root );
			
		} else {

			leftRotate(  root );
		}

		return false;

	} else  if (root->bf == -2) {

		if (root->left->bf < 0) {

			leftRotate( root->left );
			rightRotate(  root );
		
		} else {

			rightRotate( root );
		}

		return false;

	} 

	return true;
}

template <class T>
bool AVLTree<T>::_insert(AVLNode<T>*& root, AVLNode<T>* parent, AVLNode<T>* newNode) {

	if (!root)  {
		root = newNode;
		root->parent = parent;
		root->bf = 0;
		nodesAmount++;
		return true;
	}

	if (root->val() < newNode->val()) {
		if ( _insert(root->right, root, newNode) )
			root->bf++;
	} 
	else {
		if ( _insert(root->left, root, newNode) )
			root->bf--;
	}

	return _update(root);

}

template<class T>
bool AVLTree<T>::_remove(AVLNode<T>* &node, T value) {

	bool finded = false;

	if (node) {

		if (node->val() > value) {

			finded = _remove(root->left, value);
			if (finded)	node->bf--;

		}
		else if (node->val() < value) {

			finded = _remove(node->right, value);
			if (finded)	node->bf--;

		}
		else {

			if ( !node->left || !node->right ) {
				auto *aux = node;
				node = node->left ? node->left : node->right;
				delete aux;
			}
			else {

				// auto *maxValueAtLeft = nullptr;
				// TODO: check some cases with both childs


			}

			finded = true;
		}

		_refreshBalance(root);

		_update(root);
	}

	return finded;
}

template <class T>
void AVLTree<T>::insert(T value) {
	auto *node = new AVLNode<T>(value);
	_insert(root, nullptr, node);
}


template<class T>
void AVLTree<T>::remove(T value) {
	_remove(root, value);
}


