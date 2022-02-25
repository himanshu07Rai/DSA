class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        vector<int> cur = intervals[0];
        for(int i=1;i<n;i++)
        {
            vector<int> interval = intervals[i];
            if(cur[1]<interval[0])
            {
                ans.push_back(cur);
                cur = interval;
            }
            else{
                cur[1] = max(cur[1],interval[1]);   
            }
        }
        ans.push_back(cur);
        return ans;
    }
};