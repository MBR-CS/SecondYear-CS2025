#include "tree.h"
#include <iostream>
#include <queue>
using namespace std;

bool IsEmptyTree(tree root) {
    return root == nullptr;
}

int Value(tree Tree) {
    return Tree->data;
}

tree LeftSubTree(tree root) {
    if (root == nullptr) {
        return nullptr;
    }
    return root->left;
}

tree RightSubTree(tree root) {
    if (root == nullptr) {
        return nullptr;
    }
    return root->right;
}

void InsertTree(tree &root, int Value) {
  tree temp = nullptr ;
  queue<tree> helper;
  if (!root) {
    root = new node(Value);
    return;
  }
  helper.push(root);

  while (!helper.empty()) {
    temp = helper.front();
    helper.pop();

    if (!LeftSubTree(temp)) {
        temp->left = new node(Value);
        return;
    }else {
        helper.push(temp->left);
    }
    if (!RightSubTree(temp)) {
        temp->right = new node(Value);
        return;
    }else {
        helper.push(temp->right);
    }   
  }
}

void InitTree(tree &root){
  std::cout << "enter the number of nodes in the tree: "  ;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    int value;
    cout << "enter the value of the node: ";
    std::cin >> value;
    InsertTree(root, value);
  }
}






void printBinaryTree(tree  root, int space = 0, int height = 10){

}
