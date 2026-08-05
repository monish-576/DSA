class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int m=board.size(),n=board[0].size();
       vector<vector<int>>vis(m,vector<int>(n,-1));
       queue<pair<int,int>>q;
           for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O'&&vis[0][i]==-1)
            {
                 q.push({0,i});
                 vis[0][i]=1;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(board[i][n-1]=='O'&&vis[i][n-1]==-1)
            {
                 q.push({i,n-1});
                 vis[i][n-1]=1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
             if(board[m-1][i]=='O'&&vis[m-1][i]==-1)
            {
                 q.push({m-1,i});
                 vis[m-1][i]=1;
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            if(board[i][0]=='O'&&vis[i][0]==-1)
            {
                 q.push({i,0});
                 vis[i][0]=1;
            }
        }
         int r[4]={-1,0,0,1};
        int c[4]={0,1,-1,0};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int rx=i+r[k];
                int cx=j+c[k];
             if(rx>=0&&rx<m&&cx>=0&&cx<n&&board[rx][cx]=='O'&&vis[rx][cx]==-1)
             {
                q.push({rx,cx});
                vis[rx][cx]=1;
             }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O'&&vis[i][j]==-1)
                board[i][j]='X';
            }
        }
    }
};