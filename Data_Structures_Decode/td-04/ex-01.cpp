#include <iostream>
#include <queue>
using std::queue;
using std::cout;
using std::cin;
using std::endl;

// create struct tree  
struct node;
using tree = node*;

struct node { 
    int data; 
    tree left, right;
    node (int value){
      data = value;
      left = nullptr;
      right = nullptr;
  }
};


void PrintLevelOrder(tree root);
void InsertNode(tree &root);
int main () {
  tree root = nullptr;
  InsertNode(root);
  InsertNode(root);
  InsertNode(root);
  InsertNode(root);
  PrintLevelOrder(root);
  return 0;
}

// create function for insert new node in binary tree

void PrintLevelOrder(tree root) {
    if (root == nullptr) return;
    
    queue<node*> q;
    q.push(root);
    
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        cout << temp->data << " ";
        
        if (temp->right) q.push(temp->right);
        if (temp->left) q.push(temp->left);
    }
}


void InsertNode(tree &root){
  tree newNode = nullptr, temp;
  int value;
  queue<tree> MyQueue;
  if (root == nullptr) {
    std::cout << "Enter the value of the root  node: ";
    cin >> value;
    newNode = new node(value);
    root = newNode;
    return;
  }
  std::cout << "Enter the value of the node: ";
  cin >> value;
  newNode = new node(value);
  MyQueue.push(root);
  while (!MyQueue.empty()) {
    temp = MyQueue.front();
    MyQueue.pop();
    if (temp->right == nullptr) {
      temp->right = newNode;
      return;
    }else {
      MyQueue.push(temp->right);
    }

    if (temp->left == nullptr) {
      temp->left = newNode;
      return;
    }else {
      MyQueue.push(temp->left);
    }
  }







}



