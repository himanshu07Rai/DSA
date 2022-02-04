class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        long long l=1,r=x,m;
        while(l<r)
        {
            m = l+(r-l)/2;
            if(m*m>x)
            {
                r = m;
            }
            else l = m+1;
        }
        return l-1;
    }
};