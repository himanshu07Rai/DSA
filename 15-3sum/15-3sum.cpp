class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int j=0;j<n;j++)
        {
            //very imp to remove duplicates
            if(j>0 && nums[j]==nums[j-1])
                continue;
            

            int s=j+1,e=n-1;
            while(s<e)
            {
                if(nums[s]+nums[e]+nums[j] < 0)
                    s++;
                else if(nums[s]+nums[e]+nums[j] > 0)
                    e--;
                else
                {
                    // cout<<"nums[j] "<<nums[j]<<",nums[s] "<<nums[s]<<",nums[e] "<<nums[e]<<"\n";
                    ans.push_back({nums[j],nums[s],nums[e]});

                    int val=nums[s];
                    while(s<e && nums[s]==val)
                        s++;

                    val=nums[e];
                    while(e>s && nums[e]==val)
                        e--;
                }
            }
        }
        return ans;
    }
};