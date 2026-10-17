class Solution {
public:
    int help(int idx,int n,int c,vector<vector<int>>&dp)
    {
        if(c>n) return 0;
        if(idx==5)
        {
            if(n==c) return 1;
            return 0;
        }
        if(dp[idx][c]!=-1) return dp[idx][c];
        int take=0,nottake=0;
        take=help(idx,n,c+1,dp);
        nottake=help(idx+1,n,c,dp);
        return dp[idx][c]=take+nottake;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(5,vector<int>(n+1,-1));
         return help(0,n,0,dp);
    }
};