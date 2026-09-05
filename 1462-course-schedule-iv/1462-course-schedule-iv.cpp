class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites)
        {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<bool>> pre(
            numCourses,
            vector<bool>(numCourses, false)
        );

        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v : adj[u])
            {
                pre[u][v] = true;
                for(int k = 0; k < numCourses; k++)
                {
                    if(pre[k][u])
                        pre[k][v] = true;
                }

                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<bool> ans;

        for(auto &q : queries)
        {
            ans.push_back(pre[q[0]][q[1]]);
        }

        return ans;
    }
};