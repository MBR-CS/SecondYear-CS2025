#include <iostream>
#include <cmath>
using namespace std ;  
  

// create struct node
struct node;
using list = node*;

struct node { 
    int data; 
    list next; 
};
void PrintValues(list head);
bool IsPrime(int n);
list PrimeList(int N);


int main () {
  int N;
  list head = nullptr;

  std::cout << "please enter N (N>0)!: ";
  std::cin >> N;
  head = PrimeList(N);
  std::cout << "the list of number primes in range "<< N<<" is :";
  PrintValues(head);
  return 0;
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


bool IsPrime(int n){
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) 
          return false;
  }
return true;
}

list PrimeList(int N){
    list head = nullptr;
    list current = nullptr;

    for (int i = 1; i <= N; i++) {
      if (IsPrime(i)){
        list newNode = new node;
        newNode->data = i;
        newNode->next = nullptr;
        if (head == nullptr){
          head = newNode;
        }  
        else {
          current->next = newNode;
        } 
        current = newNode;       
      }
 
    }
    
    return head;
}

