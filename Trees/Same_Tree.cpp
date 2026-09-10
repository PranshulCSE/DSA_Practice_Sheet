/*
    Problem: Same Tree
    -----------------------------
    Given the roots of two binary trees p and q, check if
    they are structurally identical and the nodes have the
    same values.

    Example:
    Input:  p = [1,2,3], q = [1,2,3]
    Output: true

    Input:  p = [1,2], q = [1,null,2]
    Output: false
    (different structure)

    Input:  p = [1,2,1], q = [1,1,2]
    Output: false
    (same structure, different values)
*/

#include <iostream>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // dono null hain -> same (empty trees)
        if (p == NULL && q == NULL)
            return true;

        // sirf ek null hai -> structure mismatch
        if (p == NULL || q == NULL)
            return false;

        // values mismatch
        if (p->val != q->val)
            return false;

        // recursively left aur right dono check karo
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// helper class: testing ke liye (level-order se tree banate hain, null ke liye INT_MIN use karenge as marker)
class TreeHelper
{
public:
    // array se tree banao (level order, -1 matlab NULL node)
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

            // left child
            if (i < n && arr[i] != -1)
            {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;

            // right child
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
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};

    TreeNode *p = TreeHelper::buildTree(arr1, 3);
    TreeNode *q = TreeHelper::buildTree(arr2, 3);

    Solution sol;
    bool result = sol.isSameTree(p, q);

    cout << (result ? "true" : "false") << endl; // true

    return 0;
}