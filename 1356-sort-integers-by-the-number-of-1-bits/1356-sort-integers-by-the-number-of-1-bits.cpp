class Solution {
public:
    static int getOnes(int n)
    {
        int c = 0;
        while(n)
        {
            c+=n%2;
            n = n/2;
        }
        return c;
    }
    static bool comp(int &a,int &b)
    {
        if(getOnes(a) != getOnes(b)){
            return getOnes(a) < getOnes(b);
        }
        else  return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};