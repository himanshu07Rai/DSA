class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;
        vector<string>v = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        for(int i=0;i<words.size();i++){
            string s1 = words[i];
            string ans = "";
            for(int j=0;j<s1.length();j++){
                ans = ans + v[s1[j] - 'a'];
            }
            // cout<<ans<<" ";
            s.insert(ans);
        }
        return s.size();
    }
};