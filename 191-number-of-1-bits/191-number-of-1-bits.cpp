class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a = 1;
        int count = 0;
        for(int i =0;i<32;i++)
        {
            int b = a<<i;
            if(n&b)
                count++;
        }
        return count;
    }
};