class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>>vis(n,vector<int>(n,1e4));
       for(int i=0;i<n;i++)
       {
           vis[i][i]=0;
       }
       for(int i=0;i<edges.size();i++)
       {
            vis[edges[i][0]][edges[i][1]]=edges[i][2];
            vis[edges[i][1]][edges[i][0]]=edges[i][2];
       }
       for(int k=0;k<n;k++)
       {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                  vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
               }
           }
       }
       int ans,count=INT_MAX;
       for(int i=0;i<n;i++)
       {
           int c=0;
           for(int j=0;j<n;j++)
           {
              if(vis[i][j]<=distanceThreshold)
              c++;
           }
            if(c<=count)
            {
             ans=i;
             count=c;
            }
       }
       return ans;
    }
};