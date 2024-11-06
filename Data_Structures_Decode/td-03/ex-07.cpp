#include <iostream>

#include <string>
using namespace std ;  
  

string ClearSpaces(string str, int &size);
bool IsPalindrome(string st);
int main () {
  string st;
  cout << "Enter a string: ";
  getline(cin, st);
  if (IsPalindrome(st)) {
    cout << "The string is palindrome" << endl;
  }else {
    cout << "The string is not palindrome!!" << endl;
  }

  return 0;
}

string ClearSpaces(string str, int &size){
  string newStr = "";
  for(char c : str){ 
    if (c != ' '){ 
      newStr += c;
      size++;
    }
  }
  return newStr;
}

bool IsPalindrome(string st){
  int size = 0;
  st = ClearSpaces(st, size);
  if (size < 2) 
    return false;
  for (int i = 1; i <= (size / 2) ; i++) {
     if (tolower(st[i-1]) != tolower(st[size-i])) 
        return false;
  }
  return true; 
}






