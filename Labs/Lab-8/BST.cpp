// Justin Ventura COSC320 Lab8
// A lot of code is based off my
// 220 lab but I redid anything
// that I was rusty on. Also, I
// improved on the old code for
// a good bit and filled in any
// gaps.

#include "BST.h"

// Recursive deletion. L R N
void BST::subtreeRemoval(TreeNode * root) {

	if (root) {

		subtreeRemoval(root->left);
		subtreeRemoval(root->right);
		delete root;

	}

}

// Recursive copy. N L R
void BST::subtreeCopy(TreeNode * head) {

	if (root) {

		insertion(root->key);
		subtreeCopy(root->left);
		subtreeCopy(root->right);

	}

}

// Revised inserion method.
void BST::insertion(const int & val) {

	TreeNode * newnode = new TreeNode(val);

	TreeNode * cursor = this->root;
	TreeNode * prev = nullptr;

	while (cursor) {

		prev = cursor;

		if (newnode->key < cursor->key) {

			cursor = cursor->left;

		} 
		else {

			cursor = cursor->right;

		}

	}

	if (!prev) {

		this->root = newnode;
		return;

	}
	else if (newnode->key < prev->key) {

		prev->left = newnode;

	} 
	else {

		prev->right = newnode;

	}

	newnode->parent = prev;

}

// Revised removal method.
void BST::removal(const int & val) {

	TreeNode * target = _search(val);
	if (!target) {

		throw std::string("Node with given key not found.\n");

	}
	else if (!target->left) {

		transplant(target, target->right);
		delete target;

	} 
	else if (!target->right) {

		transplant(target, target->left);
		delete target;

	} 
	else {

		TreeNode * cursor = target->right;

		while (cursor->left) {

			cursor = cursor->left;

		}

		TreeNode * insert = cursor;

		if (insert != target->right) {

			transplant(insert, insert->right);
			insert->right = target->right;
			insert->right->parent = insert;

		}

		transplant(target, insert);
		insert->left = target->left;
		insert->left->parent = insert;
		delete target;

	}

}

// Revised public search method.
bool BST::search(const int & key) {

	TreeNode * target = _search(key);

	if (!target) {

		std::cout << "Error in BST::search-> node with given key [" << key << "] not in tree.\n";
		return false;

	}

	return true;

}

// Private search.
BST::TreeNode * BST::_search(const int & key) {

	TreeNode * cursor = this->root;
	while (cursor) {

		if (cursor->key == key) {

			return cursor;

		} 
		else if (cursor->key > key) {

			cursor = cursor->left;

		} 
		else {

			cursor = cursor->right;

		}

	}

	// Return nothing if its not found.
	// Public method will throw this error.
	return nullptr;

}

// Minimum of the tree.  Go left.
int BST::minimum() {

	TreeNode * cursor = this->root;
	if (!cursor) {

		throw std::string("Tree is empty dummy boi.\n");

	}

	while (cursor->left) {

		cursor = cursor->left;

	}

	return cursor->key;

}

// Maximum of the tree. Go right.
int BST::maximum() {

	TreeNode * cursor = this->root;
	if (!cursor) {

		throw std::string("Tree is empty dummy boi.\n");

	}

	while (cursor->right) {

		cursor = cursor->right;

	}

	return cursor->key;

}

// Return the successor of the node with given key.
int BST::successor(const int & key) {

	TreeNode * given = _search(key);
	TreeNode * cursor = given;
	TreeNode * original = given;

	if(!given) {

		throw std::string("Node with given key DNE.\n");

	}
	else if (!given->right) {

		while (cursor->parent) {

			if (cursor->parent->left == cursor) {

				return cursor->parent->key;

			}

			cursor = cursor->parent;

		}

		return original->key;

	}

	cursor = given->right;
	while (cursor->left) {

		cursor = cursor->left;

	}

	return cursor->key;

}


// Public recursive inorder print. L N R
void BST::inOrder() {

	_inOrder(root);
	std::cout << "\n";

}

// Private recursive inorder print.
void BST::_inOrder(TreeNode * root) {

	if (root) {

		_preOrder(root->left);
		std::cout << root->key << " ";
		_preOrder(root->right);

	}

}

// Transplant method.
void BST::transplant(TreeNode * oldnode, TreeNode * newnode) {

	if (oldnode == this->root && !oldnode->parent) {

		root = newnode;

	} 
	else if (oldnode->parent->right == oldnode) {

		oldnode->parent->right = newnode;

	} 
	else {

		oldnode->parent->left = newnode;

	}
	if (newnode) {

		newnode->parent = oldnode->parent;

	}

}

// Public recursive preorder print (for clarity). N L R
void BST::preOrder() {

	_preOrder(root);
	std::cout << "\n";

}

// Private recursive preorder print.
void BST::_preOrder(TreeNode * root) {

	if (root) {

		std::cout << root->key << " ";
		_preOrder(root->left);
		_preOrder(root->right);

	}

}

