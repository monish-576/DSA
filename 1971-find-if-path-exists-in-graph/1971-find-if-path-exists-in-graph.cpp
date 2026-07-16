class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0) return true;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        queue<int>q;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        vis[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                 if(vis[destination]==1)
                 return true;
                 if(vis[adj[node][i]]==0)
                 {
                     q.push(adj[node][i]);
                     vis[adj[node][i]]=1;
                 }
            }
        }
        return false;
    }
};