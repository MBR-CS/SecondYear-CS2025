#include <iostream>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    int data; 
    list next; 
};


// create function prototype
list CreateLinkedListLinear(int size); // create new linked list
void PrintValues(list head); // print the linked list
void BubbleSortAlgorithm(list head, int size); // sort the linked list 
void InvertList(list head); // invert the linked list i mean reverse the linked list
list MergeLists(list head1, list head2); // merge two linked list 
void ExplodeList(list head, list& head1, list& head2); // explode the linked list i mean split the linked list
list DeleteAllDuplicates(list head); // delete all duplicates in the linked list and return the new linked list 
bool IsSublist(list head1, list head2); // check if the linked list is sublist of another linked list 

// main function
int main () {
  list head = nullptr;
  int size;
  cout << "Enter the size of the linked list: ";
  cin >> size;
  head = CreateLinkedListLinear(size);
  std::cout << "The linked list is : ";
  PrintValues(head);
  BubbleSortAlgorithm(head, size); 
  std::cout << "The linked list after sorting is : ";
  PrintValues(head);

  
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


void BubbleSortAlgorithm(list head, int size) {
    // If list is empty or has only one element, return
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;
    list temp;
    
    // Outer loop for each pass
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        temp = head;
        
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < size - i - 1; j++) {
            if (temp->data > temp->next->data) {
                // Swap the data
                int swapData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = swapData;
                swapped = true;
            }
            temp = temp->next;
        }
        
        // If no swapping occurred, list is sorted
        if (!swapped) {
            break;
        }
    }
}






