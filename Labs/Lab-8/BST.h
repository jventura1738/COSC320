// Justin Ventura COSC320 Lab8
// A lot of code is based off my
// 220 lab but I redid anything
// that I was rusty on. Also, I
// improved on the old code for
// a good bit and filled in any
// gaps.

#ifndef BST_H
#define BST_H

#include<iostream>

class BST {

private:
	struct TreeNode {
		int key;
		TreeNode * left;
		TreeNode * right;
		TreeNode * parent;

		// Default constuctor.
		TreeNode();

		// Regular constructor.
		TreeNode(const int & val);
	};
	TreeNode * root;

	// Private utilization tools.
	void subtreeRemoval(TreeNode * root);
	void subtreeCopy(TreeNode * root);
	TreeNode * _search(const int & val);
	void transplant(TreeNode * oldnode, TreeNode * newnode);
	void _inOrder(TreeNode * node);
	void _preOrder(TreeNode * node);

public:

	/*
	 * CONSTRUCTORS ETC
	*/
	BST();
	BST(const BST & oldtree);
	~BST();
	BST & operator=(const BST & oldtree);

	/*
	 * EVERYTHING ELSE LOL
	*/

	// Insertion & deletion.
	void insertion(const int & val);
	void removal(const int & val);

	// Accesseries.
	bool search(const int & val);
	int minimum();
	int maximum();
	int successor(const int & val);
	void inOrder();
	void preOrder();

};

#endif
