/*
    Problem: Remove Outermost Parentheses
    -----------------------------
    Given a valid parentheses string s formed by concatenating 
    primitive valid parentheses strings, remove the outermost 
    parentheses of every primitive string and return the result.

    Example:
    Input:  s = "(()())(())"
    Output: "()()()"

    Input:  s = "(()())(())(()(()))"
    Output: "()()()()(())"

    Input:  s = "()()"
    Output: ""
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s = "(()())(())";
    string result = "";
    stack<char> st;

    for(char c : s){
        if(c == '('){
            // agar stack pehle se khali nahi hai, ye outermost nahi hai
            if(st.size() > 0){
                result += c;
            }
            st.push(c);
        } else { // c == ')'
            st.pop();
            // pop karne ke baad agar stack khali nahi hai, ye outermost nahi tha
            if(st.size() > 0){
                result += c;
            }
        }
    }

    cout << result << endl;
    return 0;
}