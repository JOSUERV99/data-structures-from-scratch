#ifndef __AVLT__
	#include"AVLTree.h"
#endif 

#ifndef __LL__
	#include"../canonical/LinkedList.h"
#endif

#ifndef __AVLN__
	#include"../nodes/AVLNode.h"
#endif

template <class T>
LinkedList<T> AVLTree<T>::inOrder() {
	LinkedList<T> list;
	_inOrder(root, list);
	return list;
}

template <class T>
LinkedList<T> AVLTree<T>::preOrder() {
	LinkedList<T> list;
	_preOrder(root, list);
	return list;
}

template <class T>
void AVLTree<T>::_preOrder(AVLNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		list.push_back(root->val());
		_preOrder(root->left, list);
		_preOrder(root->right, list);
	}
}

template <class T>
LinkedList<T> AVLTree<T>::postOrder() {
	LinkedList<T> list;
	_postOrder(root, list);
	return list;
}

template <class T>
void AVLTree<T>::_postOrder(AVLNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		_postOrder(root->left, list);
		_postOrder(root->right, list);
		list.push_back(root->val());
	}
}

template<class T>
void AVLTree<T>::_refreshBalance(AVLNode<T>* &node) {
	if (node) {
		
		_refreshBalance(node->left);
		_refreshBalance(node->right);

		node->bf = _height(node->right) - _height(node->left)  ;
	}
}

template <class T>
void AVLTree<T>::_inOrder(AVLNode<T>*&root, LinkedList<T> &list) {
	if (!root) {
		return;
	} else {
		_inOrder(root->left, list);
		list.push_back(root->val());
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

	node->bf = oldRoot->bf = 0;                                 
}

template<class T> 
void AVLTree<T>::leftRotate(AVLNode<T>*& node) {

	auto* oldRoot = node;
	auto* newRoot = node->right;

	oldRoot->right = newRoot->left;
	newRoot->left = oldRoot;
	node = newRoot;	   
   
   node->bf = oldRoot->bf = 0;                          
}

template<class T>
int AVLTree<T>::_height(AVLNode<T>* tree) {
	return tree ? 1 + ( _height(tree->left) | _height(tree->right) ): 0;
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
		
		auto *current = node->val() > value ? root->left : node->val() == value ? nullptr : root->right;

		if (!current) {
			finded = _remove(current, value);
			if (finded)	
				node->bf--;

		} else {

			AVLNode<T> *aux = nullptr;

			if ( !node->left || !node->right ) {

				aux = node;
				node = node->left ? node->left : node->right;
				delete aux;
			}
			else {

				auto *maxValueAtLeft = getMaxValueAtLeft(node);

				aux = node;

				maxValueAtLeft->left = maxValueAtLeft != node->left ? node->left : maxValueAtLeft->left;
				maxValueAtLeft->right = node->right;
				node = maxValueAtLeft;

				_refreshBalance( node );

				delete aux;
				nodesAmount--;
			}

			finded = true;
		}
	}

	return finded;
}

template <class T>
AVLNode<T> *AVLTree<T>::getMaxValueAtLeft(AVLNode<T>* root) {

	auto *iter = root->left;

	while (iter->right)
		iter = iter->right;

	return iter;
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


