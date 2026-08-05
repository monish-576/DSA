class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
       }
       int dr[4]={-1,0,0,1};
       int dc[4]={0,-1,1,0};
       while(!q.empty())
       {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int k=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int rx=r+dr[i];
            int cx=c+dc[i];
            if(rx>=0&&rx<m&&cx>=0&&cx<n&&vis[rx][cx]!=1&&mat[rx][cx]==1)
            {
                q.push({{rx,cx},k+1});
                vis[rx][cx]=1;
            }
        }
        dis[r][c]=k;
       }
       return dis;
    }
};