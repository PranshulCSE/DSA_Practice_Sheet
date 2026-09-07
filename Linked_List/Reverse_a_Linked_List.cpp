/*
    Problem: Reverse Linked List
    -----------------------------
    Given the head of a singly linked list, reverse the
    list and return the new head.

    Example:
    Input:  head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

    Input:  head = [1,2]
    Output: [2,1]

    Input:  head = []
    Output: []
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *next = curr->next; // agle node ko pehle save karo
            curr->next = prev;           // arrow palat do (peeche point karo)
            prev = curr;                 // prev ko aage khiskao
            curr = next;                 // curr ko bhi aage khiskao
        }

        return prev; // prev hi naya head hai
    }
};

// helper class: testing ke liye
class ListHelper
{
public:
    static ListNode *buildList(int arr[], int n)
    {
        if (n == 0)
            return NULL;
        ListNode *head = new ListNode(arr[0]);
        ListNode *curr = head;
        for (int i = 1; i < n; i++)
        {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }

    static void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = ListHelper::buildList(arr, 5);

    Solution sol;
    ListNode *reversed = sol.reverseList(head);

    ListHelper::printList(reversed); // 5 4 3 2 1

    return 0;
}