class Solution {
public:
    bool help(int idx,vector<int>&nums,int sum,int cur, vector<vector<int>>&dp)
    {
        if(sum-cur==cur) return true;
        if(idx==0)
        {
            bool nottake=(sum-cur==cur);
            bool take=(sum-(cur+nums[idx])==(cur+nums[idx]));
            return nottake||take;
        }
        if(dp[idx][cur]!=-1) return dp[idx][cur];
        dp[idx][cur]=(help(idx-1,nums,sum,cur+nums[idx],dp)||help(idx-1,nums,sum,cur,dp));
        return dp[idx][cur];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return help(n-1,nums,sum,0,dp);
    }
};