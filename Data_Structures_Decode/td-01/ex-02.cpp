#include <iostream>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    char  data; 
    list next; 
};
list CreateLinkedListLinear(int size);
void PrintValues(list head);
int Frequency(list head , char c );
char MostFrequency(list head);

int main () {
  int size, counter ;
  char c, MostFrequencyChar ;
  list head;
  cout << "please enter size of values: ";
  cin >> size;
  head = CreateLinkedListLinear(size);
  PrintValues(head);
  MostFrequencyChar = MostFrequency(head) ;
  cout << "The most Frequency is char "<< MostFrequencyChar  <<endl;
  return 0;
}


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
// create a new function for get the frequency of an cahr c in the list L
int Frequency(list head , char c ) {
  list temp = head ;
  int counter = 0;
  while (temp != nullptr) {
    if (temp->data == c) {
      counter++;
    }
    temp = temp->next;
  }
  return counter;
}
// create new function can get the most frequency in lll
char MostFrequency(list head){
  list temp = head ; 
  char most = '!';
  int repeat = 0, repeatCallFunction ;
  while (temp != nullptr) {
    repeatCallFunction = Frequency(head, temp->data) ;
    if (repeatCallFunction >= repeat) {
      most = temp->data;
      repeat = repeatCallFunction;
    }
    temp = temp->next;

  }

  return most;
  
}

