class Solution {
public:
    int help(string &s,int &i,int n)
    {
        int score = 0;
        while(i<n)
        {
            char f = s[i++];
            if(f=='(')
            {
                if(s[i]==')'){
                    score++;
                    i++;
                }
                else{
                    score = score+2*(help(s,i,n));
                }                  
            }
            else{
                return score;
            }
        }
        return score;
    }
    int scoreOfParentheses(string s) {
        int n = s.length();
        int i = 0;
        return help(s,i,n);
    }
};