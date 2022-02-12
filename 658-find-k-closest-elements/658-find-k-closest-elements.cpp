class Solution {
public:
    struct Element{
        int diff,val;
        Element(int x,int y):val(x),diff(y){}
    };
    
    struct CompareElement{
        bool operator()(Element *a,Element *b)
        {
            if(a->diff!=b->diff)
                return a->diff<b->diff;
            return a->val<b->val;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x)     {
       priority_queue<Element*,vector<Element*>,CompareElement>pq;
        for(int i=0;i<arr.size();i++)
        {
            // if(pq.size()==k)
            // {
            //     int a = pq.top()->diff;
            //     if(abs(arr[i]-x)<a)
            //         pq.pop();
            // }
            Element *t = new Element(arr[i],abs(arr[i]-x));
            pq.push(t);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(!pq.empty())
        {
            Element *a = pq.top();
            pq.pop();
            ans.push_back(a->val);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};