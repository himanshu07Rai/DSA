class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1,j = t.length()-1;
        while(i>=0 || j>=0)
        {
            int count = 0;
            while(i>=0 && (count>0 || s[i]=='#'))
            {
                s[i]=='#'?count++:count--;
                i--;
            }
            count=0;
            while(j>=0 && (count>0 || t[j]=='#'))
            {
                t[j]=='#'?count++:count--;
                j--;
            }
            if(i>=0 && j>=0)
            {
                if(s[i]!=t[j])
                    return false;
                else{
                    i--,j--;
                }
            }
            else if(i>=0 || j>=0)
                return false;
        }
        return true;
    }
};