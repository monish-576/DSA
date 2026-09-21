class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        deque<pair<int,pair<int,int>>>dq;
        vis[0][0]=0;
        dq.push_front({0,{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!dq.empty())
        {
            int cost=dq.front().first;
            int r=dq.front().second.first;
            int c=dq.front().second.second;
            dq.pop_front();
            if(r==m-1&&c==n-1) return vis[r][c];
            for(int i=0;i<4;i++)
            {
                int rx=r+dr[i];
                int cx=c+dc[i];
                if(rx>=0&&rx<m&&cx>=0&&cx<n&&vis[rx][cx]>cost+1)
                {
                     if(grid[rx][cx]==0)
                     {
                        dq.push_front({cost,{rx,cx}});
                        vis[rx][cx]=cost;
                     } 
                     else
                     {
                        dq.push_back({cost+1,{rx,cx}});
                        vis[rx][cx]=cost+1;
                     }
                }
            }
        }
        return 0;
    }
};