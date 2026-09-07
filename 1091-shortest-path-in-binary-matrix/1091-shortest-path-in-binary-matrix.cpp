class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({1,{0,0}});
        vis[0][0]=1;
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty())
        {
            int dist=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(r==n-1&&c==n-1) return vis[n-1][n-1];
            for(int i=0;i<8;i++)
            {
                int rx=r+dr[i];
                int cx=c+dc[i];
                if(rx>=0&&rx<n&&cx>=0&&cx<n&&vis[rx][cx]==-1&&grid[rx][cx]==0)
                {
                    q.push({dist+1,{rx,cx}});
                    vis[rx][cx]=dist+1;
                }
            }
        }
        return -1;
    }
};