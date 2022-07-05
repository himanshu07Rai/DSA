class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums)
        {
            s.insert(i);
        }
        int longestStreak = 0;
        for(int i:s)
        {
            if(s.find(i-1)==s.end())
            {
                int currentStreak = 1;
                int j=i;
                while(s.find(j+1)!=s.end())
                {
                    currentStreak++;
                    j++;
                }
                longestStreak = max(longestStreak,currentStreak);                    
            }
        }
        return longestStreak;
    }
};