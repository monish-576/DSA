class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
           int u=prerequisites[i][0];
           int v=prerequisites[i][1];
           adj[u].push_back(v);
           indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int c=0;
        while(!q.empty())
        {
            int i=q.front();
            c++;
            q.pop();
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]--;
                if(indegree[adj[i][j]]==0) q.push(adj[i][j]);
            }
        }
        return c==numCourses;
    }
};