/*
    Problem: Find the K-Beauty of a Number
    -----------------------------
    Given integers num and k, treat num as a string. Count
    how many substrings of length k, when converted to a
    number, divide num evenly (and are non-zero).

    Example:
    Input:  num = 240, k = 2
    Output: 2
    ("24" divides 240, "40" divides 240)

    Input:  num = 430043, k = 2
    Output: 2
    ("43" divides 430043 twice; "00" skipped as it's zero)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 430043;
    int k = 2;

    string s = to_string(num); // number ko string banao
    int count = 0;

    // fixed size k ka window slide karo
    for (int i = 0; i <= (int)s.length() - k; i++)
    {
        string sub = s.substr(i, k); // window ka substring
        int subNum = stoi(sub);      // number mein convert karo

        if (subNum == 0)
            continue; // divide by zero avoid karo

        if (num % subNum == 0)
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}