class Solution {
public:
    string reorganizeString(string s) {
        vector<int> m(26,0);
        int mostFreq = 0;
        for(char c:s)
        {
            if(++m[c-'a']>m[mostFreq])
                mostFreq = (c-'a');
        }
        
        if(m[mostFreq]*2-1>s.length())
            return "";
        
        int i = 0;
        while(m[mostFreq]--)
        {
            s[i]=('a'+mostFreq);
            i+=2;
        }
        
        for(int j=0;j<26;j++)
        {
            if(m[j])
            {
                while(m[j]-->0)
                {
                    if(i >= s.size()) i = 1;
                    s[i] = ('a' + j);
                    i += 2;
                }
            }
        }
        return s;
    }
};