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
    int widthOfBinaryTree(TreeNode* root) {
         if (!root) return 0;

        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                auto nodePair = q.front(); q.pop();
                TreeNode* node = nodePair.first;
                unsigned long long currIndex = nodePair.second - minIndex; // Normalize index

                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                if (node->left) q.push({node->left, 2 * currIndex + 1});
                if (node->right) q.push({node->right, 2 * currIndex + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return static_cast<int>(maxWidth);
    }
};