class Solution {
public:
    long long dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        vis[r][c]=1;
        long long sum=grid[r][c];
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        for(int i=0;i<4;i++)
        {
            int rx=r+dr[i];
            int cx=c+dc[i];
            if(rx>=0&&rx<grid.size()&&cx>=0&&cx<grid[0].size()&&vis[rx][cx]==0&&grid[rx][cx]>0)
            {
                sum+=dfs(rx,cx,vis,grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        long long sum=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                  if(vis[i][j]==0&&grid[i][j]>0)
                  {
                     sum=dfs(i,j,vis,grid);
                     if(sum%k==0)
                     ans++;
                  }
            }
        }
        return ans;
    }
};