#define __AVLT__

#ifndef __AVLN__
	#include"../nodes/AVLNode.h"
#endif

#ifndef __BT__
	#include"BinaryTree.h"
#endif 

template <class T>
class AVLTree : public BinaryTree<T> {
	// attributes
	int nodesAmount;

	// recursive functions
	bool _insert(AVLNode<T>*& root, AVLNode<T>* parent, AVLNode<T>* value);
	bool _remove(AVLNode<T>*& root, T value);
	void _refreshBalance(AVLNode<T>*& node);
	int  _height(AVLNode<T> *tree);
	bool _update(AVLNode<T>*& root);

	// auxiliary functions
	void leftRotate (AVLNode<T>*& node);
	void rightRotate(AVLNode<T>*& node);

	AVLNode<T> *getMaxValueAtLeft(AVLNode<T>* root);

	// visualize functions
	void   _inOrder(AVLNode<T>* &root, LinkedList<T> &list);
	void _postOrder(AVLNode<T>* &root, LinkedList<T> &list);
	void  _preOrder(AVLNode<T>* &root, LinkedList<T> &list);

	// testing
	AVLNode<T> *root; //////////////////////

	// builders
	AVLTree(): nodesAmount(0), root(nullptr) {}

	// main functions
	void remove(T value);
	void insert(T value);

	int size() {
		return nodesAmount;
	}

	LinkedList<T> inOrder();
	LinkedList<T> preOrder();
	LinkedList<T> postOrder();
};