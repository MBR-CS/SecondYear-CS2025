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

list UniqueListInAnotherList(list head){
list temp = head , headOdd=nullptr,headEven=nullptr,tempOdd=nullptr, tempEven=nullptr, Q=nullptr;
while (temp != nullptr) {
    if (temp->data % 2 == 0) { // even number check
        tempEven = new node;
        tempEven->next = nullptr;
        tempEven->data = temp->data;
        if (headEven == nullptr) {
          headEven = tempEven;
        }else {
          Q->next  = tempEven;
        }
      Q = tempEven;
    }
    else {// otherwise  then odd number
      tempOdd = new node;
      tempOdd->next = headOdd;
      tempOdd->data = temp->data;
      headOdd = tempOdd;
    }
    temp = temp->next;

  
}
  if (headEven == nullptr) {
    return headOdd;
  }else {
    Q->next = headOdd;
    return headEven;
  }
  
}


list SelfUniqueList(list head){
  list temp = head  , before= head , newHead= head ;
  while (temp != nullptr) {
    if (temp->data % 2 == 0) {
      before->next = temp->next;
      temp->next = newHead;
      newHead = temp;
      temp = before->next;

    }else {
     before = temp;
      temp = temp->next ;
 
    }
 }
  return newHead;
}




int main () {
  int size;
  list head;
  std::cout << "please enter size of linked list: ";
  std::cin >> size;
  head = CreateLinkedListLinear(size);
  PrintValues(head);
  head = SelfUniqueList(head);
  //head = UniqueListInAnotherList(head);
  PrintValues(head);
  return 0;
}







