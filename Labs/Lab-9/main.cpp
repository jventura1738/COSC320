// Justin Ventura COSC320
// Lab-9: main.cpp

#include <stdio.h>
#include <iostream>

enum color_t {

  RED, BLACK

};

class RBTree {

private:

  struct TreeNode {

    int key;
    color_t color;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

  };

  static TreeNode* const nil;

  TreeNode * root;

  void _printInOrder(TreeNode * u) {

    if( u != nil ) {

      _printInOrder(u->left);
      printf(" %d", u->key);
      _printInOrder(u->right);

    }

  }

  // Private recursive preorder print.
  void _preOrder(TreeNode * root) {

    if (root != nil) {

      std::cout << root->key << " ";
      _preOrder(root->left);
      _preOrder(root->right);

    }

  }

  TreeNode * _search(const int & key) const {

    TreeNode * cursor = this->root;
    while (cursor != nil) {

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
    return nil;

  }

  // Transplant method.
  void transplant(TreeNode * u, TreeNode * v) {

    if (u->parent == nil) {

      this->root = v;

    }
    else if (u == u->parent->left) {

      u->parent->left = v;

    }
    else {

      u->parent->right = v;

    }
    if (v != nil) {

      v->parent = u->parent;

    }

  }

  // Pretty much from the lecture and text.
  void FixUp(TreeNode * z) {

    while (z->parent->color == RED) {

      if (z->parent == z->parent->parent->left) {

        TreeNode * y = z->parent->parent->right;

        if (y->color == RED) {

          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;

        } 
        else {

          if (z == z->parent->right) {

            z = z->parent;
            LeftRotate(z);

          }

          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          RightRotate(z->parent->parent);

        }
      } 
      else {

        TreeNode * y = z->parent->parent->left;

        if (y->color == RED) {

          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;

        } 
        else { 

          if (z == z->parent->left) {

            z = z->parent;
            RightRotate(z);

          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          LeftRotate(z->parent->parent);

        }

      }

    }

    this->root->color = BLACK;

  }

  void FixUpD(TreeNode * x) {

    while (x != this->root && x->color == BLACK) {

      if (x == x->parent->left) {

        TreeNode * w = x->parent->right;

        if (w->color == RED) {

          w->color = BLACK;
          x->parent->color = RED;
          LeftRotate(x->parent);
          w = x->parent->right;

        }
        if (w->left->color == BLACK && w->right->color == BLACK) {

          w->color = RED;
          x = x->parent;

        } 
        else {

          if (w->right->color == BLACK) {

            w->left->color = BLACK;
            w->color = RED;
            RightRotate(w);
            w = x->parent->right;

          }

          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->right->color = BLACK;
          LeftRotate(x->parent);
          x = root;

        }

      } 
      else {

        TreeNode * w = x->parent->left;
        if (w->color == RED) {

          w->color = BLACK;
          x->parent->color = RED;
          RightRotate(x->parent);
          w = x->parent->left;

        }
        if (w->right->color == BLACK && w->left->color == BLACK) {

          w->color = RED;
          x = x->parent;

        } 
        else {

          if (w->left->color == BLACK) {

            w->right->color = BLACK;
            w->color = RED;
            LeftRotate(w);
            w = x->parent->left;

          }

          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->left->color = BLACK;
          RightRotate(x->parent);
          x = root;

        }

      }

    }

    x->color = BLACK;

  }

  void LeftRotate(TreeNode * x) {

    TreeNode * y = x->right;
    x->right = y->left;
    if (y->left != nil) {

      y->left->parent = x;

    }
    y->parent = x->parent;

    if (x->parent == nil) {

      root = y;

    } 
    else if (x == x->parent->left) {

      x->parent->left = y;

    } 
    else {

      x->parent->right = y;

    }
    y->left = x;
    x->parent = y;

  }

  void RightRotate(TreeNode * x) {

    TreeNode* y = x->left;
    x->left = y->right;

    if (y->right != nil) {

      y->right->parent = x;

    }
    y->parent = x->parent;

    if (x->parent == nil) {

      root = y;

    } 
    else if (x == x->parent->right) {

      x->parent->right = y;

    } 
    else {

      x->parent->left = y;

    }
    y->right = x;
    x->parent = y;

  }

public:
  /* Fill in with methods */

  // Constructor.
  RBTree() {

    this->root = nil;

  }

  // Copy boi.
  RBTree(const RBTree & oldtree) {

    delete nil;
    this->root = nil;
    subtreeCopy(oldtree.root);

  }

  // Recursive copy. N L R
  void subtreeCopy(TreeNode * root) {

    if (root != nil) {

      insertion(root->key);
      subtreeCopy(root->left);
      subtreeCopy(root->right);

    }

  }

  // AO Overload.
  RBTree & operator=(const RBTree & oldtree) {

    subtreeRemoval(this->root);
    this->root = nullptr;
    subtreeCopy(oldtree.root);
    return *this;
    
  }

  // Destructor.
  ~RBTree() {

    subtreeRemoval(this->root);

  }

  // Recursive deletion. L R N
  void subtreeRemoval(TreeNode * root) {

    if (root != nil) {

      subtreeRemoval(root->left);
      subtreeRemoval(root->right);
      delete root;

    }

  }

  // Print in order.
  void printInOrder() {

    printf("Tree data in order: ");
    _printInOrder(root);
    puts("");

  }

  // Revised public search method.
  bool search(const int & key) {

    TreeNode * target = _search(key);

    if (target == nil) {

      std::cout << "Error in BST::search-> node with given key [" << key << "] not in tree.\n";
      return false;

    }

    return true;

  }

  // Insert function.
  void insertion(int k) {

    TreeNode* newNode = new TreeNode;
    newNode->key = k;

    if (root == nil) {

      printf("Inserting %d into empty tree\n", k);
      root = newNode;
      newNode->parent = nil;

    } 
    else {

      TreeNode* y = nil;
      TreeNode* x = root;

      while(x != nil) {

        y = x;

        if( k < x->key ) {

          x = x->left;

        } 
        else {

          x = x->right;

        }

      }

      if( k < y->key ) {

        printf("Inserting %d on the left of %d\n",k,y->key);
        y->left = newNode;

      } 
      else {

        printf("Inserting %d on the right of %d\n",k,y->key);
        y->right = newNode;

      }

      newNode->parent = y;

    }

    newNode->color = RED;
    newNode->left = nil;
    newNode->right = nil;
    FixUp(newNode);
  }

  // Minimum of the tree.  Go left.
  int minimum() const {

    TreeNode * cursor = this->root;
    if (cursor == nil) {

      throw std::string("Tree is empty dummy boi.\n");

    }

    while (cursor->left != nil) {

      cursor = cursor->left;

    }

    return cursor->key;

  }

  // Maximum of the tree.  Go right.
  int maximum() const {

    TreeNode * cursor = this->root;
    if (cursor == nil) {

      throw std::string("Tree is empty dummy boi.\n");

    }

    while (cursor->right != nil) {

      cursor = cursor->right;

    }

    return cursor->key;

  }

  // Findd successor.
  int successor(int key) const {

    TreeNode * given = _search(key);
    TreeNode * cursor = given;
    TreeNode * original = given;

    if(!given) {

      throw std::string("Node with given key DNE.\n");

    }
    else if (given->right == nil) {

      while (cursor->parent != nil) {

        if (cursor->parent->left == cursor) {

          return cursor->parent->key;

        }

        cursor = cursor->parent;

      }

      return original->key;

    }

    cursor = given->right;
    while (cursor->left != nil) {

      cursor = cursor->left;

    }

    return cursor->key;

  }

  // Revised removal method.
  void removal(const int & val) {

    TreeNode * z = this->_search(val);
    TreeNode * y = z;
    TreeNode * x;
    color_t yOriginalColor = y->color;
    if (z->left == nil) {

      x = z->right;
      this->transplant(z, z->right);
      delete z;

    }
    else if (z->right == nil) {

      x = z->left;
      this->transplant(z, z->left);
      delete z;

    }
    else {

      y = z->right;
      while (y->left) {

        y = y->left;

      }
      yOriginalColor = y->color;
      x = y->right;
      if(y->parent != z) {

        this->transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;

      }
      else {

        x->parent = y;

      }
      this->transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
      delete z;

    }
    if (yOriginalColor == BLACK) {

      FixUpD(x);

    }

  }

  // Public recursive preorder print (for clarity). N L R
  void preOrder() {

    _preOrder(root);
    std::cout << "\n";

  }

};

// Intialize non-int static members outside
// need -std=c++11 to use the intializer-list constructor call
RBTree::TreeNode* const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});

int main(int argc, char ** argv) {

  // printf("Warning! Insert-Fixup not implemented! RBT properties will not be enforced!\n");
  RBTree t;
  t.insertion(3);
  t.insertion(2);
  t.insertion(5);
  t.printInOrder();

  return 0;

}
