class Solution {
public:
    int help(int i,int p,int m,vector<int>&piles,vector<vector<vector<int>>>&dp)
    {
        if(i>=piles.size()) return 0;
        if(dp[i][p][m]!=-1) return dp[i][p][m];
        int sum=0;
        int ans;
        if(p==0)
        {
            ans=0;
        }
        else
        ans=INT_MAX;
        for(int x=1;x<=2*m&&i+x<=piles.size();x++)
        {
            sum+=piles[i+x-1];
            if(p==0)
            {
                ans=max(sum+help(i+x,1,max(m,x),piles,dp),ans);
            }
            else
            {
                ans=min(ans,help(i+x,0,max(m,x),piles,dp));
            }
        }
        return dp[i][p][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
         vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(n + 1, -1))
        );
        return help(0,0,1,piles,dp);
    }
};