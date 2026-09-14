/*
    Problem: Validate Binary Search Tree
    -----------------------------
    Given the root of a binary tree, determine if it is a 
    valid BST. A valid BST requires that for EVERY node, all 
    values in its left subtree are smaller and all values in 
    its right subtree are larger (not just immediate children).

    Example:
    Input:  root = [2,1,3]
    Output: true

    Input:  root = [5,1,4,null,null,3,6]
    Output: false
    (node 4's right subtree has 3, which violates BST property 
    when considering the whole tree, not just immediate parent)
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    // har node ke liye allowed range (minVal, maxVal) — exclusive dono taraf se
    bool validate(TreeNode* node, long minVal, long maxVal){
        if(node == NULL) return true; // empty subtree valid hai

        // range violate ho gaya
        if(node->val <= minVal || node->val >= maxVal) return false;

        // left subtree: max ab current node ki value ban gaya
        // right subtree: min ab current node ki value ban gaya
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root){
        // shuru mein range -infinity se +infinity tak hai
        return validate(root, LONG_MIN, LONG_MAX);
    }
};

// helper class: testing ke liye
class TreeHelper {
public:
    static TreeNode* buildTree(int arr[], int n){
        if(n == 0 || arr[0] == -1) return NULL;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() && i < n){
            TreeNode* curr = q.front();
            q.pop();

            if(i < n && arr[i] != -1){
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;

            if(i < n && arr[i] != -1){
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

int main(){
    // tree: [5,1,4,null,null,3,6]
    int arr[] = {5,1,4,-1,-1,3,6};
    TreeNode* root = TreeHelper::buildTree(arr, 7);

    Solution sol;
    bool result = sol.isValidBST(root);

    cout << (result ? "true" : "false") << endl; // false

    return 0;
}