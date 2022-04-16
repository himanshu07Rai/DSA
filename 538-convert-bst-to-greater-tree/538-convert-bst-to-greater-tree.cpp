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
    void check(TreeNode* root,int &t)
    {
        if(!root)
            return;
        
        if(root->right)
            check(root->right,t);
        
        t+=root->val;
        root->val = t;
        
        if(root->left)
            check(root->left,t);
    }
    TreeNode* convertBST(TreeNode* root) {
        int t = 0;
        check(root,t);
        return root;
    }
};