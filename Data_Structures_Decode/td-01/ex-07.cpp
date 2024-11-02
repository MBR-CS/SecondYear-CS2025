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
listData CreateLinkedListLinear(int sizeStudent);
void PrintData(listData HeadData);
void PrintNote(listNote HeadNote);
int CalculateAverage__And__AdmittedStudent(listData head); 
listNote InsertNote(int sizeNote);
int main () {
  int sizeStudent, sizeNote, admittedStudent;
  listData head;
  std::cout << "Please Enter The Size Of Section: ";
  std::cin >> sizeStudent;
  head = CreateLinkedListLinear(sizeStudent);
  admittedStudent = CalculateAverage__And__AdmittedStudent(head); 
  PrintData(head);

  std::cout <<"\033[32m"<<"The Number Of Admitted Student Is: "<< admittedStudent <<"\033[0m"<<endl;

  return 0;
}

listNote InsertNote(int sizeNote){
listNote headNote = nullptr;
listNote currentNote = nullptr;
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
  return headNote;
}


listData CreateLinkedListLinear(int sizeStudent) {
    listData head = nullptr;
    listData current = nullptr;
    int sizeNote;
    for (int i = 0; i < sizeStudent; i++) {
        listData newNode = new Data;
        std::cout << "-------------------------------------------------"<<endl;
        cout << "Please Enter The ID:  ";
        cin >> newNode->id;
        cout << "Enter the first name :  " ;
        cin >> newNode->firstName;
        cout << "Enter the last name :  " ;
        cin >> newNode->lastName;
        newNode->GA = 0;
        std::cout << "Please Enter The Number Of Note: ";
        std::cin >> sizeNote;       
        newNode->data = InsertNote(sizeNote);
        newNode->next = nullptr;
        if (head == nullptr)  
          head = newNode;
        else  
          current->next = newNode;
        current = newNode;
    }
    
    return head;
}

void PrintData(listData HeadData){
  listData temp = HeadData;
  
  while (temp != nullptr) {

    std::cout << "--------------Information:--------------"<<endl;
    std::cout << "id: "<< temp->id<<endl; 
    std::cout << "first name: "<<temp->firstName<<endl; 
    std::cout << "last name: "<<temp->lastName<<endl; 
    std::cout << "GA: "<<temp->GA<<endl;
    std::cout << "--------------Notes:--------------"<<endl;
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


int CalculateAverage__And__AdmittedStudent(listData head){
listData tempData=head; 
listNote  tempNote=nullptr;
double average = 0 ;

int coef = 0 ,admittedStudent = 0 ;
  while (tempData != nullptr) {
    average = 0;
    coef = 0;
    tempNote = tempData->data;
    while (tempNote != nullptr) {
      average += (tempNote->note * tempNote->coef);
      coef += tempNote->coef;
      tempNote = tempNote->next;
    }
    average /=  coef;
    tempData->GA = average;
    if (average >= 10) {
      admittedStudent++;
    }

    tempData = tempData->next;
  }
  return admittedStudent;
}







