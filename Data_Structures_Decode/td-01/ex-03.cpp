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

// create new functino can check if the list is ascending order
bool CheckAscendingOrder(list head){
  bool ascending = true;
  list before=head, after=head;
  while (after != nullptr && ascending != false) {
    if (before->data > after->data) {
      ascending = false; 
      break;
      
    }
    before = after;
    after = before->next;
  }
  return ascending;
}

// create new function for concatenats two linked list   
list ConcatenatesTwoListInOneList(list  &mainList, list subList){

}
int main () {
  list head;
  int size;
  bool ascendingCheck;
  cout << "please enter the size of linked list linear: ";
  cin >> size;
  head = CreateLinkedListLinear(size);
  PrintValues(head);
  ascendingCheck = CheckAscendingOrder(head);
  if (ascendingCheck == true) {
    cout << "the list is ascending order "<<endl;
    
  }else {
   cout << "the list is not ascending order!!"<<endl; 
  }

  
  return 0;
}

