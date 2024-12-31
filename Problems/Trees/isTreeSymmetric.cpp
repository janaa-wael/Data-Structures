class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is symmetric
        }
        // Call the helper function to compare the left and right subtrees
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both subtrees are null, so they are mirrors of each other
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // One of the subtrees is null, so they are not mirrors
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // The current nodes must have the same value,
        // and their subtrees must also be mirrors of each other
        return (left->val == right->val) &&
            isMirror(left->left, right->right) &&
            isMirror(left->right, right->left);
    }
};
