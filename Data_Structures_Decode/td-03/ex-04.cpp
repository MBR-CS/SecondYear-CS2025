#include <iostream>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    char data; 
    list next; 
};


void PrintValues(list head);
list CreateLinkedListLinear(int size); 
int OccurrencesValue(list head, char c);
int main () {
  
  int size;
  list head;
  char c;
    std::cout << "Enter the size of the linked list: ";
    cin >> size;
    head = CreateLinkedListLinear(size);
    PrintValues(head);
    cout << "Enter the character you want to count: ";
    cin >> c;
    cout << "The number of occurrences of the character " << c << " is: " << OccurrencesValue(head, c) << endl;

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

int OccurrencesValue(list head, char c){
  int status = 0;
  if (head == nullptr) {
    return 0;
  }
  if (head->data == c) {
    status = 1;
  }
  return status + OccurrencesValue(head->next, c);
  
}



