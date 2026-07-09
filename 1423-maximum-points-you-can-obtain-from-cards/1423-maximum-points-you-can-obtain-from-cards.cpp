class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;

        // Take first k cards
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int ans = leftSum;
        int leftIndex = k - 1;

        // Replace left cards one by one with right cards
        for (int rightIndex = n-1; rightIndex >=n-k; rightIndex--) {
            leftSum -= cardPoints[leftIndex];
            rightSum += cardPoints[rightIndex];

            leftIndex--;

            ans = max(ans, leftSum + rightSum);
        }

        return ans;
    }
};