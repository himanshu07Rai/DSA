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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(!root)
            return ans;
        q.push(root);
        q.push(NULL);
        int val = INT_MIN;
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            if(f)
            {
                val = max(val,f->val);
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }else{
                ans.push_back(val);
                if(!q.empty())
                {
                    val = INT_MIN;
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
    
};