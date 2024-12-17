#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;

// NOTE: create  function prototypes
void PrintStack(stack<int>& MyStack);
void InitStack(stack<int> &MyStack);

void ReverseStackOnly(stack<int>&MyStack);
int main () {
  stack<int> MyStack;
  InitStack(MyStack);
  std::cout << "The Stack is: ";
  PrintStack(MyStack);
  ReverseStackOnly(MyStack);
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



void ReverseStackOnly(stack<int>&MyStack){

int temp , size = MyStack.size(),  counter = 0;
stack<int> helper;

for (int i = 0; i < size; i++) {
    temp = MyStack.top();
    MyStack.pop();
    while (!helper.empty()) {
      MyStack.push(helper.top());
      helper.pop();
    }
    helper.push(temp);
    for (int i = 0; i < counter; i++) {
      helper.push(MyStack.top());
      MyStack.pop();
    }
    counter++;
}
while (!helper.empty()) {
  MyStack.push(helper.top());
    helper.pop() ;
}
}

