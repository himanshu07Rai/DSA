// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    struct Marks{
        int phy,chem,math;
    };
    public:
    static bool comp(Marks a,Marks b)
    {
        if(a.phy!=b.phy)
            return a.phy<b.phy;
        if(a.chem!=b.chem)
            return a.chem>b.chem;
        return a.math<b.math;
    }
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        vector<Marks> v(N);
        for(int i=0;i<N;i++)
        {
            v[i].phy = phy[i];
            v[i].chem = chem[i];
            v[i].math = math[i];
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<N;i++)
        {
            phy[i] = v[i].phy ;
            chem[i] = v[i].chem;
            math[i] = v[i].math;
        }
        
    } 
};

// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends