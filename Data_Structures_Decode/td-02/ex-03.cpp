#include <iostream>
#include <queue>
#include <stack>
using std::stack;
using std::queue;
using std::cout;
using std::cin;
using std::endl;


void PrintQueue(queue<int>& MyQueue);
void InitQueue(queue<int> &MyQueue);
void MergeSortedQueue(queue<int> &SortedQueue,queue<int> &MainQueue, queue<int> &SubQueue);
void SplitStack(stack<int> &MyQueue, stack<int> &EvenStack, stack<int> &OddStack);
void PrintStack(stack<int>& MyStack);
void InitStack(stack<int> &MyStack);
bool IsSubStack(stack<int> &MainStack, stack<int> &SubStack);
int main () {
  stack<int> MainStack, SubStack;
  InitStack(MainStack);
  std::cout << "MainStack is: ";
  PrintStack(MainStack);
  InitStack(SubStack);
  std::cout << "SubStack is: ";
  PrintStack(SubStack);

  if (IsSubStack(MainStack, SubStack)) {
    cout << "SubStack is a substack of MainStack" << endl;
  }else {
    cout << "SubStack is not a substack of MainStack" << endl;
  }
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

void MergeSortedQueue(queue<int> &SortedQueue,queue<int> &MainQueue, queue<int> &SubQueue){

  while (!MainQueue.empty() and !SubQueue.empty()) {
    if (MainQueue.front() < SubQueue.front()) {
      SortedQueue.push(MainQueue.front());
      MainQueue.pop();
      continue;
    }
    SortedQueue.push(SubQueue.front());
    SubQueue.pop();
  }
  while (!SubQueue.empty()) {
      SortedQueue.push(SubQueue.front());
      SubQueue.pop();       
      }  
  while (!MainQueue.empty()) {
      SortedQueue.push(MainQueue.front());
      MainQueue.pop();       
      } 
  
}


void SplitStack(stack<int> &MyStack, stack<int> &EvenStack, stack<int> &OddStack){
   
  while (!MyStack.empty()) {
    if (MyStack.top() % 2 == 0)
      EvenStack.push(MyStack.top());
    else
      OddStack.push(MyStack.top());
    MyStack.pop();
  }
}

bool IsSubStack(stack<int> &MainStack, stack<int> &SubStack)
{
  stack<int> helper;
  while (!MainStack.empty() && !SubStack.empty()) {
    if (MainStack.top() == SubStack.top()) {
      helper.push(SubStack.top());
      SubStack.pop();
    }else if (!helper.empty()) {
      while (!helper.empty()) {
        SubStack.push(helper.top());
        helper.pop();
      }
      continue;
    }
    MainStack.pop();
  }

  if (SubStack.empty()) {
    return true;
  }
  return false;



}

