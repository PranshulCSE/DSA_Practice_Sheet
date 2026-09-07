/*
    Problem: Merge Two Sorted Lists
    -----------------------------
    Given two sorted linked lists list1 and list2, merge
    them into one sorted linked list by splicing together
    the existing nodes.

    Example:
    Input:  list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Input:  list1 = [], list2 = []
    Output: []

    Input:  list1 = [], list2 = [0]
    Output: [0]
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // constructor
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);       // dummy node (value matter nahi karta)
        ListNode *tail = &dummy; // tail result list banata jayega

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;  // chhota wala jodo
                list1 = list1->next; // us list ko aage badhao
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // tail bhi aage badhao
        }

        // jo list bachi hai (already sorted), use seedha attach kar do
        if (list1 != NULL)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy.next; // actual merged list ka head
    }
};

// helper class: linked list build aur print karne ke liye (testing purpose)
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
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode *list1 = ListHelper::buildList(arr1, 3);
    ListNode *list2 = ListHelper::buildList(arr2, 3);

    Solution sol;
    ListNode *merged = sol.mergeTwoLists(list1, list2);

    ListHelper::printList(merged); // 1 1 2 3 4 4

    return 0;
}