#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;


//NOTE: create  function prototypes
void PrintStack(stack<int>& MyStack);
void InitStack(stack<int>& MyStack);

bool IsParenthesized(stack<char> &MyStack);

//NOTE: create  function main to test the above functions
int main () {

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










bool IsParenthesized(stack<char> &MyStack){

}
