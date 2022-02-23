class Solution {
public:
    int countVowelStrings(int n) {
        return count(n,' ');
    }
    int count(int n,char last)
    {
        if(!n)
            return 1;
        int res = 0;
        int arr[]={'a','e','i','o','u'};
        for(int i=0;i<5;i++)
        {
            if(last<=arr[i])
            {
                res+=count(n-1,arr[i]);
            }
        }
        return res;
    }
};