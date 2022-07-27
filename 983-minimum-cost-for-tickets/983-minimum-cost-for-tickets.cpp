class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        int lastDay = days[n-1];
        vector<int> dp(lastDay+1);
        dp[0] = 0;
        unordered_set<int> travelDays(days.begin(),days.end());
        for(int i=1;i<=lastDay;i++)
        {
            if(travelDays.count(i)==0)
            {
                dp[i]=dp[i-1];
                continue;
            }
            dp[i] = dp[i-1]+costs[0];
            int j = max(0,i-7);
            dp[i] = min(dp[i],costs[1]+dp[j]);
            j = max(0,i-30);
            dp[i] = min(dp[i],costs[2]+dp[j]);
        }
        
        return dp[lastDay];
    }
    
};