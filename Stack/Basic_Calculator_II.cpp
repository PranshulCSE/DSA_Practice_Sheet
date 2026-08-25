/*
    Problem: Basic Calculator II
    -----------------------------
    Given a string s representing an expression with
    non-negative integers and operators +, -, *, / (with
    possible spaces), evaluate it following standard operator
    precedence (* and / before + and -). Integer division
    truncates toward zero.

    Example:
    Input:  s = "3+2*2"
    Output: 7

    Input:  s = " 3/2 "
    Output: 1

    Input:  s = " 3+5 / 2 "
    Output: 5
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s = "3+5 / 2";

    stack<int> st;
    int num = 0;
    char sign = '+'; // pehla "virtual" operator +

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isdigit(c))
        {
            num = num * 10 + (c - '0'); // multi-digit number banao
        }

        // agar operator hai YA ye last character hai, to pending number ko process karo
        if ((!isdigit(c) && c != ' ') || i == s.length() - 1)
        {
            if (sign == '+')
            {
                st.push(num);
            }
            else if (sign == '-')
            {
                st.push(-num);
            }
            else if (sign == '*')
            {
                int top = st.top();
                st.pop();
                st.push(top * num);
            }
            else if (sign == '/')
            {
                int top = st.top();
                st.pop();
                st.push(top / num);
            }

            sign = c; // naya operator record karo
            num = 0;  // number reset karo
        }
    }

    // stack ke saare numbers ka sum hi final answer hai
    int result = 0;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
    return 0;
}