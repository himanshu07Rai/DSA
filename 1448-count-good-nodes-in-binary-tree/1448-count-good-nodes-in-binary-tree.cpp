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
    void dfs(TreeNode* root,int num,int &ans)
    {
        if(!root)
            return;
        if(root->val>=num)
            ans++;
        num = max(num,root->val);
        dfs(root->left,num,ans);
        dfs(root->right,num,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 1
            ,num = root->val;
        dfs(root->left,num,ans);
        dfs(root->right,num,ans);
        return ans;
    }
};