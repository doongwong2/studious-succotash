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
    int ret = 0;

    int dfs(TreeNode* root)
    {
        if (nullptr == root) return 0;

        int leftd = dfs(root->left);
        int rightd = dfs(root->right);

        ret = max(ret, leftd + rightd);

        return max(leftd, rightd) + 1;

    }


    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
