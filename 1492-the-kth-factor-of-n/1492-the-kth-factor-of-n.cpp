class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int>mxHeap;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                mxHeap.push(i);
            
            if(mxHeap.size()>k)
                mxHeap.pop();
        }
        if(k>mxHeap.size())
            return -1;
        return mxHeap.top();
    }
};