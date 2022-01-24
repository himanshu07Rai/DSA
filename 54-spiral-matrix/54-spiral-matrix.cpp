class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M =matrix[0].size(), N = matrix.size();
        int T = 0, B = N - 1, L = 0, R = M - 1;
        int dir = 0;
        vector<int> ans;
        while (L <= R && T <= B)
        {
            if (dir == 0)
            {
                for (int k = L; k <= R; k++)
                    ans.push_back(matrix[T][k]);
                T++;
            }
            else if (dir == 1)
            {
                for (int k = T; k <= B; k++)
                    ans.push_back(matrix[k][R]);
                R--;
            }
            else if (dir == 2)
            {
                for (int k = R; k >= L; k--)
                    ans.push_back(matrix[B][k]);
                B--;
            }
            else if (dir == 3)
            {
                for (int k = B; k >= T; k--)
                    ans.push_back(matrix[k][L]);
                L++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
        
    }
};