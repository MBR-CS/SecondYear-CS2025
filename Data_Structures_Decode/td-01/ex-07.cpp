#include <iostream>
using namespace std ;  
  

// create struct node
struct Data;
struct Note;
using listData = Data*;
using listNote = Note*;

struct Data { 
  int id;
  string firstName, lastName;
  double GA;
  listNote data;
  listData next;

};
struct Note { 
    double note;
    int coef; 
    listNote next; 
};

// create function for take the size and create new linked list 
listData CreateLinkedListLinear(int sizeStudent, int sizeNote) {
     listData head = nullptr;
     listData current = nullptr;
     listNote headNote = nullptr;
     listNote currentNote = nullptr;

    for (int i = 0; i < sizeStudent; i++) {
        listData newNode = new Data;
        cout << "Please Enter The ID:  ";
        cin >> newNode->id;
        cout << "Enter the first name :  " ;
        cin >> newNode->firstName;
        cout << "Enter the last name :  " ;
        cin >> newNode->lastName;
        newNode->GA = 0;
        for (int i = 0; i < sizeNote; i++) {
            listNote newNodeNote = new Note;
            cout << "      enter the note number " << i + 1 << " : ";
            cin >> newNodeNote->note;
            cout << "      enter the coef for note number " << i + 1 << " : ";
            cin >> newNodeNote->coef;
            newNodeNote->next = nullptr;
            if (headNote == nullptr)  
              headNote = newNodeNote;
            else  
              currentNote->next = newNodeNote;
            currentNote = newNodeNote;
        }
        
        std::cout << "-------------------------------------------------";
        newNode->data = headNote;
        headNote = nullptr;
        newNode->next = nullptr;
        if (head == nullptr)  
          head = newNode;
        else  
          current->next = newNode;
        current = newNode;
    }
    
    return head;
}

void PrintNote(listNote HeadNote);
void PrintData(listData HeadData){
  listData temp = HeadData;
  
  while (temp != nullptr) {
    std::cout << "id: "<< temp->id<<endl; 
    std::cout << "first name: "<<temp->firstName<<endl; 
    std::cout << "last name: "<<temp->lastName<<endl; 
    std::cout << "GA: "<<temp->GA<<endl;
    std::cout << "--------------notes:--------------"<<endl;
    PrintNote(temp->data);

    temp = temp->next;
  }
}

// create new functino for print the linked list
void PrintNote(listNote HeadNote){
  listNote current = HeadNote;
  
  while (current != nullptr) {
    std::cout << "the note of coef  " << current->coef << " is :"<< current->note <<endl; 
    current = current->next;
  }
  cout << endl;
}





int main () {
  int sizeStudent, sizeNote;
  listData head;
  std::cout << "Please Enter The Size Of Section: ";
  std::cin >> sizeStudent;
  std::cout << "Please Enter The Number Of Note: ";
  std::cin >> sizeNote;
  std::cout << "-------------------------------------------------";
  head = CreateLinkedListLinear(sizeStudent, sizeNote);
  PrintData(head);
  return 0;
}

















