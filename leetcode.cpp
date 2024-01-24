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
    int ans;
    vector<int> nums = { 0,0,0,0,0,0,0,0,0,0 };

    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root);

        return ans;
    }

    void dfs(TreeNode* root)
    {
        if (root == nullptr) return;

        nums[root->val]++;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (check()) ans++;
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
        nums[root->val]--;
    }

    bool check()
    {
        int odd = 0;
        for (int i = 1; i < 10; i++)
            if (nums[i] & 1)
                odd++;

        if (odd > 1) return false;

        return true;
    }
};