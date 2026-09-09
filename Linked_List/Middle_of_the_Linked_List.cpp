/*
    Problem: Middle of the Linked List
    -----------------------------
    Given the head of a singly linked list, return the 
    middle node. If there are two middle nodes, return the 
    second middle node.

    Example:
    Input:  head = [1,2,3,4,5]
    Output: [3,4,5]
    (middle node is 3)

    Input:  head = [1,2,3,4,5,6]
    Output: [4,5,6]
    (second middle node is 4)
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
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        // fast 2 step, slow 1 step -- jab fast end tak pahunche, slow middle pe hoga
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // middle node
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
    int arr[] = {1,2,3,4,5,6};
    ListNode* head = ListHelper::buildList(arr, 6);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    ListHelper::printList(mid); // 4 5 6

    return 0;
}