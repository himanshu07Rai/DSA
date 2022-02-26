// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    // Complete the function
    int countOne = 0;
    for(int i=0;i<n;i++)
    {
        countOne+=arr[i]==1;
    }
    
    if(!countOne)
        return -1;
        
    int i=0,j=0,temp = 0,ans = INT_MAX,a,b;
    while(j<n)
    {
        temp+=arr[j]==0;
        if(j-i+1==countOne)
        {
            ans = min(ans,temp);
            
            temp -= arr[i]==0;
            i++;
        }
        j++;
    }
    return ans;
}