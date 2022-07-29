class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
       
        for(string t:words)
        {
            int f = 1;
            if(t.size()!=pattern.size())
                continue;
            unordered_map<char,char> word_to_pat,pat_to_word;
            for(int i=0;i<t.size();i++)
            {
                if((word_to_pat.count(t[i]) && word_to_pat[t[i]] != pattern[i]) || (pat_to_word.count(pattern[i]) && pat_to_word[pattern[i]] != t[i])) 
			    {
                    f = 0;
                    continue;
                }
                else
                    word_to_pat[t[i]] = pattern[i],
                    pat_to_word[pattern[i]] = t[i];
            }
            if(f==0)
                continue;
            
            ans.push_back(t);
        }
        return ans;
    }
};