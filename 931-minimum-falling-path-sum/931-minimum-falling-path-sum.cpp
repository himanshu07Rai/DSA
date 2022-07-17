class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> x(m,0);
        for(int j = 0;j<m;j++)
            x[j] = matrix[0][j];
        for(int i=1;i<n;i++)
        {
            vector<int> y(m,0);
            for(int j=0;j<m;j++)
            {
                int u = matrix[i][j]+x[j];
                int l = INT_MAX,r = INT_MAX;
                if(j>0)
                    l = matrix[i][j]+x[j-1];
                if(j<m-1)
                    r = matrix[i][j]+x[j+1];
                y[j] = min(u,min(l,r));
            }
            x = y;
        }
        int ans = INT_MAX;
        for(int j = 0;j<m;j++)
            ans = min(ans,x[j]);
        
        return ans;
    }
};