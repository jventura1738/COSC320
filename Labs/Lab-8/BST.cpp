// Justin Ventura COSC320 Lab8
// A lot of code is based off my
// 220 lab but I redid anything
// that I was rusty on. Also, I
// improved on the old code for
// a good bit and filled in any
// gaps.

#include "BST.h"

BST::BST() {
	this->root = nullptr;
}
BST::BST(const BST & oldtree) {
	this->root = nullptr;
	subtreeCopy(oldtree.root);
}
BST::~BST() {
	subtreeRemoval(this->root);
}
BST & BST::operator=(const BST & oldtree) {
	subtreeRemoval(this->root);
	this->root = nullptr;
	subtreeCopy(oldtree.root);
	return *this;
}

BST::TreeNode::TreeNode() {
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

// Regular constructor.
BST::TreeNode::TreeNode(const int & val) {
	this->key = val;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

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

	TreeNode * z = new TreeNode(val);
	TreeNode * x = this->root;
	TreeNode * y = nullptr;
	while(x) {

		y = x;
		if (z->key < x->key) {

			x = x->left;

		}
		else {

			x = x->right;

		}

	}
	z->parent = y;
	if (!y) {

		this->root = z;

	}
	else if (z->key < y->key) {

		y->left = z;

	}
	else {

		y->right = z;

	}


}

// Revised removal method.
void BST::removal(const int & val) {

	TreeNode * z = this->_search(val);
	if (!z->left) {

		this->transplant(z, z->right);
		delete z;

	}
	else if (!z->right) {

		transplant(z, z->left);
		delete z;

	}
	else {

		TreeNode * y = z->right;
		while (y->left) {

			y = y->left;

		}
		if(y->parent != z) {

			this->transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;

		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		delete z;

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

// Private recursive inorder print. L N R
void BST::_inOrder(TreeNode * root) {

	if (root) {

		_inOrder(root->left);
		std::cout << root->key << " ";
		_inOrder(root->right);

	}

}

// Transplant method.
void BST::transplant(TreeNode * u, TreeNode * v) {

	if (!u->parent) {

		this->root = v;

	}
	else if (u == u->parent->left) {

		u->parent->left = v;

	}
	else {

		u->parent->right = v;

	}
	if (v) {

		v->parent = u->parent;

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

