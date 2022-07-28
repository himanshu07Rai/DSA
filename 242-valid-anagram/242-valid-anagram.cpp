class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            smap[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            smap[t[i]]--;
            if(smap[t[i]]<0)
                return false;
        }
        return true;
    }
};