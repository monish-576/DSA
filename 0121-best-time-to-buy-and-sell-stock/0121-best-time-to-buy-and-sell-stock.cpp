class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        int sale=prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(prices[i]-sale,dp[i-1]);
            sale=min(sale,prices[i]);
        }
        return dp[n-1];
    }
};