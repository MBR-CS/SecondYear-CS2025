#include <iostream>
#include <queue>
#include <stack>
using std::stack;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

// NOTE: create  function prototypes
void PrintQueue(queue<int>& MyQueue);
void InitQueue(queue<int> &MyQueue);
int OccurrencesEven(queue<int> &MyQueue);
void ReplaceAllOccurrences(queue<int> &MyQueue,int x, int y);
void ReverseQueue(queue<int> &MyQueue);
void SorteQueue(queue<int> &MyQueue);

int main () {
  queue<int> MyQueue;
  InitQueue(MyQueue);
  std::cout << "The Queue is: ";
  PrintQueue(MyQueue);
  SorteQueue(MyQueue);
  std::cout << "The Sorted Queue is: ";
  PrintQueue(MyQueue);
  return 0;
}
 

//NOTE: Core functions 
void PrintQueue(queue<int>& MyQueue){
  queue<int> helper;
  int size = MyQueue.size();
  for (int i = 0; i < size; i++) {
    std::cout << MyQueue.front() << " ";
    helper.push(MyQueue.front());
    MyQueue.pop();
  }
  for (int i = 0; i < size; i++) {
    MyQueue.push(helper.front());
    helper.pop();
}
 std::cout << std::endl;
} 

void InitQueue(queue<int> &MyQueue){
  int size;
  int element;
  std::cout << "please enter the size of the queue: ";
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    std::cout << "please enter element " << i+1 << " :";
    std::cin >> element;
    MyQueue.push(element);
  }
}





//NOTE: create  function definitions for exercise 01
int OccurrencesEven(queue<int> &MyQueue){
  queue<int> helper;
  int counter = 0 , size = MyQueue.size();
  for (int i = 0; i < size; i++) {
    if (MyQueue.front() % 2 == 0) {
       counter++;
    } 
    helper.push(MyQueue.front());
    MyQueue.pop();
  }
  for (int i = 0; i < size; i++) {
    MyQueue.push(helper.front());
    helper.pop();
  }
  return counter;
}

void ReplaceAllOccurrences(queue<int> &MyQueue,int x, int y){
  queue<int> helper;
  int size = MyQueue.size();
  for (int i = 0; i < size; i++) {
    if (MyQueue.front() == x) {
      helper.push(y);
      MyQueue.pop();
      continue;  
    } 
    helper.push(MyQueue.front());
    MyQueue.pop();
  }
  for (int i = 0; i < size; i++) {
    MyQueue.push(helper.front());
    helper.pop();
  }
} 

void ReverseQueue(queue<int> &MyQueue){
  stack<int> helper;
  int size = MyQueue.size();
  for (int i = 0; i < size; i++) {
    helper.push(MyQueue.front());
    MyQueue.pop();
  }

  for (int i = 0; i < size; i++) {
    MyQueue.push(helper.top());
    helper.pop();
  }
}


void SorteQueue(queue<int> &MyQueue ){
  int MinValue ; 
  queue<int> helper, SortedQueue;
  // find the minimum value in the queue and push it to the sorted queue
  while (!MyQueue.empty()) {
      MinValue = MyQueue.front();
      MyQueue.pop();
    while (!MyQueue.empty()) {
      if (MyQueue.front() <MinValue) {
        helper.push(MinValue);
        MinValue = MyQueue.front();
        MyQueue.pop();
       }else {
        helper.push(MyQueue.front());
        MyQueue.pop();
        
       } 
    }
   // return the helper queue to the original queue 
    while (!helper.empty()) {
        MyQueue.push(helper.front());
        helper.pop();
    }   
    SortedQueue.push(MinValue);
  }
  // return the sorted queue to the original queue
  while (!SortedQueue.empty()) {
        MyQueue.push(SortedQueue.front());
        SortedQueue.pop();
    }   
}


void SortedQueueUsingStack(queue<int> &MyQueue){
  stack<int> helper;
  int size ;
  while (!MyQueue.empty()) {
    helper.push(MyQueue.front());
    MyQueue.pop();
    size = MyQueue.size();
    for (int i = 0; i < size; i++) {
      if () {
        
      }else {
        
      }

    }   
  }
 














