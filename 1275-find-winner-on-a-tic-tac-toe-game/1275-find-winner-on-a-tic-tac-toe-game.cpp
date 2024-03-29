class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int rowA[3]={0},rowB[3]={0},colA[3]={0},colB[3]={0},d1A=0,d2A=0,d1B=0,d2B=0;
        int id=0;
        for(auto i:moves){
            if(!id)
            {
                ++rowA[i[0]],++colA[i[1]];
                if(i[0]==i[1])
                    d1A++;
                if(i[0]+i[1]==2)
                    d2A++;
                if(rowA[i[0]]==3 || colA[i[1]]==3 || d1A==3 || d2A==3)
                    return "A";
                    
            }else{
                ++rowB[i[0]],++colB[i[1]];
                if(i[0]==i[1])
                    d1B++;
                if(i[0]+i[1]==2)
                    d2B++;
                if(rowB[i[0]]==3 || colB[i[1]]==3 || d1B==3 || d2B==3)
                    return "B";
            }
            id=!id;
        }
        return moves.size()==9?"Draw":"Pending";
    }
};