class Solution {
public:
    int arrangeCoins(int n) {
        int l=1,r=n,ans;
        while(l<=r)
        {
            long long row = l+(r-l)/2;
            long long coins = row*(row+1)/2;
            if(coins<=n)
                l=row+1,ans=row;
            else r=row-1;
        }
        return ans;
    }
};