#include <iostream>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    int data; 
    list next; 
};


void PrintValues(list head);
list CreateLinkedListLinear(int size); 
list CreateBox(int n);
list CountEvenOdd(list head,  list box);
int main () {
  int size;
  list head;
  list box;
  std::cout << "Enter the size of the linked list: ";
  cin >> size;
  head = CreateLinkedListLinear(size);
  PrintValues(head);
  box = CreateBox(2);
  box = CountEvenOdd(head, box);
  cout << "The number of even numbers is: " << box->data << endl;
  cout << "The number of odd numbers is: " << box->next->data << endl;


  return 0;
}



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

list CreateBox(int n){
  list current = nullptr, newNode = nullptr ; 
  for (int i = 0; i < n; i++) {
      newNode = new node;
      newNode->next = current;
      newNode->data = 0;
      current = newNode;
      
  }
  return current;
}

list CountEvenOdd(list head, list box){
  if (head == nullptr) {
     return box; 
  }
  if (head->data % 2 == 0) {
    box->data++;
  }else {
    box->next->data++;
  }
  return CountEvenOdd(head->next , box);
}

