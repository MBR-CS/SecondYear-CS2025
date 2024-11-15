#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;


//NOTE: create  function prototypes
void PrintStack(stack<int>& MyStack);
void InitStack(stack<int>& MyStack);
bool IsFound(stack<int> &MyStack, char element);
bool IsDisjoint(stack<int> &FirstStack,stack<int> &SecondStack);
//NOTE: create  function main to test the above functions
int main () {
  stack<int> FirstStack, SecondStack;
  InitStack(FirstStack);
  cout << "FirstStack is :";
  PrintStack(FirstStack);
  InitStack(SecondStack);
  cout << "SecondStack is :";
  PrintStack(SecondStack);
  if (IsDisjoint(FirstStack, SecondStack)) {
    cout << "disjoint Stacks" << endl;
  }else {
    cout << "Non-disjoint Stacks" << endl;
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

bool IsFound(stack<int> &MyStack, char element){
  stack<char> helper;
  bool status = false;
  while (!MyStack.empty()) {
    if (MyStack.top() == element) {
      status = true;
      break;
    }
    helper.push(MyStack.top());
    MyStack.pop();
  }
  while (!helper.empty()) {
    MyStack.push(helper.top());
    helper.pop();
  }
  return status;

}


bool IsDisjoint(stack<int> &FirstStack,stack<int> &SecondStack){
  while (!FirstStack.empty() && !SecondStack.empty()) {
    if (IsFound(SecondStack, FirstStack.top())) {
      return false;
    }
    FirstStack.pop();
  }
  return true;
}

