// Justin Ventura Lab-8
// COSC320 Joe Anderson

#include <iostream>
#include "BST.h"

int main() {

	BST tree;
	std::cout << "Adding 5 elements in this order: 3 5 4 1 2.\n";
	tree.insertion(3);
	tree.insertion(5);
	tree.insertion(4);
	tree.insertion(1);
	tree.insertion(2);

	std::cout << "Should preorder (NLR) print: 3 1 2 5 4 -> ";
	tree.preOrder();
	std::cout << "Should inorder (LNR) print: 1 2 3 4 5 -> ";
	tree.inOrder();

	std::cout << "Check the tree for 7 and 5.\n";
	tree.search(7);
	if (tree.search(5)) {

		std::cout << "key 5 found!\n";

	}
	else {

		std::cout << "key 5 not found.\n";

	}

	std::cout << "Minimum of tree is : " << tree.minimum() << "\n";
	std::cout << "Maximum of tree is : " << tree.maximum() << "\n";

	std::cout << "Inserting 0, 6.\n";
	tree.insertion(0);
	tree.insertion(6);

	std::cout << "Should preorder (NLR) print: 3 1 0 2 5 4 6 -> ";
	tree.preOrder();
	std::cout << "Should inorder (LNR) print: 0 1 2 3 4 5 6 -> ";
	tree.inOrder();

	std::cout << "Successor of 1 is : " << tree.successor(1) << "\n";
	std::cout << "Removing 1.\n";
	tree.removal(1);

	std::cout << "Should preorder (NLR) print: 3 2 0 5 4 6 -> ";
	tree.preOrder();
	std::cout << "Should inorder (LNR) print: 0 2 3 4 5 6 -> ";
	tree.inOrder();

	std::cout << "Removing 5.\n";
	tree.removal(5);

	std::cout << "Should preorder (NLR) print: 3 2 0 4 6 -> ";
	tree.preOrder();
	std::cout << "Should inorder (LNR) print: 0 2 3 4 6 -> ";
	tree.inOrder();


	return 0;
}