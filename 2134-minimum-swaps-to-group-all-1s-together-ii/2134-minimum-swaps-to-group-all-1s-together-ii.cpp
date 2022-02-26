class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int countOne = 0;
        for(int i=0;i<n;i++)
        {
            countOne+=arr[i]==1;
        }

        if(!countOne)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(arr[i]);
        }
        
        n*=2;

        int i=0,j=0,temp = 0,ans = INT_MAX,a,b;
        while(j<n)
        {
            temp+=arr[j]==0;
            if(j-i+1==countOne)
            {
                ans = min(ans,temp);

                temp -= arr[i]==0;
                i++;
            }
            j++;
        }
        return ans;
    }
};