class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j<m && j>=0;
    }
    void check(int i,int j,int n,int m,vector<vector<int>>& board,vector<pair<int,int>> &st)
    {
        int count = 0;
        int for_i[]={-1,-1,-1,0,1,1,1,0},for_j[]={-1,0,1,1,1,0,-1,-1};
        for(int k=0;k<8;k++)
        {
            int n_i = i+for_i[k],n_j = j+for_j[k];
            if(isValid(n_i,n_j,n,m) && board[n_i][n_j])
                count++;
        }
        if(board[i][j])
        {
            if(count<2 || count>3)
                st.push_back({i,j});
        }
        else{
            if(count==3)
                st.push_back({i,j});
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(),m=board[0].size();
        vector<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                check(i,j,n,m,board,st);
            }
        }
        for(auto it:st)
        {
            board[it.first][it.second] = !board[it.first][it.second] ;
        }
    }
};