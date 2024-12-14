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
void ReverseQueueOnly(queue<int> &MyQueue);

int main () {

  queue<int> MyQueue;
  InitQueue(MyQueue);
  std::cout << "The Queue is: ";
  PrintQueue(MyQueue);
  ReverseQueueOnly(MyQueue);
  std::cout << "The Reversed Queue is: ";
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


void ReverseQueueOnly(queue<int> &MyQueue){
int  size= MyQueue.size(),counter=size;
queue<int> TempRev, helper;
  while (counter != 0) {
      while (counter != 1) {
          helper.push(MyQueue.front());
          MyQueue.pop();      
          counter--;
      } 
      
      counter = 0; 
      TempRev.push(MyQueue.front());
      MyQueue.pop();

      while (!helper.empty()) {
            counter++;
            MyQueue.push(helper.front());
            helper.pop();
      }
  }
  while (!TempRev.empty()) {
      MyQueue.push(TempRev.front());
      TempRev.pop();
  }


}







