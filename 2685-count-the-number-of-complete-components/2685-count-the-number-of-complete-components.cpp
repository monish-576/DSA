class Solution {
public:
    void dfs(int idx,vector<vector<int>>&adj,vector<int>&vis,int &node,int &edges)
    {
        vis[idx]=1;
        node++;
        for(int i=0;i<adj[idx].size();i++)
        {
           edges++;
           if(vis[adj[idx][i]]!=1)
           dfs(adj[idx][i],adj,vis,node,edges);   
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
             int node=0,edges=0;
             dfs(i,adj,vis,node,edges);
             if(edges==(node)*(node-1))
             c++;
            }
        }
        return c;
    }
};