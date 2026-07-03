class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi=1,lastidx=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int vis=0;vis<i;vis++)
            {
                if(nums[i]%nums[vis]==0&&dp[i]<dp[vis]+1)
                {
                    dp[i]=dp[vis]+1;
                    hash[i]=vis;
                }
            }
            if(maxi<dp[i])
            {
                maxi=dp[i];
                lastidx=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastidx]);
        while(hash[lastidx]!=lastidx)
        {
            lastidx=hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};