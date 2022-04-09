class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min;
        for(auto it = m.begin();it!=m.end();it++)
        {
            min.push({it->second,it->first});
            if(min.size()>k)
                min.pop();
        }
        vector<int> ans;
        while(min.size())
        {
            ans.push_back(min.top().second);
            min.pop();
        }
        return ans;
    }
};