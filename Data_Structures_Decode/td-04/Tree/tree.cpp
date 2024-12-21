#include "tree.h"
#include <iostream>
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

tree CreateBinaryTree(tree &root, int &currentSize, int maxSize) {
    if (currentSize >= maxSize) {
        return nullptr;
    }

    int value;
    std::cout << "Enter value for node (-1 to skip this node): ";
    std::cin >> value;

    if (value == -1) {
        return nullptr;
    }

    root = new node(value);
    currentSize++;  // Increment size counter

    std::cout << "\nCreating left child for node " << value
              << " (Current size: " << currentSize << "/" << maxSize << ")" << std::endl;
    root->left = CreateBinaryTree(root->left, currentSize, maxSize);

    std::cout << "\nCreating right child for node " << value
              << " (Current size: " << currentSize << "/" << maxSize << ")" << std::endl;
    root->right = CreateBinaryTree(root->right, currentSize, maxSize);

    return root;
}
void printBinaryTree(tree  root, int space = 0, int height = 10){
    // Base case
    if (root == nullptr) {
        return;
    }

    // now increase distance between levels
    space += height;

    // print the right child first
    printBinaryTree(root->right, space);
    cout << endl;

    // print the current node after increasing with spaces
    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << root->data;

    // print the left child
    cout << endl;
    printBinaryTree(root->left, space);
}
