class Solution {
public:
    int help(int n,vector<int>&dp)
    {
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int a,b;
        int cost=0;
        if(n%2==0)
        a=n/2;
        else
        a=n/2+1;
        b=n-a;
        cost=a*b;
        if(a>1)
        cost+=help(a,dp);
        if(b>1)
        cost+=help(b,dp);
        return dp[n]=cost;
    }
    int minCost(int n) {
        if(n==1) return 0;
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};