class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = arr[m];
            cout<<val<<"\n";
            if(m>0 && val>arr[m-1] && val>arr[m+1])
                return m;
            else if(m>0 && val<arr[m-1])
                r=m-1;
            else l=m+1;
        }
        return 0;
    }
};