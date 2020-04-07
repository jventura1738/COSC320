// Justin Ventura COSC320
// Lab-9: main.cpp

#include <stdio.h>

enum color_t{
  RED, BLACK
};

class RBTree{
  private:
    struct TreeNode {
      int key;
      color_t color;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
    };

    static TreeNode* const nil;

    TreeNode* root;

    void _printInOrder(TreeNode* u){
      if( u != nil ){
        _printInOrder(u->left);
        printf(" %d", u->key);
        _printInOrder(u->right);
      }
    }

  public:
    /* Fill in with methods */
    RBTree(){
      root = nil;
    }

    void printInOrder(){
      printf("Tree data in order: ");
      _printInOrder(root);
      puts("");
    }

    void insert(int k){
      TreeNode* newNode = new TreeNode;
      newNode->key = k;

      if (root == nil){
        printf("Inserting %d into empty tree\n", k);
        root = newNode;
        newNode->parent = nil;
      } else {
        TreeNode* y = nil;
        TreeNode* x = root;
        while(x != nil){
          y = x;
          if( k < x->key ){
            x = x->left;
          } else {
            x = x->right;
          }
        }
        if( k < y->key ){
          printf("Inserting %d on the left of %d\n",k,y->key);
          y->left = newNode;
        } else {
          printf("Inserting %d on the right of %d\n",k,y->key);
          y->right = newNode;
        }
        newNode->parent = y;
      }
      newNode->color = RED;
      newNode->left = nil;
      newNode->right = nil;
      // TODO: Call fixup
    }
};

// Intialize non-int static members outside
// need -std=c++11 to use the intializer-list constructor call
RBTree::TreeNode* const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});

int main(int argc, char* argv[]){
  printf("Warning! Insert-Fixup not implemented! RBT properties will not be enforced!\n");
  RBTree t;
  t.insert(3);
  t.insert(2);
  t.insert(5);
  t.printInOrder();
  return 0;
}