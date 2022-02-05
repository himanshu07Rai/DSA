class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()<=target)
            return letters[0];
        int n = letters.size();
        int l = 0,r=n-1;
        int res = letters[0];
        while(l<r)
        {
            int m = l+(r-l)/2;
            if(letters[m]>target)
            {
                r=m;
            }else l=m+1;
        }
        return letters[l];
    }
};