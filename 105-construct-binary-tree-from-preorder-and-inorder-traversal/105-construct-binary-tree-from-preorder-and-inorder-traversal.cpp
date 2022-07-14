class Solution {
public:
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int low,int high,int& i,unordered_map<int,int>& um){
        if(low>high)
            return NULL;
        int loc = um[preorder[i]];
        TreeNode *temp= new TreeNode(preorder[i]);
        i++;
        temp->left=helper(preorder,inorder,low,loc-1,i,um); 
        temp->right=helper(preorder,inorder,loc+1,high,i,um);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            um[inorder[i]]=i;
        
        if(n==0)
            return NULL;
        int i =0;
        
        return helper(preorder,inorder,0,preorder.size()-1,i,um); 
    }
};