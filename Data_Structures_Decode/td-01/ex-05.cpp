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
list InvertList(list head); // invert the linked list i mean reverse the linked list
list MergeLists(list head1, list head2); // merge two linked list 
void ExplodeList(list head, list& head1, list& head2); // explode the linked list i mean split the linked list
list DeleteAllDuplicates(list head); // delete all duplicates in the linked list and return the new linked list 
bool IsSublist(list head1, list head2); // check if the linked list is sublist of another linked list 

bool SubListCheck(list main, list subHead);

// main function
int main () {
  list head1 = nullptr,head2= nullptr,head3 = nullptr;
  int size,size2;
  cout << "Enter the size of the linked list: ";
  cin >> size;
  head1 = CreateLinkedListLinear(size);
  std::cout << "The linked list is : ";
  PrintValues(head1);
  /*BubbleSortAlgorithm(head, size); 
  std::cout << "The linked list after sorting is : ";
  PrintValues(head);
  head = InvertList(head); 
  std::cout << "The linked list after inverting is : ";
  PrintValues(head);
  cout << "Enter the size of the sub linked list: ";
  cin >> size2;
  head2 = CreateLinkedListLinear(size2);
  std::cout << "The linked list is : ";
  head3 = MergeLists(head1, head2);
  PrintValues(head3);
  ExplodeList(head1, head2, head3);
  std::cout << "The linked list Even is : ";
  PrintValues(head2);
  std::cout << "The linked list Odd is : ";
  PrintValues(head3);
  head3 = DeleteAllDuplicates(head1);
  std::cout << "The linked list after deleting all duplicates is : ";
  PrintValues(head3);*/
   cout << "Enter the size of the sub linked list: ";
  cin >> size2;
  head2 = CreateLinkedListLinear(size2);
  std::cout << "The linked list is : ";
  PrintValues(head2);
  if (SubListCheck(head1,head2)) {
     std::cout << "yes";
   } else {
     
     std::cout <<"no" ;
   }


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


list InvertList(list head){
  list previous=nullptr, current= head, next;
  while (current != nullptr) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
    
  }
  return previous;
}

list MergeLists(list head1, list head2){
list temp1 = head1 , temp2 = head2;
list head3 = nullptr;
list current = nullptr, newNode = nullptr ;
int data ;

    while (temp1!=nullptr && temp2 != nullptr) {
        newNode = new node;
        if (temp1->data < temp2->data) {
          data = temp1->data;
          temp1 = temp1->next;

        }else {
          data = temp2->data;
          temp2 = temp2->next;
        }
        newNode->data = data;
        newNode->next = nullptr;
        if (head3 == nullptr)  
          head3 = newNode;
        else  
          current->next = newNode;
        current = newNode;
    }
    if (temp1 == nullptr) {
      current->next = temp2;
    }else {
      
      current->next = temp1;
    }
  return head3;
}


void ExplodeList(list head, list& head1, list& head2){
list temp = head, tempEven, tempOdd;

  while (temp != nullptr) {
    if (temp->data % 2 == 0) {
         if (head1 == nullptr) {
          head1 = temp;
          tempEven = temp;
         }else {
          tempEven->next = temp;
          tempEven = temp;  
         }
    }else {
         if (head2 == nullptr) {
          head2 = temp;
          tempOdd = temp;
         }else {
          tempOdd->next = temp;
          tempOdd = temp;  
         }
       
    } 
    temp = temp->next;
  
}
  tempOdd->next = nullptr;
  tempEven->next= nullptr;
}


bool IsFound(list head, int value){
  list temp = head;
  while (temp != nullptr) {
    if (temp->data == value) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

list DeleteAllDuplicates(list head){
  list temp = head, current=nullptr, newNode=nullptr;
  while (temp != nullptr) {
    if (IsFound(current, temp->data) == false) {
      newNode = new node;
      newNode->data = temp->data;
      newNode->next = current;
      current = newNode;
    }
    temp = temp->next;
  }
  return current;
}

bool SubListCheck(list main, list subHead){
  list sub = subHead, temp = main; 
  bool status = false;
  while (sub != nullptr && temp != nullptr) {
    if (temp->data == sub->data) {
      sub = sub->next;
      if (sub==nullptr) {
        status = true;
      }
    }else {
      sub = subHead;
      status = false;
      
    }
    temp = temp->next;
  }
  return status;
} 


