class Solution {
public:
    int help(int col,int n, vector<vector<int>>&queen,vector<int>&midrow,vector<int>&uprdia, vector<int>&lwrdia)
    {
       int ans=0;
       if(n==col)
       {
         return 1;
       }
       for(int i=0;i<n;i++)
       {
          if(midrow[i]==0&&uprdia[i+col]==0&&lwrdia[(n-1)+col-i]==0)
          {
          queen[i][col]=1;
          midrow[i]=1;
          uprdia[i+col]=1;
          lwrdia[(n-1)+col-i]=1;
          ans+=help(col+1,n,queen,midrow,uprdia,lwrdia);
          queen[i][col]=0;
          midrow[i]=0;
          uprdia[i+col]=0;
          lwrdia[(n-1)+col-i]=0;
          }
       }
       return ans;
    }
    int totalNQueens(int n) {
        int c=0;
        vector<vector<int>>queen(n,vector<int>(n,0));
        vector<int>midrow(n,0);
        vector<int>uprdia(n*n,0);
        vector<int>lwrdia(n*n,0);
        return help(0,n,queen,midrow,uprdia,lwrdia);
    }
};