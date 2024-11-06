#include <iostream>

#include <string>
using namespace std ;  
  

string ClearSpaces(string str, int &size);
bool IsPalindrome(string st ,int size, int start , int end);
int main () {
  int size = 0;
  string st = "";
  cout << "Enter a string: ";
  getline(cin, st);
  st = ClearSpaces(st, size);
  if (IsPalindrome(st, size, 0, size - 1)) {
    cout << "The string is a palindrome" << endl;
  }else {
    cout << "The string is not a palindrome" << endl;
  }

  

  return 0;
}

string ClearSpaces(string str, int &size){
  string newStr = "";
  for(char c : str){ 
    if (c != ' '){ 
      newStr += tolower(c);
      size++;
    }
  }
  return newStr;
}

bool IsPalindrome(string st ,int size, int start , int end){
  if (size < 2) 
    return false;
  
  if (start >= (size / 2) ) 
    return true;

  if (st[start] != st[end]) 
    return false;
  return IsPalindrome(st, size, start + 1, end - 1); 
}






