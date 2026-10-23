class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        int m=grid.size(),n=grid[0].size();
        vis[i][j]=1;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int rx=i+dr[k];
            int cx=j+dc[k];
            if(rx>=0&&rx<m&&cx>=0&&cx<n&&vis[rx][cx]==0&&grid[rx][cx]==0)
            {
                vis[rx][cx]=1;
                dfs(rx,cx,vis,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(vis[0][i]==0&&grid[0][i]==0)
            dfs(0,i,vis,grid);
            if(vis[m-1][i]==0&&grid[m-1][i]==0)
            dfs(m-1,i,vis,grid);
        }
        for(int i=0;i<m;i++)
        {
            if(vis[i][0]==0&&grid[i][0]==0)
            dfs(i,0,vis,grid);
            if(vis[i][n-1]==0&&grid[i][n-1]==0)
            dfs(i,n-1,vis,grid);
        }
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(vis[i][j]==0&&grid[i][j]==0)
                {
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};