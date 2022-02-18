class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        int first = 0,
        second = 1;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr = first+second;
            first = second;
            second = curr;
        }
        return second;
    }
};