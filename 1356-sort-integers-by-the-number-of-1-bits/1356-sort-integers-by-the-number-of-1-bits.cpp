class Solution {
public:
    // static unsigned int getOnes(int n)
    // {
    //     int c = 0;
    //     while(n)
    //     {
    //         c+=n%2;
    //         n>>1;
    //     }
    //     return c;
    // }
    static bool comp(int &a,int &b)
    {
        if(__builtin_popcount(a) < __builtin_popcount(b))
            return true;
        if(__builtin_popcount(a) == __builtin_popcount(b))
            return a<b;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};