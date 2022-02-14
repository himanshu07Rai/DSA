// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long mergeSortedArrays(long long arr[],long long l_start,long long l_end,long long r_start,long long r_end)
    {
        long long i = l_start,j = r_start,k = 0;
        long long temp[r_end-l_start+1];
        long long count = 0;
        while(i<=l_end && j<=r_end){
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }else{
                // cout<<arr[i]<<"\n";
                temp[k++]=arr[j++];
                count+=l_end-i+1;
            }
        }
        while(i<=l_end)
            temp[k++]=arr[i++];
        while(j<=r_end)
        {
            temp[k++]=arr[j++];
        }
        // k=0;
        for(int i=l_start,k=0;i<=r_end;)
        {
            arr[i++]=temp[k++];
        }
        // cout<<count<<"\n";
        return count;
    }
    long long mergeSort(long long arr[],long long l,long long r){
        if(l<r){
            long long m = (l+r)/2;
            long long leftCount = mergeSort(arr,l,m);
            long long rightCount = mergeSort(arr,m+1,r);
            long long combinedCount = mergeSortedArrays(arr,l,m,m+1,r);
            return leftCount+rightCount+combinedCount;
        }
        return 0;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long ans = mergeSort(arr,0,N-1);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends