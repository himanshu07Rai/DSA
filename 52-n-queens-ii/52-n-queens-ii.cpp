class Solution {
public:
     void solve(vector<vector<bool>> &board, int row, vector<bool> &cols, vector<bool> &ld, vector<bool> &rd,vector<vector<string>>& ans)

{

    if (row == board.size())
    {
        string temp = "";
        vector<string>sol;
        for(int i=0;i<board.size();i++)
        {
            temp="";
            for(int j=0;j<board[0].size();j++)
            {
                if(!board[i][j])
                {
                    temp+=".";
                }
                else
                {
                    temp+="Q";
                }
            }
            sol.push_back(temp);
        }
        ans.push_back(sol);
        return;
    }
    for (int col = 0; col < board[0].size(); col++)
    {
        if (!cols[col] && !ld[row + col] && !rd[row - col + board.size() - 1])
        {
            board[row][col] = true;
            cols[col] = true;
            ld[row + col] = true;
            rd[row - col + board.size() - 1] = true;
            solve(board, row + 1, cols, ld, rd,ans);
            board[row][col] = false;
            cols[col] = false;
            ld[row + col] = false;
            rd[row - col + board.size() - 1] = false;
        }
    }
}
    int totalNQueens(int n) {
        vector<bool> cols(n, false), ld(2 * n - 1, false), rd(2 * n - 1, false);
        int row = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        solve(board, row, cols, ld, rd,ans);
        
        return ans.size();
    }
};