class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows = bank.size();
        int ans = 0;
        int prev = 0;
        for(auto i:bank)
        {
            int count = 0;
            for(auto j:i)
            {
                if(j=='1')
                    count++;
            }
            ans+=count*prev;
            if(count>0)
                prev = count;
        }
        return ans;        
    }
};