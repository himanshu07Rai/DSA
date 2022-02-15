class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())
            return findMedianSortedArrays(b,a);
        int l=0,h = a.size();
        int totalElements = b.size()+a.size();
        int leftEl = (totalElements+1)/2;
        while(l<=h)
        {
            int aleft = l+(h-l)/2;
            int bleft = leftEl - aleft;
            int l1 = aleft==0?INT_MIN:a[aleft-1];
            int l2 = bleft==0?INT_MIN:b[bleft-1];
            int r1 = aleft==a.size()?INT_MAX:a[aleft];
            int r2 = bleft==b.size()?INT_MAX:b[bleft];
            if(l1<=r2 && l2<=r1)
            {
                if(totalElements&1){
                    return max(l1,l2);
                }else{
                   double lMax = max(l1,l2),
                    rMin = min(r1,r2);
                    return (lMax+rMin)/2.0;
                }
            }
            else if(l1>r2)
            {
                h = aleft-1;
            }else{
                l = aleft+1;
            }
        }
        return 2.0;
    }
};