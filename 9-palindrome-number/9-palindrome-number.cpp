class Solution {
public:
    int getReverse(int &x)
    {
        int t = x;
        long long res = 0;
        while(t)
        {
            res = res*10+t%10;
            t/=10;
        }
        return res;
    }
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0))
            return false;
        int res =  getReverse(x);
        return x==res;
    }
};