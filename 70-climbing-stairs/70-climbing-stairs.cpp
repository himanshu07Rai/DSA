class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
        int first = 1,
        second = 2;
        int curr;
        for(int i=3;i<=n;i++)
        {
            curr = first+second;
            first = second;
            second = curr;
        }
        return second;
    }
};