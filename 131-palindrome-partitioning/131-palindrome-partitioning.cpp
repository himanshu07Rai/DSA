class Solution {
public:
    bool isPalindromic(string &s,int i,int j)
    {
        if(i>=j)
            return true;
        if(s[i]!=s[j])
            return false;
        return isPalindromic(s,i+1,j-1);
        
    }
    void solve(string s,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(s.size()==0){
            ans.push_back(temp);
        }   
        for(int i=0;i<s.length();i++)
        {
            string leftPart = s.substr(0,i+1);
            if(isPalindromic(leftPart,0,i))
            {
                temp.push_back(leftPart);
                solve(s.substr(i+1),temp,ans);
                temp.pop_back();
            }            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,temp,ans);
        return ans;
    }
};