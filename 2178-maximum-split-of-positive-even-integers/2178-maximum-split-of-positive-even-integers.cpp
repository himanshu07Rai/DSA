class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1)
            return {};
        vector<long long> ans;
        int i = 2;
        while(finalSum>=i)
        {
            ans.push_back(i);
            finalSum-=i;
            i+=2;
        }
        ans.back()+=finalSum;
        return ans;       
        
    }
};