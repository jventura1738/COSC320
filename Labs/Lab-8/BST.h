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
#include<stdio.h>

class BST {

private:
	struct TreeNode {
		int key;
		TreeNode * left;
		TreeNode * right;
		TreeNode * parent;

		// Default constuctor.
		TreeNode() {
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}

		// Regular constructor.
		TreeNode(const int & val) {
			this->key = val;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}
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
	BST() {
		this->root = nullptr;
	}
	BST(const BST & oldtree) {
		this->root = nullptr;
		subtreeCopy(oldtree.root);
	}
	~BST() {
		subtreeRemoval(this->root);
	}
	BST & operator=(const BST & oldtree) {
		subtreeRemoval(this->root);
		this->root = nullptr;
		subtreeCopy(oldtree.root);
		return *this;
	}

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
