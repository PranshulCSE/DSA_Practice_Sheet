/*
    Problem: Min Stack
    -----------------------------
    Design a stack that supports push, pop, top, and
    retrieving the minimum element in O(1) time.

    Example:
    push(-2), push(0), push(-3)
    getMin() -> -3
    pop()
    top()    -> 0
    getMin() -> -2
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> mainStack; // actual values
    stack<int> minStack;  // har point pe ka minimum

public:
    MinStack() {}

    void push(int val)
    {
        mainStack.push(val);

        // agar minStack khali hai, ya naya val chota/equal hai current min se
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        else
        {
            // warna purana minimum hi repeat kar do
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        mainStack.pop();
        minStack.pop(); // dono saath saath pop honge
    }

    int top()
    {
        return mainStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "getMin: " << minStack.getMin() << endl; // -3

    minStack.pop();

    cout << "top: " << minStack.top() << endl;       // 0
    cout << "getMin: " << minStack.getMin() << endl; // -2

    return 0;
}