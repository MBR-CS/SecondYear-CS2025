// create header file tree.h
#ifndef TREE_H
#define TREE_H

// include necessary libraries for the struct and function prototypes (nullptr)
#include <cstddef>
// create struct tree
struct node;
typedef node* tree;

// create struct tree
struct node {
    int data;
    tree left, right;
  node (int value){
      data = value;
      left = nullptr;
      right = nullptr;
  }
};

/**
  * - check if the tree is empty 
  *   return true if empty
  *   return false if not empty
  *   @param tree root
  *   @return bool

 */
bool IsEmptyTree(tree root );
/**
  * - get the value of the root
  *   @param tree root
  *   @return int value of the root
 */
int Value(tree Tree );
/**
  * - get the left subtree of the root
  *   @param tree root
  *   @return tree left subtree
  *   @return nullptr if left subtree is empty
  *   @return left subtree if not empty
  *   @return tree
  *   @return nullptr
 */
tree LeftSubTree(tree root );
/**
  * - get the right subtree of the root
  *   @param tree root
  *   @return tree right subtree
  *   @return nullptr if right subtree is empty
  *   @return right subtree if not empty
  *   @return tree
  *   @return nullptr
 */
tree RightSubTree(tree root );
/**
  * - create a binary tree
  *   @param tree root
  *   @param int currentSize
  *   @param int maxSize
  *   @return tree
 */
 tree CreateBinaryTree(tree &root, int &currentSize, int maxSize);

/**
  * - print the binary tree
  *   @param tree root
  *   @param int space
  *   @param int height
 */

void printBinaryTree(tree  root, int space , int height );

#endif // TREE_H
