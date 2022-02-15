// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
    int sum = 0,prevSum = 0;
    
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        prevSum+=i*A[i];
    }
    int ans = prevSum;
    for(int i=0;i<N;i++)
    {
        int nextSum = prevSum+sum-N*A[N-1-i];
        ans = max(ans,nextSum);
        prevSum = nextSum;
    }
    return ans;
}