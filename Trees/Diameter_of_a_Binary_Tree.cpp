/*
    Problem: Diameter of Binary Tree
    -----------------------------
    Given the root of a binary tree, return the length of 
    the diameter (longest path between any two nodes, in 
    number of edges). The path may or may not pass through 
    the root.

    Example:
    Input:  root = [1,2,3,4,5]
    Output: 3
    (longest path: 4->2->1->3, or 4->2->5, both 3 edges)

    Input:  root = [1,2]
    Output: 1
*/

#include <iostream>
#include <queue>
#include <algorithm>
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
    int diameter = 0; // global max track karne ke liye

    // ye function normal height return karta hai, lekin side mein diameter bhi update karta hai
    int height(TreeNode* node){
        if(node == NULL) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // is node se guzarne wala path check karo
        diameter = max(diameter, leftHeight + rightHeight);

        // normal height return karo (jaise Max Depth mein karte hain)
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root){
        diameter = 0; // reset (agar object reuse ho raha ho)
        height(root); // ye call karne se diameter side-effect se update ho jayega
        return diameter;
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
    // tree: [1,2,3,4,5]
    int arr[] = {1,2,3,4,5};
    TreeNode* root = TreeHelper::buildTree(arr, 5);

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);

    cout << result << endl; // 3

    return 0;
}