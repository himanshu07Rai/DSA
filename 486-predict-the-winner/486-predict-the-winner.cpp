class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2==0)return true;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++){
                if(!g)
                    dp[i][j] = nums[i];
                else if(g==1){
                    dp[i][j] = max(nums[i],nums[j]);
                }else{
                    int v1 = nums[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int v2 = nums[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j] = max(v1,v2);
                }
            }
        }
        
        
        
        int sum = 0;
        for(int i:nums)
            sum+=i;
        // cout<<dp[0][n-1];
        return dp[0][n-1]*2>=sum;
    }
};