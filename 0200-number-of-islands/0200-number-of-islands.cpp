class Solution {
public:
    void help(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j)
    {
         queue<pair<int,int>>q;
         q.push({i,j});
         vis[i][j]=1;
         while(!q.empty())
         {
             int r=q.front().first;
             int c=q.front().second;
             q.pop();
             int dr[4]={-1,0,1,0};
             int dc[4]={0,-1,0,1};
             for(int i=0;i<4;i++)
             {
                int rx=r+dr[i],cx=c+dc[i];
                if(rx>=0&&rx<grid.size()&&cx>=0&&cx<grid[0].size()&&grid[rx][cx]=='1'&&vis[rx][cx]!=1)
                {
                    q.push({rx,cx});
                    vis[rx][cx]=1;
                }
             }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
              if(grid[i][j]=='1'&&vis[i][j]!=1)
              {
                 help(grid,vis,i,j);
                 ans++;
              }
          }
        }
        return ans;
    }
};