class Solution {
public:
   TreeNode* helper(vector<int>& preorder,int low,int high,int &r,unordered_map<int,int>& um){
        if(low>high)
            return NULL;
        int loc = um[preorder[r]];
        TreeNode *temp= new TreeNode(preorder[r]);
        r++;
        temp->left=helper(preorder,low,loc-1,r,um); 
        temp->right=helper(preorder,loc+1,high,r,um);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            um[inorder[i]]=i;
        
        if(n==0)
            return NULL;
        
        int i = 0;
        int low = 0,high = n-1;
        return helper(preorder,low,high,i,um);
    }
};