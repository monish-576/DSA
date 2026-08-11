class Solution {
public:
    bool dfs(int i,int j,string word,vector<vector<char>>&board,vector<vector<int>>&vis,int idx)
    {
        if(idx==word.size()) return true;
        vis[i][j]=1;
        int r[4]={0,-1,0,1};
        int c[4]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rx=i+r[k];
            int cx=j+c[k];
            if(rx>=0&&rx<board.size()&&cx>=0&&cx<board[0].size()&&vis[rx][cx]==-1&&board[rx][cx]==word[idx])
            {
                if(dfs(rx,cx,word,board,vis,idx+1))
                return true;
            }
        }
        vis[i][j]=-1;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]&&vis[i][j]==-1)
                {
                    if(dfs(i,j,word,board,vis,1))
                    return true;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<"\n";
        }
        return false;
    }
};