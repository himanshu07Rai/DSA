class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>y(n,0);
        for(int j=0;j<n;j++)
            y[j] = triangle[n-1][j];
        
        for (int i = n - 2; i>= 0 ; i-- )
        {
            vector<int>x(n,0);
            for(int j = i; j >=0 ;  j-- )
            {
                x[j] = triangle[i][j] + min(y[j],y[j+1]);
            }
            y = x;
        }
            
        return y[0];
    }
};