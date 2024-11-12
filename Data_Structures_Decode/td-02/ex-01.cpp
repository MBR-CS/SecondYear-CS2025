#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;


//NOTE: create  function prototypes
void PrintStack(stack<int>& MyStack);
stack<int> InitStack(int size);
int OccurrencesEven(stack<int>& MyStack);
void RemoveAllOccurrences(stack<int>& MyStack, int x);


//NOTE: create  function main to test the above functions
int main () {
  stack<int> P;
  int size;
  int x;

  std::cout << "please enter the size of the stack: ";
  std::cin >> size;
  P = InitStack(size);
  std::cout << "the stack is :";
  PrintStack(P);
  std::cout << "the number of even elements in the stack is : " << OccurrencesEven(P) << std::endl;
  /**/
  std::cout << "please enter the element you want to remove from the stack: ";
  std::cin >> x;
  RemoveAllOccurrences(P, x);
  std::cout << "the stack after removing all occurrences of " << x << " is :";
  PrintStack(P);

  return 0;
}

//NOTE: Core functions 
void PrintStack(stack<int>& MyStack){
  stack<int> helper;
  int size = MyStack.size();
  for (int i = 0; i < size; i++) {
    helper.push(MyStack.top());
    MyStack.pop();
  }
  for (int i = 0; i < size; i++) {
    std::cout << helper.top() << " ";
    MyStack.push(helper.top());
    helper.pop();
}
 std::cout << std::endl;
} 

stack<int> InitStack(int size){
  stack<int> MyStack;
  int element;
  for (int i = 0; i < size; i++) {
    std::cout << "please enter element " << i+1 << " :";
    std::cin >> element;
    MyStack.push(element);
  }
  return MyStack;
}


//NOTE: create  function definitions for exercise 01
int OccurrencesEven(stack<int> &MyStack){
  stack<int> helper;
  int counter = 0 , size = MyStack.size();
  for (int i = 0; i < size; i++) {
    if (MyStack.top() % 2 == 0) {
       counter++;
    } 
    helper.push(MyStack.top());
    MyStack.pop();
  }
  for (int i = 0; i < size; i++) {
    MyStack.push(helper.top());
    helper.pop();
  }
  return counter;
}



//NOTE: create  function definitions for exercise 02:

void RemoveAllOccurrences(stack<int> &MyStack, int x){
  stack<int> helper;
  int size = MyStack.size();
  for (int  i = 0; i < size; i++) {
    if (MyStack.top() != x) {
      helper.push(MyStack.top());
    }
    MyStack.pop();
  }
  size = helper.size();
  for (int  i = 0; i < size; i++) {
    MyStack.push(helper.top());
    helper.pop();
  }  
}



//NOTE: create  function definitions for exercise 03: 









//NOTE: create  function definitions for exercise 04: 






