class Solution {
public:
    bool isPossible(vector<int>&piles,int sp,int h)
    {
        int time = 0;
        for(int i=0;i<piles.size();i++)
        {
            time+=(piles[i]+sp-1)/sp;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int Max = -1;
        for(int i=0;i<n;i++)
            Max = max(Max,piles[i]);
        if(n==h)
            return Max;
        
        // cout<<Max<<"\n";
        int lo = 1,hi=Max,ans=INT_MAX;
        while(lo<=hi)
        {
            int sp = lo+(hi-lo)/2;
            if(isPossible(piles,sp,h))
            {
                ans = sp;
                hi = sp-1;
            }else{
                lo = sp+1;
            }
        }
        return ans;
    }
};