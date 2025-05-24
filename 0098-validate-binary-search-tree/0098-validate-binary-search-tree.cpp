class Solution {
public:
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if (!root) return true;

        if (!inorder(root->left, prev)) return false;

        if (prev && root->val <= prev->val) return false;

        prev = root;

        return inorder(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
};
