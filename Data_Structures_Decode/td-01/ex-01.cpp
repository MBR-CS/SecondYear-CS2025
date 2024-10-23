#include <iostream>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    int data; 
    list next; 
};


// create function for take the size and create new linked list 
list CreateLinkedListLinear(int size) {
    list head = nullptr;
    list current = nullptr;

    for (int i = 0; i < size; i++) {
        list newNode = new node;
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = nullptr;
        if (head == nullptr)  
          head = newNode;
        else  
          current->next = newNode;
        current = newNode;
    }
    
    return head;
}

// create new functino for print the linked list
void PrintValues(list head){
  list current = head;

  while (current != nullptr) {
    cout << current->data <<"  ";
    current = current->next;

  }
  cout << endl;
}

// create function for get size linked list linear
int SizeLinkedListLinear(list head){
  int size = 0;
  list current = head;
  while (current != nullptr) {
    size++;
    current = current->next;
  }
  return size;
} 

// create new function for get the position of the last (first) occurrence of an integer x in the list L
int GetThePositionLastOccurrence(list head , int x){
  int position= 0, current = 1;
  list node = head;
  while (node != nullptr) {
    if (node->data == x) {
      position = current;
        
      }  
    node = node->next;
    current++;
  
  }
  return position;

}

// create function for Replaces all occurrences of the element x by an element y in the list L.

void ReplaceAllOccurrences(list head , int x, int y){
  list current = head ;
  while (current != nullptr) {
    if (current->data == x) {
      current->data = y;
    }
    current = current->next;
  }
}





int  main () {
  int size,x,y;
  list head;
  cout << "please enter size of values: ";
  cin >> size;
  head = CreateLinkedListLinear(size);
  PrintValues(head);
  cout << "the size of linked list is: "<< SizeLinkedListLinear(head)<<" values"<<endl;
  cout << "please enter number for get the position in lll:";
  cin >> x;
  cout << "the last position show value "<<x<<" is: "<< GetThePositionLastOccurrence(head, x)<<endl;
  cout << "enter value x: ";
  cin >> x;
  cout << "enter value y: ";
  cin >> y;
  ReplaceAllOccurrences(head, x, y);
  PrintValues(head);
  return 0;
}











