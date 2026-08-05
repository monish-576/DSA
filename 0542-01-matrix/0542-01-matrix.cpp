class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
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
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int l=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int rx=i+r[k];
                int cx=j+c[k];
                if(rx>=0&&rx<m&&cx>=0&&cx<n&&vis[rx][cx]!=1)
                {
                    q.push({{rx,cx},l+1});
                    vis[rx][cx]=1;
                }
            }
            dis[i][j]=l;
        }
        return dis;
    }
};