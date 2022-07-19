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
        int res =  getReverse(x);
        return x>=0 && x ==res;
    }
};