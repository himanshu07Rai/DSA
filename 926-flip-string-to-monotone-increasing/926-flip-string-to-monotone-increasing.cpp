class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCounter = 0,flips = 0;
        for(char c:s)
        {
            if(c=='1')
                oneCounter++;
            else
                flips++;
            flips = min(flips,oneCounter);
        }
        return flips;
    }
};