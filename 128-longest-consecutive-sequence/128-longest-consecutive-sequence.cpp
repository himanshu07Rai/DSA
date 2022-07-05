class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums)
        {
            s.insert(i);
        }
        int longestStreak = 0;
        for(int num:s)
        {
            if(s.find(num-1)==s.end())
            {
                int currentStreak = 1;
                int currentNum=num;
                while(s.find(currentNum+1)!=s.end())
                {
                    currentStreak++;
                    currentNum++;
                }
                longestStreak = max(longestStreak,currentStreak);                    
            }
        }
        return longestStreak;
    }
};