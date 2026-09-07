class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            for(auto it:adj[i])
            {
                int v=it.first;
                int w=it.second;
                if(dist[v]>cost+w)
                {
                    dist[v]=cost+w;
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX) return -1;
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans;
    }
};