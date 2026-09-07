class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while(!pq.empty())
        {
            int time=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==n-1) return time;
            for(int i=0;i<4;i++)
            {
                int rx=r+dr[i];
                int cx=c+dc[i];
                if(rx>=0&&rx<n&&cx>=0&&cx<n&&dist[rx][cx]==INT_MAX)
                {
                    int a=max(time,grid[rx][cx]);
                    if(a<dist[rx][cx])
                    {
                        dist[rx][cx]=a;
                        pq.push({a,{rx,cx}});
                    }
                }
            }
        }
        return 0;
    }
};