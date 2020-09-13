#define __BT__

#ifndef __TN__
	#include "../nodes/TreeNode.h"
#endif

#ifndef __LL__
	#include"../canonical/LinkedList.h"
#endif

template <class T>
class BinaryTree {
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