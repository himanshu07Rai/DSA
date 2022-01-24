class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto i:prerequisites)
        {
            int f = i[1],s=i[0];
            g[f].push_back(s);
        }
        vector<int>in(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(int child:g[i])
            {
                in[child]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(!in[i]) q.push(i);
        }
        int count = numCourses;
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            count--;
            for(int next:g[course])
            {
                in[next]--;
                if(!in[next])q.push(next);
            }
        }
        return !count;
    }
};