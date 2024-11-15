#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;


//NOTE: create  function prototypes
template <typename T>
void PrintStack(stack<T>& MyStack);

template <typename T>
void InitStack(stack<T>& MyStack);

template <typename T>
int OccurrencesEven(stack<T>& MyStack);

template <typename T>
void RemoveAllOccurrences(stack<T>& MyStack, T x);

template <typename T>
void SorteStack(stack<T>& MyStack);

template <typename T>
int CountSubstring(stack<T>& MyStack);

//NOTE: create  function main to test the above functions
int main () {
    stack<char> MyCharStack;
    InitStack(MyCharStack);
    PrintStack(MyCharStack);
    cout << "The number of substrings 'be' is: " << CountSubstring(MyCharStack) << endl;

    stack<int> MyIntStack;
    InitStack(MyIntStack);
    cout << "Number of even elements: " << OccurrencesEven(MyIntStack) << endl;
    cout << "Enter the element you want to remove: ";
    int element;
    cin >> element;
    RemoveAllOccurrences(MyIntStack, element);
    cout << "After removing : ";
    PrintStack(MyIntStack);
    SorteStack(MyIntStack);
    cout << "Sorted stack: ";
    PrintStack(MyIntStack);

  return 0;
}

//NOTE: Core functions 
template <typename T>
void PrintStack(stack<T>& MyStack){
  stack<T> temp;
    
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

template <typename T>
void InitStack(stack<T> &MyStack){
  int size;
  T element;
  std::cout << "please enter the size of the stack: ";
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    std::cout << "please enter element " << i+1 << " :";
    std::cin >> element;
    MyStack.push(element);
  }
}


//NOTE: create  function definitions for exercise 01
template <typename T>
int OccurrencesEven(stack<T> &MyStack){
  stack<T> helper;
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
template <typename T>
void RemoveAllOccurrences(stack<T> &MyStack, T  x){
  stack<T> helper;
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

template <typename T>
int CountSubstring(stack<T> &MyStack) {
    int counter = 0;
    T prev = '!'; 
    while (!MyStack.empty()) {
        T current = MyStack.top();
        if (current == 'b' && prev == 'e') {
            counter++;
        }
        prev = current;
        MyStack.pop();
    }
    return counter;
} 

//NOTE: create  function definitions for exercise 04: 
template <typename T>

void SorteStack(stack<T> &MyStack){
  stack<T> helper; 
  T temp;

  while (!MyStack.empty()) {
    temp = MyStack.top();
    MyStack.pop();
    while (!helper.empty() && temp < helper.top()) {
        MyStack.push(helper.top());
        helper.pop();
    }
    helper.push(temp);
  }

  while (!helper.empty()) {
    MyStack.push(helper.top());
    helper.pop();
  }

} 


