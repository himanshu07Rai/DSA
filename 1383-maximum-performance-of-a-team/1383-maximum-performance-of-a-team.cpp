class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>nums(n);
        priority_queue <int, vector<int>, greater<int>> q;
        long maxPerf = 0, sum = 0;

        for (int i = 0; i < n; i++)	{
            nums[i].first = efficiency[i];
            nums[i].second = speed[i];
        }
        sort(nums.rbegin(), nums.rend());
        // for(auto i:nums)
        // {
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }

        for (int i = 0; i < n; i++)	{
            sum += nums[i].second;
            q.push(nums[i].second);
            if(q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            long curr = sum *nums[i].first;
            // cout<<curr<<"\n";
            maxPerf = max(maxPerf, curr);
        }
        return maxPerf % MOD;
    }



};