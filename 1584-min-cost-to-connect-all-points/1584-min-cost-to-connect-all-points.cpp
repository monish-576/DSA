class DSU{
 public:
    vector<int>par,size;
    DSU(int n)
    {
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
    }
    int findpar(int u)
    {
        if(par[u]==u) return u;
        int npr=findpar(par[u]);
        return par[u]=npr;
    }
    void merge(int u,int v)
    {
        int paru=findpar(u);
        int parv=findpar(v);
        if(paru==parv) return ;
        if(size[paru]>=size[parv])
        {
            par[parv]=paru;
            size[paru]+=size[parv];
        }
        else
        {
            par[paru]=parv;
            size[parv]+=size[paru];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                 int x=abs(points[i][0]-points[j][0]);
                 int y=abs(points[i][1]-points[j][1]);
                  pq.push({x+y,{i,j}});
            }
        }
        DSU *obj=new DSU(n);
        int ans=0;
        while(!pq.empty())
        {
                int wt=pq.top().first;
                int u=pq.top().second.first;
                int v=pq.top().second.second;
                pq.pop();
                int paru=obj->findpar(u);
                int parv=obj->findpar(v);
                if(paru==parv) continue;
                obj->merge(u,v);
                ans+=wt;
        }
        return ans;
    }
};