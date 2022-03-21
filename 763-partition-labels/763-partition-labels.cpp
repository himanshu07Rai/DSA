class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26);
        int len = S.length();
        for(int i=0;i<len;i++)
            last[S[i]-'a'] = i;
        int start = 0;
        int maxi = -1;//max index of character which in between S[i] and last[s[i]]
        vector<int> ans;
        for(int i=0;i<len;i++)
        {
            maxi = max(maxi,last[S[i]-'a']);
            if(i == maxi)
            {
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
    
};

