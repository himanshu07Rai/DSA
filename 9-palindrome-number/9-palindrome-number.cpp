class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long n = 0;
        int t = x;
        while(t)
        {
            n=n*10+t%10;
            // cout<<n<<" "<<x<<"\n";
            // if(n==x)
            //     return true;
            // if(n>INT_MAX/10 || n<INT_MIN/10)
            //     return false;
            t=t/10;
        }
        
        return n==x;
    }
};