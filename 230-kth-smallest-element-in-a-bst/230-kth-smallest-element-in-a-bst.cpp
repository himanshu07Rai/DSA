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
    void check(TreeNode* root,vector<int>& v,int k)
    {
        if(!root)
            return ;        
        check(root->left,v,k);
        v.push_back(root->val);
        if(v.size()==k)
            return;
        check(root->right,v,k);
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int>v;
        check(root,v,k);
        return v[k-1];
    }
};