class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        dp[0] = nums;
        for (int i = 1; i < nums.size(); i++) {
             dp[i].resize(dp[i - 1].size() - 1);
            for (int j = 0; j < dp[i - 1].size()-1; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1])%10;
            }
        }
        return dp[n - 1][0];
    }
};