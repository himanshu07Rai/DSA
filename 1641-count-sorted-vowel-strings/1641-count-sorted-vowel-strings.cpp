class Solution {
public:
    int countVowelStrings(int n) {
        map<pair<int,char>,int> dp;
        return count(n,' ',dp);
        
    }
    int count(int n,char last,map<pair<int,char>,int> &dp)
    {
        if(!n)
            return 1;
        if(dp[{n,last}])
            return dp[{n,last}];
        int res = 0;
        int arr[]={'a','e','i','o','u'};
        for(int i=0;i<5;i++)
        {
            if(last<=arr[i])
            {
                res+=count(n-1,arr[i],dp);
            }
        }
        return dp[{n,last}] = res;
    }
};