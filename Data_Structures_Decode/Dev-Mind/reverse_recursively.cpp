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
void ReverseQueueRecersive(queue<int> &Q);
void CopyStack(stack<int> &S, stack<int> &_Copy);
void ReverseStackRecersive(stack<int> &S);
void PrintStack(stack<int>& MyStack);
void InitStack(stack<int> &MyStack);

int main () {

  queue<int> MyQueue;
  InitQueue(MyQueue);
  std::cout << "The Queue is: ";
  PrintQueue(MyQueue);
  ReverseQueueRecersive(MyQueue);
  std::cout << "The Reversed Queue is: ";
  PrintQueue(MyQueue);
  
  stack<int> MyStack;
  InitStack(MyStack);
  std::cout << "The Stack is: ";
  PrintStack(MyStack);
  ReverseStackRecersive(MyStack);
  std::cout << "The Reversed Stack is: ";
  PrintStack(MyStack);



 return 0;
}
 
//NOTE: Core functions 

void PrintStack(stack<int>& MyStack){
  stack<int> temp;
    
    cout << "\n\n";
    
    while(!MyStack.empty()) {
        cout << "| " << MyStack.top() << " |\n";
        temp.push(MyStack.top());
        MyStack.pop();
    }
    
    cout << "⎯⎯⎯⎯\n";
    
    while(!temp.empty()) {
        MyStack.push(temp.top());
        temp.pop();
    }} 

void InitStack(stack<int> &MyStack){
  int size;
  int element;
  std::cout << "please enter the size of the stack: ";
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    std::cout << "please enter element " << i+1 << " :";
    std::cin >> element;
    MyStack.push(element);
  }
}




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




//NOTE: create the core functions

void  ReverseQueueRecersive(queue<int> &Q){
  int temp;
  
  if (Q.empty()) {
    return ;
  }
  temp = Q.front();
  Q.pop();
  ReverseQueueRecersive(Q);
  
  Q.push(temp);

}




//NOTE: reverse a stack using recursion 
void CopyStack(stack<int> &S, stack<int> &_Copy){
  if (S.empty()) {
    return;
  }
  int temp = S.top();
  S.pop();
  CopyStack(S,_Copy);
  
  _Copy.push(temp);


}




void ReverseStackRecersive(stack<int> &S){
  stack<int> helper;

  CopyStack(S, helper);
  while (!helper.empty()) {
    S.push(helper.top());
    helper.pop();   
  }
}


