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
    void solve(vector<int> &temp,TreeNode* root,int target,vector<vector<int>> &ans)
    {
        if(!root)
            return ;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val==target)
            ans.push_back(temp);
        // temp.push_back(root->val);
        // if(root->left)
            solve(temp,root->left,target-root->val,ans);
        // if(root->right)
            solve(temp,root->right,target-root->val,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(temp,root,targetSum,ans);
        return ans;
        
    }
};