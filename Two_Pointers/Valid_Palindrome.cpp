/*
    Problem: Valid Palindrome
    -----------------------------
    Given a string s, return true if it is a palindrome,
    considering only alphanumeric characters and ignoring
    case (uppercase/lowercase treated as same).

    Example:
    Input:  s = "A man, a plan, a canal: Panama"
    Output: true
    (cleaned lowercase alphanumeric = "amanaplanacanalpanama")

    Input:  s = "race a car"
    Output: false
    (cleaned = "raceacar" -> not a palindrome)

    Input:  s = " "
    Output: true
    (no alphanumeric characters -> considered palindrome)
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s = "A man, a plan, a canal: Panama";

    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // agar left wala character alphanumeric nahi hai, skip karo
        if (!isalnum(s[left]))
        {
            left++;
            continue;
        }
        // agar right wala character alphanumeric nahi hai, skip karo
        if (!isalnum(s[right]))
        {
            right--;
            continue;
        }

        // dono valid hain, ab lowercase karke compare karo
        if (tolower(s[left]) != tolower(s[right]))
        {
            cout << "false" << endl;
            return 0;
        }

        // match ho gaya, andar badho
        left++;
        right--;
    }

    cout << "true" << endl;
    return 0;
}