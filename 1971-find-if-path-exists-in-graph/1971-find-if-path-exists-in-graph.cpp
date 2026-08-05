class Solution {
public:
    void dfs(int source,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[source]=1;
        for(int i=0;i<adj[source].size();i++)
        {
            if(vis[adj[source][i]]==-1)
            {
                dfs(adj[source][i],adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,-1);
        dfs(source,adj,vis);
        return vis[destination]==1;
    }
};