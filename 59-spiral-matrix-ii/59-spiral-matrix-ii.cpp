class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int top = 0,left=0,bottom=n-1,right=n-1;
        int c = 0,k=1;
        // cout<<top<<" "<<bottom<<" "<<left<<" "<<right;
        while(top<=bottom && left<=right)
        {
            // cout<<c<<" ";
            if(c==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans[top][i] = k++;
                    // cout<<k<<" ";
                }
                top++;
            }
            else if(c==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans[i][right] = k++;
                    // cout<<k<<" ";
                }
                right--;
            }
            else if(c==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i] = k++;
                }
                bottom--;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left] = k++;
                    // cout<<k<<" ";
                }
                left++;
            }
            c = (++c)%4;
        }
        return ans;
    }
};