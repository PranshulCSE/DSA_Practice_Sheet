/*
    Problem: Lowest Common Ancestor of a Binary Tree
    -----------------------------
    Given the root of a binary tree and two nodes p and q, 
    find their lowest common ancestor (the deepest node that 
    has both p and q as descendants, a node can be its own 
    ancestor).

    Example:
    Input:  root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3

    Input:  root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    (4 is in 5's subtree, so 5 itself is the LCA)
*/

#include <iostream>
#include <queue>
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        // base case: khaли tree, ya khud p/q mil gaya
        if(root == NULL || root == p || root == q){
            return root;
        }

        // left aur right subtrees mein recursively dhundो
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // dono taraf se signal mila -> current node hi LCA hai
        if(left != NULL && right != NULL){
            return root;
        }

        // sirf ek taraf se mila, usी ko upar bhej dो
        return (left != NULL) ? left : right;
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

    // ek specific value wala node dhundने ke liye (testing purpose)
    static TreeNode* findNode(TreeNode* root, int val){
        if(root == NULL) return NULL;
        if(root->val == val) return root;

        TreeNode* leftResult = findNode(root->left, val);
        if(leftResult != NULL) return leftResult;

        return findNode(root->right, val);
    }
};

int main(){
    // tree: [3,5,1,6,2,0,8,null,null,7,4]
    int arr[] = {3,5,1,6,2,0,8,-1,-1,-1,-1,7,4};
    TreeNode* root = TreeHelper::buildTree(arr, 13);

    TreeNode* p = TreeHelper::findNode(root, 5);
    TreeNode* q = TreeHelper::findNode(root, 1);

    Solution sol;
    TreeNode* result = sol.lowestCommonAncestor(root, p, q);

    cout << result->val << endl; // 3

    return 0;
}