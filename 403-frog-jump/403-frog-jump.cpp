class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> mp;
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            unordered_set<int> t;
            mp[stones[i]] = t;
        }
        mp[0].insert(0);
        for(int i=0;i<n;i++)
        {
            int stone = stones[i];
            for(int val:mp[stone])
            {
                if(mp.find(stone+val-1)!=mp.end())
                {
                    if(val-1>0)
                        mp[stone+val-1].insert(val-1);
                }
                if(mp.find(stone+val)!=mp.end())
                {
                    if(val>0)
                        mp[stone+val].insert(val);
                }
                if(mp.find(stone+val+1)!=mp.end())
                {
                    if(val+1>0)
                        mp[stone+val+1].insert(val+1);
                }
            }
        }
//         for(int i=0;i<n;i++)
//         {
//             int stone = stones[i];
//             cout<<"\n"<<i<<" "<<stone<<"\n";
            
//             for(int val:mp[stone])
//             {
//                 cout<<val<<" ";
//             }
//         }
        return !mp[stones[n-1]].empty();
    }
};