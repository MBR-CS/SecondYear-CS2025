#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//NOTE: create  function prototypes
bool IsParenthesized(string MyExpression);
//NOTE: create  function main to test the above functions
int main () {
  // create array of stirng for test 
  string expressions[] = {
    "[([])]([()()])",
    "[([()))])",
    "[([(])[)(])]",
    ")))]]","(([]"
  };
  for (string expression : expressions) {
    cout << "The expression " << expression << " is " << (IsParenthesized(expression) ? "well parenthesized" : "bad parenthesized") << endl;
  }
  return 0;
}

bool IsParenthesized(string MyExpression) {
  stack<char> MyStack;
  for (char c : MyExpression) {
    if (c == ')' || c == ']') {
        if (MyStack.empty()) {
            return false;
        }else {
              if ((MyStack.top() == '(' and c == ')') || (MyStack.top() == '[' and c == ']')) {
                MyStack.pop(); 
              }else {
                return false;
              }
        }
    }else if (c == '(' || c == '[') {
      MyStack.push(c);
    }
  }
  return MyStack.empty();
}
