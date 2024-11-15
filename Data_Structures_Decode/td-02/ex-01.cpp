#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;


//NOTE: create  function prototypes
void PrintStack(stack<char>& MyStack);
void InitStack(stack<char>& MyStack);
int OccurrencesEven(stack<int>& MyStack);
void RemoveAllOccurrences(stack<int>& MyStack, int x);

void SorteStack(stack<int>& MyStack);
int CountSubstring(stack<char>& MyStack);
//NOTE: create  function main to test the above functions
int main () {
  stack<char> MyStack;
  InitStack(MyStack);
  PrintStack(MyStack);
  cout << "The number of substrings is: " << CountSubstring(MyStack) << endl;

  return 0;
}

//NOTE: Core functions 
void PrintStack(stack<char>& MyStack){
  stack<char> temp;
    
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

void InitStack(stack<char> &MyStack){
  int size;
  char element;
  std::cout << "please enter the size of the stack: ";
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    std::cout << "please enter element " << i+1 << " :";
    std::cin >> element;
    MyStack.push(element);
  }
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

int CountSubstring(stack<char> &MyStack) {
    int counter = 0;
    char prev = '!'; 
    while (!MyStack.empty()) {
        char current = MyStack.top();
        if (current == 'b' && prev == 'e') {
            counter++;
        }
        prev = current;
        MyStack.pop();
    }
    return counter;
} 

//NOTE: create  function definitions for exercise 04: 

void SorteStack(stack<int> &MyStack){
  stack<int> helper; 
  int temp;

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


