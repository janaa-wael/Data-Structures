class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal)
    {
        // If the node is null, it is valid
        if (node == nullptr) return true;

        // The current node's value must be within the range
        if (node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }

        // Recursively check the left and right subtrees with updated bounds
        return isValidBSTHelper(node->left, minVal, node->val) &&
            isValidBSTHelper(node->right, node->val, maxVal);
    }
};
