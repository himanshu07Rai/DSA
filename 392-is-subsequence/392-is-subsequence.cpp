class Solution {
public:
    // bool isSubsequence(string s, string t) {
    //     int i = 0,j=0;
    //     while(i<s.size() && j<t.size())
    //     {
    //         if(t[j]==s[i])
    //         {
    //             i++;
    //         }
    //         j++;
    //     }
    //     if(i==s.size())
    //         return true;
    //     else
    //         return false;
    // }
    // bool solve(string s, string t,int idx,string &temp)
    // {
    //     if(idx>=t.size())
    //     {
    //         return temp==s;
    //     }
    //     temp+=t[idx];
    //     solve
    // }
    bool isSubsequence(string s, string t) {
        int len = 0;
        if(size(s) == 0) return true;
        for(char x:t){
            if(x==s[len]) len++;
            if(len == size(s)) return true;
        }
        return false;
    }
};