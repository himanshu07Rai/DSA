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
    void dfs(TreeNode* root,TreeNode* dummy)
    {
        if(!root)
            return;
        TreeNode *temp = new TreeNode(root->val);
        dummy->right = temp;
        dummy->left=NULL;
        dummy = dummy->right;
        dfs(root->left,dummy);
        dfs(root->right,dummy);
    }
    void flatten(TreeNode* root) {
       if(!root)
           return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            if(!st.empty())
                curr->right = st.top();
            curr->left = NULL;
        }
    }
};