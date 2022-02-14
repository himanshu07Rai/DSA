#define ll long long

class Solution {
public:
    ll mergeSortedArrays(vector<int>&nums,ll l_start,ll l_end,ll r_start, ll r_end)
    {
        ll count=0, i=l_start,j=r_start,k=0;
        
        vector<int>temp(r_end-l_start+1,0);
        while(i<=l_end && j<=r_end)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++] = nums[i++];
            }else{
                count+=l_end-i+1;
                temp[k++] = nums[j++];
            }
        }
        while(i<=l_end)
            temp[k++] = nums[i++];
        
        while(j<=r_end)
            temp[k++] = nums[j++];
        
        for(int i=l_start,k=0;i<=r_end;)
            nums[i++] = temp[k++];
        
        return count;
    }
    ll mergeSort(vector<int>&nums,ll l,ll r)
    {
        if(l==r)
            return 0;
        int m = l+(r-l)/2;
        ll leftCount = mergeSort(nums,l,m);
        ll rightCount = mergeSort(nums,m+1,r);
        ll combinedCount = mergeSortedArrays(nums,l,m,m+1,r);
        return leftCount+rightCount+combinedCount;
        
    }
    bool isIdealPermutation(vector<int>& nums) {
        ll localCount = 0;
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                localCount++;
        }
        
        ll gCount = mergeSort(nums,0,n-1);
        
        return localCount==gCount;
        
        
        
    }
};