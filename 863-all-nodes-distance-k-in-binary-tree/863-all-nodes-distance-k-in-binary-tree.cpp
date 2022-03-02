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
    void createGraph(TreeNode *root,unordered_map<int,vector<int>> &graph)
    {
        if(!root)
            return;
        int val = root->val;
        if(root->left){
             graph[root->left->val].push_back(root->val);
             graph[root->val].push_back(root->left->val);
            createGraph(root->left,graph);
        }
        if(root->right){
            graph[root->right->val].push_back(root->val);
            graph[root->val].push_back(root->right->val);
                     createGraph(root->right,graph);
        }
        /*
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* current = q.front();
                q.pop();
                if(current->left) {
                    graph[current->left->val].push_back(current->val);
                    graph[current->val].push_back(current->left->val);
                    q.push(current->left);
                }
                if(current->right) {
                    graph[current->right->val].push_back(current->val);
                    graph[current->val].push_back(current->right->val);
                    q.push(current->right);
                }
            }
        }
        */
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!k)
            return {target->val};
        unordered_map<int,vector<int>> graph;
        createGraph(root,graph);
        unordered_map<int,bool> visited;
        vector<int> res;
        queue<int> q;
        int level = 0;
        
        //push the target to start bfs with
        q.push(target->val);
        
        //bfs
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                int curr = q.front();
                q.pop();
                visited[curr]=true;
                
                for(int x : graph[curr])
                    if(!visited[x])
                        q.push(x);
            }
            //we reached the Kth layer, push the layer in res vector and break bfs
            if(++level==k){
                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }       
        }
        return res;       
    }
};