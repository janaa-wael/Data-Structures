/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth1, depth2;
        if (root == NULL)
        {
            return true;
        }
        if (root->right != NULL)
            depth1 = maxDepth(root->right);
        else
            depth1 = 0;

        if (root->left != NULL)
            depth2 = maxDepth(root->left);
        else
            depth2 = 0;
        return (abs(depth1 - depth2) <= 1) && isBalanced(root->right) && isBalanced(root->left);

    }

    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->right) + 1, maxDepth(root->left) + 1);
    }
};