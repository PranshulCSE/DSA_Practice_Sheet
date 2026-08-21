/*
    Problem: Valid Parentheses
    -----------------------------
    Given a string s containing just the characters 
    '(', ')', '{', '}', '[' and ']', determine if the input 
    string is valid. Brackets must close in the correct 
    order (last opened, first closed).

    Example:
    Input:  s = "()[]{}"
    Output: true

    Input:  s = "(]"
    Output: false
    (mismatched bracket types)

    Input:  s = "([)]"
    Output: false
    (wrong closing order)

    Input:  s = "{[]}"
    Output: true
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    string s = "{[]}";

    stack<char> st;
    // closing -> matching opening
    unordered_map<char, char> matchPair = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for(char c : s){
        // agar opening bracket hai, push kar do
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        // warna ye closing bracket hai
        else {
            // stack empty hai -> koi opening hi nahi tha
            if(st.empty()){
                cout << "false" << endl;
                return 0;
            }

            // top check karo -> matching opening hai kya
            if(st.top() != matchPair[c]){
                cout << "false" << endl;
                return 0;
            }

            // match ho gaya, pop kar do
            st.pop();
        }
    }

    // agar stack empty hai to sab close ho gaya -> valid
    if(st.empty()){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}