class Solution {
public:
     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> cnt(26, 0);
        string s = words2[0];
        for(int i = 0; i < size(s); i++)
            cnt[s[i]-'a']++;
        
        int n = size(words2);
        for(int i = 1; i < n; i++) {
            vector<int> cnt1(26, 0);
            string str = words2[i];
            for(int j = 0; j < size(str); j++)
                cnt1[str[j]-'a']++;
            
            for(int k = 0; k < 26; k++) {
                int temp = cnt1[k] - cnt[k];
                if(temp > 0)
                    cnt[k] += temp;
            }
        }
        
        for(auto w1 : words1) {
            vector<int> cnt1(26, 0);
            
            string str = w1;
            for(int j = 0; j < size(str); j++)
                cnt1[str[j]-'a']++;
            
            bool b = true;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] <= cnt1[i]) continue;
                else {
                    b = false;
                    break;
                }
            }
            
            if(b) ans.push_back(w1);
        }
        
        return ans;
    }
};