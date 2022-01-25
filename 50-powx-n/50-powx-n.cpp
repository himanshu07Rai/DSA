class Solution {
public:
    double helper(double x, int n)
    {
        if(!n)
            return 1;
        if(n==1)
            return x;
        if(n&1)
            return x*helper(x*x,n/2);
        else return helper(x*x,n/2);
    }
    double myPow(double x, int n) {
        double ans = helper(x,n);
        return n<0?1/ans:ans;
    }
};