/*
    Problem: Binary Tree Level Order Traversal
    -----------------------------
    Given the root of a binary tree, return the level order
    traversal of its nodes' values (top to bottom, left to
    right per level, grouped by level).

    Example:
    Input:  root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

    Input:  root = [1]
    Output: [[1]]

    Input:  root = []
    Output: []
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size(); // is level ke exact nodes count
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                // children ko queue mein daालो (agले level ke liye)
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }

            result.push_back(currentLevel);
        }

        return result;
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
    // tree: [3,9,20,null,null,15,7]
    int arr[] = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = TreeHelper::buildTree(arr, 7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    for (auto &level : result)
    {
        cout << "[ ";
        for (int val : level)
            cout << val << " ";
        cout << "]" << endl;
    }

    return 0;
}