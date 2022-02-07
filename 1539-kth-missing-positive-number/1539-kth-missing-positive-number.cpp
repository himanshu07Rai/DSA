class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
       int l=0,r=A.size()-1;
       int m;
       while (l <= r) {
            m=l+(r-l)/2;
           
           // cout<<A[m]<<"\n";
            if (A[m] - (1 + m) < k)
                l = m + 1;
            else
                r = m-1;
        }
        return l + k;
    }
};