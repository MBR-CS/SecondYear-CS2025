#include "Tree/tree.h"
#include <iostream>
using namespace std;

// create declaration of the functions
int DepthTree();
int LeavesOfTree(tree root);
int InternalNodesTree(tree root);
int SizeTree(tree root);
void inorderTraversal(tree root);
int main(){
  tree root = nullptr; 
  InitTree(root);
  inorderTraversal(root);
  cout << endl; 
  cout << "The size of the tree is: " << SizeTree(root) << endl;

}

void inorderTraversal(tree root) {
  
    // Empty Tree
    if (root == nullptr)
        return;
  
    // Recur on the left subtree
    inorderTraversal(root->left);
 
    // Visit the current node
    cout << root->data << " ";
  
    // Recur on the right subtree
    inorderTraversal(root->right);
}

// create the implementation of the functions
int SizeTree(tree root){
  if (root == nullptr)
      return 0;
  
  return 1 + SizeTree(root->left) + SizeTree(root->right);
  
}

int InternalNodesTree(tree root){

}


int LeavesOfTree(tree root){

}



int DepthTree(){

}
