class Solution {
public:
    long long smallestNumber(long long num) {
        if(!num)
            return 0;
        vector<int>arr(10,0);
        long long t = num;
        while(t)
        {
            int r =abs(t%10);
            arr[r]++;
            // cout<<r<<" "<<arr[r]<<"\n";
            t=t/10;
        }
        
        // for(int i:arr)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        if(num<0)
        {
            long long ans = 0;
            for(int i=9;i>=0;i--)
            {
                // cout<<ans<<"\n";
                while(arr[i]--)
                {
                    ans = ans*10+i;
                    // cout<<ans<<"\n";
                }
            }
            return ans*-1;
        }else{
            long long ans = 0;
            int t;
            for(int i=1;i<=9;i++)
            {
                // cout<<i<<" ";
                if(arr[i]>0)
                {
                    t = i;
                    break;
                }                    
            }
            // cout<<t<<"\n";
            ans = t;
            arr[t]--;
            for(int i=0;i<=9;i++)
            {
                // cout<<ans<<"\n";
                while(arr[i]>0)
                {
                    ans = ans*10+i;
                    arr[i]--;
                }
            }
            return ans;            
        }
        return 0;
    }
};