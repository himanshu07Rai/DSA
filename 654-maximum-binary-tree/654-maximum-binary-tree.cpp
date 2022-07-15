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
    TreeNode* buildTree(vector<int>& nums,int low,int high, unordered_map<int,int> &um)
    {
        if(low>high)
            return NULL;
        int rootVal = *max_element(nums.begin()+low,nums.begin()+high+1);
        int loc = um[rootVal];
        TreeNode *temp = new TreeNode(rootVal);
        temp->left = buildTree(nums,low,loc-1,um);
        temp->right = buildTree(nums,loc+1,high,um);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            um[nums[i]] = i;
        }
        int i = 0,low=0,high=n-1;
        return buildTree(nums,low,high,um);
    }
};