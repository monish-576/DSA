class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int tot = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        vector<vector<int>> dp(n + 3, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            // Alice's turn (p = 0)
            int s1 = stoneValue[i] + dp[i + 1][1];

            int s2 = INT_MIN;
            if (i + 1 < n)
                s2 = stoneValue[i] + stoneValue[i + 1] + dp[i + 2][1];

            int s3 = INT_MIN;
            if (i + 2 < n)
                s3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + dp[i + 3][1];

            dp[i][0] = max({s1, s2, s3});

            // Bob's turn (p = 1)
            int b1 = dp[i + 1][0];
            int b2 = dp[i + 2][0];
            int b3 = dp[i + 3][0];

            dp[i][1] = min({b1, b2, b3});
        }

        int alice = dp[0][0];
        int bob = tot - alice;

        if (alice > bob) return "Alice";
        if (alice < bob) return "Bob";
        return "Tie";
    }
};