/*
    Problem: Reorder List
    -----------------------------
    Given the head of a singly linked list L0->L1->...->Ln, 
    reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
    Must be done in-place (re-link nodes, don't swap values).

    Example:
    Input:  head = [1,2,3,4]
    Output: [1,4,2,3]

    Input:  head = [1,2,3,4,5]
    Output: [1,5,2,4,3]
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
    void reorderList(ListNode* head){
        if(head == NULL || head->next == NULL) return;

        // ---- Step 1: Middle dhundo (Fast-Slow pointer) ----
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // ---- Step 2: Doosрे half ko reverse karo ----
        ListNode* secondHead = slow->next;
        slow->next = NULL; // pehला half ko yahin todo

        ListNode* prev = NULL;
        ListNode* curr = secondHead;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondHead = prev; // ab ye reversed doosрे half ka head hai

        // ---- Step 3: Dono halves ko alternate karके merge karo ----
        ListNode* first = head;
        ListNode* second = secondHead;

        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;   // pehले se doosрे ko jodo
            second->next = temp1;   // doosрे se pehले ke agले ko jodo

            first = temp1;
            second = temp2;
        }
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
    int arr[] = {1,2,3,4,5};
    ListNode* head = ListHelper::buildList(arr, 5);

    Solution sol;
    sol.reorderList(head);

    ListHelper::printList(head); // 1 5 2 4 3

    return 0;
}