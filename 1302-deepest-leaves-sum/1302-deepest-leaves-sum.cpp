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
    // int getHeight(TreeNode* root)
    // {
    //     if(!root){
    //         return 0;
    //     }
    //     return std::max(getHeight(root->left),getHeight(root->right)) + 1;
    // }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> Q;
        int level_sum=0;
        Q.push(root);
        while(!Q.empty())
        {
            level_sum=0;
            int size = Q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                level_sum+=cur->val; 
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
            }            
        }
        return level_sum;
    }
};