class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        int i=0,j=n-1;
        while(i<n-1 && arr[i+1]>arr[i])
            i++;
        while(j>0 && arr[j-1]>arr[j])
            j--;
        return i>0 && j<n-1 && i==j;
    }
};