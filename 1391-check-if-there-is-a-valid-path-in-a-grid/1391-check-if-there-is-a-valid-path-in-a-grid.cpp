class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int i,j;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty())
        {
           i=q.front().first;
           j=q.front().second;
           q.pop();

           if(i==m-1&&j==n-1) return true;

           if(grid[i][j]==1)
           {
              if(j-1>=0&&vis[i][j-1]==0&&
                 (grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6))
              {
                   vis[i][j-1]=1;
                   q.push({i,j-1});
              }

              if(j+1<n&&vis[i][j+1]==0&&
                 (grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5))
              {
                   vis[i][j+1]=1;
                   q.push({i,j+1});
              }
           }
           else if(grid[i][j]==2)
           {
              if(i-1>=0&&vis[i-1][j]==0&&
                 (grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4))
              {
                   vis[i-1][j]=1;
                   q.push({i-1,j});
              }

              if(i+1<m&&vis[i+1][j]==0&&
                 (grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6))
              {
                   vis[i+1][j]=1;
                   q.push({i+1,j});
              }
           }
           else if(grid[i][j]==3)
           {
              if(j-1>=0&&vis[i][j-1]==0&&
                 (grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6))
              {
                   vis[i][j-1]=1;
                   q.push({i,j-1});
              }

              if(i+1<m&&vis[i+1][j]==0&&
                 (grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6))
              {
                   vis[i+1][j]=1;
                   q.push({i+1,j});
              }
           }
           else if(grid[i][j]==4)
           {
              if(j+1<n&&vis[i][j+1]==0&&
                 (grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5))
              {
                   vis[i][j+1]=1;
                   q.push({i,j+1});
              }

              if(i+1<m&&vis[i+1][j]==0&&
                 (grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6))
              {
                   vis[i+1][j]=1;
                   q.push({i+1,j});
              }
           }
           else if(grid[i][j]==5)
           {
              if(j-1>=0&&vis[i][j-1]==0&&
                 (grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6))
              {
                   vis[i][j-1]=1;
                   q.push({i,j-1});
              }

              if(i-1>=0&&vis[i-1][j]==0&&
                 (grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4))
              {
                   vis[i-1][j]=1;
                   q.push({i-1,j});
              }
           }
           else
           {
              if(j+1<n&&vis[i][j+1]==0&&
                 (grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5))
              {
                   vis[i][j+1]=1;
                   q.push({i,j+1});
              }

              if(i-1>=0&&vis[i-1][j]==0&&
                 (grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4))
              {
                   vis[i-1][j]=1;
                   q.push({i-1,j});
              }
           }
        }

        return false;
    }
};