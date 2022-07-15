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
    TreeNode* helper(vector<int>& postorder, int low,int high,int &i,unordered_map<int,int>& um) {
        // if(low>high)return NULL;
        // int loc = um[postorder[r]];
        // TreeNode *temp = new TreeNode(postorder[r]);
        // r++;
        // temp->left = helper(postorder,low,loc-1,r,um);
        // temp->right = helper(postorder,loc+1,high,r,um);
        // return temp;
        if(low>high)
            return NULL;
        int loc = um[postorder[i]];
        TreeNode *temp= new TreeNode(postorder[i]);
        i--;
        
        temp->right=helper(postorder,loc+1,high,i,um); 
        temp->left=helper(postorder,low,loc-1,i,um);
        
        return temp;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> um;
        
        for(int i=0;i<n;i++)
            um[inorder[i]] = i;
        
        int i = n-1;
        int low = 0,high = n-1;
        return helper(postorder,low,high,i,um);
    }
};