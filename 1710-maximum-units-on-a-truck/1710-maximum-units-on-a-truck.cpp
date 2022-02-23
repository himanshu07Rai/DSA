class Solution {
public:
    static bool comp(vector<int> &item1,vector<int> &item2)
    {
        if(item1[1]!=item2[1])
            return item1[1]>item2[1];
        else return item1[0]<item2[0];
    }
    int maximumUnits(vector<vector<int>>& bt, int truckSize) {
        int rows = bt.size();
        int count = 0;
        int i;
        sort(bt.begin(),bt.end(),comp);
        for(i=0;i<rows;i++)
        {
            if(bt[i][0]<=truckSize){
                count+=bt[i][1]*bt[i][0];
                truckSize-=bt[i][0];
            }else break;
        }
        if(i<rows)
            count+=bt[i][1]*truckSize;
        return count;
    }
};