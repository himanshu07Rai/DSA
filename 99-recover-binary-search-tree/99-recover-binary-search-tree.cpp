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
    void inorder(TreeNode* root,vector<int> &v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void check(TreeNode* root,vector<int> &v,int &i){
        if(!root) return;
        check(root->left,v,i);
        if(v[i]!=root->val) swap(v[i],root->val);
        i++;
        check(root->right,v,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int i = 0;
        sort(v.begin(),v.end());
        check(root,v,i);
    }
};