class Solution {
public:
    int ans=0;
    void dfs(int i,int j,vector<vector<int>>grid,vector<vector<int>>&vis,int &c)
    {
        vis[i][j]=1;
        int r[4]={0,-1,0,1};
        int d[4]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rx=i+r[k];
            int cx=j+d[k];
            if(rx>=0&&rx<grid.size()&&cx>=0&&cx<grid[0].size()&&vis[rx][cx]==-1&&grid[rx][cx]==1)
            {
                c++;
                dfs(rx,cx,grid,vis,c);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==-1&&grid[i][j]==1)
                {
                    int c=1;
                    dfs(i,j,grid,vis,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};