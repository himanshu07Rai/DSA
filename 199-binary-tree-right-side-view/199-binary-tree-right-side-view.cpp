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
    void solve(TreeNode* root,int num,vector<int>&ans)
    {
        if(!root)
            return;
        if(num==ans.size())
            ans.push_back(root->val);
        solve(root->right,num+1,ans);
        solve(root->left,num+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int num = 0;
        solve(root,num,ans);
        return ans;
    }
};