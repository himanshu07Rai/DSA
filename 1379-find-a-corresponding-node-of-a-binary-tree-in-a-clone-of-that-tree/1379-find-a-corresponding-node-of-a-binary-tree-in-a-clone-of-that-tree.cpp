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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> Q;
        Q.push(cloned);  
        TreeNode* current ;
        //while there is at least one discovered node
        while(!Q.empty()) {
            current = Q.front();
            Q.pop(); // removing the element at front
            //cout<<current->data<<" ";
            if(current->val==target->val)
               break;
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
        }
        return current;
    }
};