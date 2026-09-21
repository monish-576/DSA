class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vis[0][0]=0;
        pq.push({0,{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==m-1&&c==n-1) return vis[r][c];
            for(int i=0;i<4;i++)
            {
                int rx=r+dr[i];
                int cx=c+dc[i];
                if(rx>=0&&rx<m&&cx>=0&&cx<n&&vis[rx][cx]>cost+1)
                {
                     if(grid[rx][cx]==0)
                     {
                        pq.push({cost,{rx,cx}});
                        vis[rx][cx]=cost;
                     } 
                     else
                     {
                        pq.push({cost+1,{rx,cx}});
                        vis[rx][cx]=cost+1;
                     }
                }
            }
        }
        return 0;
    }
};