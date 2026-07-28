class Solution {
public:
    int help(int idx,vector<int>&cost,vector<int>&dp)
    {
        if(idx>=cost.size())
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        dp[idx]=cost[idx]+min(help(idx+1,cost,dp),help(idx+2,cost,dp));
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(help(0,cost,dp),help(1,cost,dp));
    }
};