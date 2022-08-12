/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<=root->val && q->val>=root->val)
            return root;
        else if(p->val<=root->val && q->val<=root->val)
            return lowestCommonAncestor( root->left, p, q);
        else
            return lowestCommonAncestor( root->right, p, q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* l = p->val<q->val?p:q;
        TreeNode* r = p->val>q->val?p:q;
        return lca(root,l,r);
    }
};