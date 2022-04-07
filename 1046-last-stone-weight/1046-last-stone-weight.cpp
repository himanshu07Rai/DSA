class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxh;
        for(int i=0;i<n;i++)
            maxh.push(stones[i]);
        while(maxh.size()>=2)
        {
            int f = maxh.top();
            maxh.pop();
            int s = maxh.top();
            maxh.pop();
            int diff = f-s;
            if(diff)
            {
                maxh.push(diff);
            }
        }
        return maxh.empty()?0:maxh.top();
    }
};