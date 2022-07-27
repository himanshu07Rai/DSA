class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size()-1];
        vector<int> dp(lastDay+1); //size till the last travel day is enough 
        unordered_set<int> travel(days.begin(), days.end()); //store travel days in hashset

        dp[0] = 0;

        for(int i=1;i<=lastDay;i++)
        {
            if(!travel.count(i)) //if 'i' is not a travel day 
            {
                dp[i] = dp[i-1]; //cost till day 'i' would be same as previous day cost i.e 'i-1'
                continue;
            }
             //if 'i' is a travel day then we have 3 cases    
            dp[i] = costs[0] + dp[i-1]; //for single day ticket
            dp[i] = min(costs[1] + dp[max(i-7, 0)], dp[i]); //for 7 day ticket
            dp[i] = min(costs[2] + dp[max(i-30, 0)], dp[i]); //for 30 day ticket

        }
        return dp[lastDay]; //return min cost upto the last travel day
    }
    
};