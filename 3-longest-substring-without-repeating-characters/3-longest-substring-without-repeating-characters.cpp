class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0,r = 0;
        unordered_set<char> set;
        int ans=0,size=0;
        while(r<n)
        {
            auto it = set.find(s[r]);
            if(it==set.end())
            {
                set.insert(s[r]);
                size = set.size();
                ans = max(ans,size);
            }else{
                while(s[l]!=s[r])
                {
                    set.erase(s[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};