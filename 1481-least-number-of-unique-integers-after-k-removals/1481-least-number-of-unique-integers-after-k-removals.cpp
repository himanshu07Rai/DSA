class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,long long> count;
        for(int i:arr)
        {
            count[i]++;
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        for(auto it=count.begin();it!=count.end();it++)
        {
            pq.push({it->second,it->first});
        }
        while(!pq.empty())
        {
            if(pq.top().first==k)
            {
                pq.pop();
                break;
            }else if(pq.top().first<k)
            {
                k-=pq.top().first;
                pq.pop();
            }else{
                break;
            }
        }
        return pq.size();
    }
};