#include <iostream>
#include <stack>
#include <queue>
using std::stack;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;



// Function to find the first non-repeating character in a string

char FirstNonRepeating(string st); 

int main () {
  string st; 
  cout << "Enter a string: ";
  cin >> st;
  cout << "The first non-repeating character is: " << FirstNonRepeating(st) << endl;
  return 0;
}



char FirstNonRepeating(string st) {
    queue<char> q;
    int n = st.length();  // Changed from 0
    bool flag = true;
    char t, v;
    
    for (char c : st) {
        q.push(c);
    }
    
    for (int i = 0; i < n; i++) {
        flag = true;  // Reset flag for each character
        t = q.front();
        q.pop();
        
        for (int j = 0; j < n-1; j++) {  // Fixed loop condition
            v = q.front();
            q.pop();
            q.push(v);
            if (v == t) {
                flag = false;
            }
        }
        q.push(t);
        
        if (flag) {  // If no repeats found
            return t;
        }
    }
    return '#';  // Added return for no non-repeating char
}
