class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        unordered_map<int,int> um;
        um[0]=0;
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a==0)
                count+=um[0];
            else if(um[60-a])
                count+=um[60-a];
            um[a]++;
        }
        return count;
    }
};