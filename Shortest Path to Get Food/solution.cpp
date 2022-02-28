class Solution {
public:
    /**
     * @param targetMap: 
     * @return: nothing
     */
    int shortestPath(vector<vector<int>> &targetMap) {
        // Write your code here
        int n = targetMap.size(),m = targetMap[0].size();
        queue<int> q;
        q.push(0);
        vector<vector<int>> dir = {
            {0,-1},
            {-1,0},
            {0,1},
            {1,0}
        };
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int t = q.front();
                q.pop();
                int i = t/100;
                int j = t%100;
                if(targetMap[i][j]==2)
                    return step;
                for(auto d:dir)
                {
                    int new_i = i+d[0],new_j = j+d[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && targetMap[new_i][new_j]!=1)
                    {
                        q.push(new_i*100+new_j);
                        if(targetMap[new_i][new_j]!=2)
                            targetMap[new_i][new_j]=1;  // visited
                    }

                }
            }
            step++;
        }
        return -1;
    }
};