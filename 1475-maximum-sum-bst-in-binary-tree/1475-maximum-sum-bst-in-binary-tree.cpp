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
class Nodevalue {
public:
    int maxNode, minNode, sum;
    Nodevalue(int maxNode, int minNode, int sum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
    int maxSum = 0;

    Nodevalue BSThelp(TreeNode* root) {
        if (!root) {
            // For null nodes, return INT_MAX for min and INT_MIN for max to allow valid comparison
            return Nodevalue(INT_MIN, INT_MAX, 0);
        }

        auto left = BSThelp(root->left);
        auto right = BSThelp(root->right);

        // Check if current subtree is a valid BST
        if (left.maxNode < root->val && root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return Nodevalue(
                max(root->val, right.maxNode),
                min(root->val, left.minNode),
                currSum
            );
        }

        // Invalid BST subtree: return such that parent knows it’s invalid
        return Nodevalue(INT_MAX, INT_MIN, max(left.sum, right.sum));
    }

public:
    int maxSumBST(TreeNode* root) {
        BSThelp(root);
        return maxSum;
    }
};
