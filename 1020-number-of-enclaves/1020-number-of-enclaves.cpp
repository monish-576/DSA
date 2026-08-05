class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        vector<vector<int>>dum(grid);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1&&vis[0][i]==-1)
            {
                 q.push({0,i});
                 vis[0][i]=1;
                 dum[0][i]=-1;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(grid[i][n-1]==1&&vis[i][n-1]==-1)
            {
                 q.push({i,n-1});
                 vis[i][n-1]=1;
                 dum[i][n-1]=-1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
             if(grid[m-1][i]==1&&vis[m-1][i]==-1)
            {
                 q.push({m-1,i});
                 vis[m-1][i]=1;
                 dum[m-1][i]=-1;
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            if(grid[i][0]==1&&vis[i][0]==-1)
            {
                 q.push({i,0});
                 vis[i][0]=1;
                 dum[i][0]=-1;
            }
        }
        int r[4]={-1,0,0,1};
        int c[4]={0,1,-1,0};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int rx=i+r[k];
                int cx=j+c[k];
             if(rx>=0&&rx<m&&cx>=0&&cx<n&&grid[rx][cx]==1&&vis[rx][cx]==-1)
             {
                q.push({rx,cx});
                vis[rx][cx]=1;
                dum[rx][cx]=-1;
             }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&dum[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
};