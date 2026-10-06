class Solution {
public:
    void bfs(int node,vector<vector<int>>&store,vector<vector<int>>&adj,int n)
    {
        vector<int>vis(n,0);
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
           int x=q.front();
           q.pop();
           for(int i=0;i<adj[x].size();i++)
           {
              int y=adj[x][i];
              if(vis[y]==0)
              {
                  vis[y]=1;
                  store[node].push_back(y);
                  q.push(y);
              }
           }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(quiet.size());
        for(int i=0;i<richer.size();i++)
        {
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        vector<vector<int>>store(n);
        for(int i=0;i<quiet.size();i++)
        {
            store[i].push_back(i);
            bfs(i,store,adj,n);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX,node=-1;
            for(int j=0;j<store[i].size();j++)
            {
                int y=store[i][j];
                if(quiet[y]<mini)
                {
                    mini=quiet[y];
                    node=y;
                }
            }
            ans[i]=node;
        }
        return ans;
    }
};