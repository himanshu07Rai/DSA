class Solution {
public:
    #define MOD 1000000007        //change the value if reqd.

    int findWays(vector<int> &num, int tar)
    {
        //You can get pretty suicidal if you fill up the vector with -1 instead of 0's.
        vector<int> cur(tar+1, 0), prev(tar+1, 0);

        if(num[0] == 0)    prev[0] = 2;
        else prev[0] = 1; 

        //if check is needed to prevent array index out of bounds
        if(num[0] != 0 and num[0] <= tar)
        {
            prev[num[0]] = 1;         
        }

        for(int index=1; index<num.size(); index++)
        {
            for(int sum=0; sum <= tar; sum++)
            {
                int way1=0, way2=0;

                //The if condition check is necessary to prevent array index out of bounds!
                if(num[index] <= sum)
                    way1 = prev[sum-num[index]];

                way2 = prev[sum];

                cur[sum] = (way1 + way2)% MOD; 
            }
            prev = cur;
        }

        return prev[tar]; 
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int total = 0;
        for(auto &it: arr)    total+=it;

        if(total - d < 0 or (total - d)%2)    return 0;

        return findWays(arr, (total-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
        
    }
        
};