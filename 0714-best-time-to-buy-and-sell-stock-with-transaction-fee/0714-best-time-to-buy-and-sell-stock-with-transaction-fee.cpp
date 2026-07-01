class Solution {
public:
    int help(int idx,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee)
    {
         if(idx>=prices.size()) return 0;
         if(dp[idx][buy]!=-1) return dp[idx][buy];
         int take=0,nottake=0;
         if(buy==1)
         {
            take-=prices[idx];
            take+=help(idx+1,0,prices,dp,fee);
            nottake=help(idx+1,1,prices,dp,fee);
         }
         else
         {
            take-=fee;
            take+=prices[idx]+help(idx+1,1,prices,dp,fee);
            nottake=help(idx+1,0,prices,dp,fee);
         }
         return dp[idx][buy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(0,1,prices,dp,fee);
    }
};