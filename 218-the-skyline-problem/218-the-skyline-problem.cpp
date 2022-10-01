class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i <= buildings.size(); ++i) {
            while (!pq.empty() && (i == buildings.size() || pq.top().second < buildings[i][0])) {
                auto cur = pq.top(); pq.pop();
                while (!pq.empty() && pq.top().second <= cur.second)
                    pq.pop();
                res.push_back({cur.second, pq.empty() ? 0 : pq.top().first});
            }
            if (i < buildings.size()) {
                if (pq.empty() || buildings[i][2] > pq.top().first) {
                    if (!res.empty() && res.back()[0] == buildings[i][0]) 
                        res.back()[1] = buildings[i][2];
                    else
                        res.push_back({buildings[i][0], buildings[i][2]});
                }
                pq.push({buildings[i][2], buildings[i][1]});
            }
        }
        return res;
    }
};