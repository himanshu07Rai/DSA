class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int t = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }

        for(int i=0;i<matrix.size();i++)
        {
            int l = 0,r=m-1;
            while(l<r){
                int t = matrix[i][l];
                matrix[i][l]=matrix[i][r];
                matrix[i][r]=t;
                l++;
                r--;
            }
            
        }
        
        // return matrix;
    }
};