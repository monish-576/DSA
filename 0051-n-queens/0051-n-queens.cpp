class Solution {
public:
    void help(int col,int n, vector<string>&board,vector<int>&midrow,vector<int>&uprdia, vector<int>&lwrdia,vector<vector<string>>&ans)
    {
       if(n==col)
       {
         ans.push_back(board);
         return ;
       }
       for(int i=0;i<n;i++)
       {
          if(midrow[i]==0&&uprdia[i+col]==0&&lwrdia[(n-1)+col-i]==0)
          {
          board[i][col]='Q';
          midrow[i]=1;
          uprdia[i+col]=1;
          lwrdia[(n-1)+col-i]=1;
          help(col+1,n,board,midrow,uprdia,lwrdia,ans);
          board[i][col]='.';
          midrow[i]=0;
          uprdia[i+col]=0;
          lwrdia[(n-1)+col-i]=0;
          }
       }
    } 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<string>queen(n);
        vector<int>midrow(n,0);
        vector<int>uprdia(n*n,0);
        vector<int>lwrdia(n*n,0);
        help(0,n,board,midrow,uprdia,lwrdia,ans);
        return ans;
    }
};