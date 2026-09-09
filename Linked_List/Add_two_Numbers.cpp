/*
    Problem: Add Two Numbers
    -----------------------------
    Given two non-empty linked lists representing two 
    non-negative integers, with digits stored in reverse 
    order (ones digit first), add the two numbers and 
    return the sum as a linked list in the same format.

    Example:
    Input:  l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    (342 + 465 = 807 -> reverse digits: [7,0,8])

    Input:  l1 = [9,9,9], l2 = [9,9]
    Output: [8,9,0,1]
    (999 + 99 = 1098 -> reverse digits: [8,9,0,1])
*/

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;   // naya carry
            int digit = sum % 10; // is position ka digit

            tail->next = new ListNode(digit);
            tail = tail->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        return dummy.next;
    }
};

// helper class: testing ke liye
class ListHelper {
public:
    static ListNode* buildList(int arr[], int n){
        if(n == 0) return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for(int i = 1; i < n; i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }

    static void printList(ListNode* head){
        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(){
    int arr1[] = {9,9,9};
    int arr2[] = {9,9};

    ListNode* l1 = ListHelper::buildList(arr1, 3);
    ListNode* l2 = ListHelper::buildList(arr2, 2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    ListHelper::printList(result); // 8 9 0 1

    return 0;
}