/*
    Problem: Minimum Add to Make Parentheses Valid
    -----------------------------
    Given a string s of '(' and ')', find the minimum number 
    of parentheses that must be inserted to make the string 
    valid (any position).

    Example:
    Input:  s = "())"
    Output: 1

    Input:  s = "((("
    Output: 3

    Input:  s = "()))(("
    Output: 4
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "()))((";

    int openCount = 0;   // kitne '(' abhi unmatched hain
    int additions = 0;   // kitne brackets add karne padenge

    for(char c : s){
        if(c == '('){
            openCount++;
        } else { // c == ')'
            if(openCount > 0){
                openCount--; // match mil gaya
            } else {
                additions++; // '(' missing hai, ek add karna padega
            }
        }
    }

    // jitne '(' bache reh gaye, utne ')' bhi chahiye honge
    additions += openCount;

    cout << additions << endl;
    return 0;
}