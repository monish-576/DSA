class Solution {
public:
    int help(int idx, int buy, int count, vector<int>& prices,
             vector<vector<vector<int>>>& dp) {

        if(idx == prices.size() || count == 2)
            return 0;

        if(dp[idx][buy][count] != -1)
            return dp[idx][buy][count];

        int take, nottake;

        if(buy) {
            take = -prices[idx] + help(idx+1, 0, count, prices, dp);
            nottake = help(idx+1, 1, count, prices, dp);
        }
        else {
            take = prices[idx] + help(idx+1, 1, count+1, prices, dp);
            nottake = help(idx+1, 0, count, prices, dp);
        }

        return dp[idx][buy][count] = max(take, nottake);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));

        return help(0, 1, 0, prices, dp);
    }
};