class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>> maxh;
        for(int i=0;i<points.size();i++)
        {
            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
                    
                    if(maxh.size()>K)
                    {
                        maxh.pop();
                    }
        }
        vector<vector<int>> ans;
        while(maxh.size()>0)
        {
            ans.push_back(points[maxh.top().second]);
            maxh.pop();
        }
        return ans;
    }
};