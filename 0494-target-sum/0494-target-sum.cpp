class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);

        if (tot < abs(target)) return 0;
        if ((tot + target) % 2) return 0;

        int req = (tot + target) / 2;

        vector<vector<int>> dp(n, vector<int>(req + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;
            if (nums[0] <= req)
                dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= req; j++) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] <= j)
                    dp[i][j] += dp[i - 1][j - nums[i]];
            }
        }

        return dp[n - 1][req];
    }
};