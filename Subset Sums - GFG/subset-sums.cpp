// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(int start,vector<int>&arr,int CurrSum,vector<int> &ans,int N)
    {
        if(start==N)
        {
            ans.push_back(CurrSum);
            return;
        }
        solve(start+1,arr,CurrSum,ans,N);
        solve(start+1,arr,CurrSum+arr[start],ans,N);
        CurrSum-=arr[start];
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int CurrSum = 0;
        solve(0,arr,CurrSum,ans,N);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends