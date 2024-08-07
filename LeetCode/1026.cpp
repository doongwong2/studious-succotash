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
    using info = tuple<TreeNode*, int, int>;
    int ans = 0;
    void iterate(TreeNode* root)
    {
        vector<info> s;

        s.emplace_back(root, INT_MAX, INT_MIN);

        while (!s.empty())
        {
            auto [node, min_, max_] = s.back();
            s.pop_back();
            int x = node->val;
            min_ = min(x, min_);
            max_ = max(x, max_);
            ans = max({ ans, x - min_, max_ - x });

            if (node->right)
                s.emplace_back(node->right, min_, max_);
            if (node->left)
                s.emplace_back(node->left, min_, max_);
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        iterate(root);
        return ans;
    }
};
