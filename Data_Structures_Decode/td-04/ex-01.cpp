#include "Tree/tree.h"
#include <iostream>

// create declaration of the functions
int DepthTree();
int LeavesOfTree(tree root);
int InternalNodesTree(tree root);
int SizeTree(tree root);
int main(){
    
    tree root = nullptr;
    int maxSize;
    int currentSize = 0;

    std::cout << "Enter maximum size of the tree: ";
    std::cin >> maxSize;

    root = CreateBinaryTree(root, currentSize, maxSize);
    printBinaryTree(root, 0,10);
}

// create the implementation of the functions
int SizeTree(tree root){
}

int InternalNodesTree(tree root){

}


int LeavesOfTree(tree root){

}



int DepthTree(){

}
