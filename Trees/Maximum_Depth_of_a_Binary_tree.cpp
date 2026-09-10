/*
    Problem: Maximum Depth of Binary Tree
    -----------------------------
    Given the root of a binary tree, return its maximum
    depth (the number of nodes along the longest path from
    root to the farthest leaf node).

    Example:
    Input:  root = [3,9,20,null,null,15,7]
    Output: 3

    Input:  root = [1,null,2]
    Output: 2

    Input:  root = []
    Output: 0
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // base case: khaли tree/subtree ki depth 0 hai
        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);   // left subtree ki depth
        int rightDepth = maxDepth(root->right); // right subtree ki depth

        // khud ke liye +1, jo bada hai us taraf ko count karo
        return 1 + max(leftDepth, rightDepth);
    }
};

// helper class: testing ke liye
class TreeHelper
{
public:
    static TreeNode *buildTree(int arr[], int n)
    {
        if (n == 0 || arr[0] == -1)
            return NULL;

        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < n)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (i < n && arr[i] != -1)
            {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;

            if (i < n && arr[i] != -1)
            {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

int main()
{
    // tree: [3,9,20,null,null,15,7]  (-1 represents null)
    int arr[] = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = TreeHelper::buildTree(arr, 7);

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << depth << endl; // 3

    return 0;
}