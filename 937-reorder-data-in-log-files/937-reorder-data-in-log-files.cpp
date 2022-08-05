class Solution {
  static bool comp(pair<string,string>&item1,pair<string,string>&item2)
    {
        if(item1.second!=item2.second)
            return item1.second<item2.second;
        else{
            return item1.first<item2.first;
        }
    }
    public:
   
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> let;
        vector<string>dig;
        for(string s:logs)
        {
            int i = s.find(' ');
            if(isalpha(s[i+1])){
                let.push_back({s.substr(0,i),s.substr(i+1)});
            }else{
                dig.push_back(s);
            }
        }
        sort(let.begin(),let.end(),comp);
        vector<string> ans;
        for(auto s:let)
        {
            ans.push_back(s.first+" "+s.second);
        }
        for(auto s:dig)
        {
            ans.push_back(s);
        }
        return ans;
    }
};