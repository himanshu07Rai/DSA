
class Solution {
    static bool mycmp(const pair<int,int> &a, const  pair<int,int> &b)
    {
        return (a.second>b.second);
    }
   
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto &it: mp)
        {
            v.push_back(it);
        }
        
        sort(v.begin(),v.end(),mycmp);
        int count=0;
        int sum=0;
        for(auto &it: v)
        {
            sum=sum+it.second;
            count++;
            if(sum>=n/2)
               break; 
        }
        return count;
    }
};