class Solution {
public:
    bool help(int idx,vector<int>&nums,int sum,int cur, vector<vector<int>>&dp)
    {
        if(idx<0) return false;
        if(sum-cur==cur&&idx>=0) return true;
        if(dp[idx][cur]!=-1) return dp[idx][cur];
        dp[idx][cur]=(help(idx-1,nums,sum,cur+nums[idx],dp)||help(idx-1,nums,sum,cur,dp));
        return dp[idx][cur];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
       vector<int>prev(sum+1,0);
       vector<int>curr(sum+1,0);
       prev[0]=1;
       curr[0]=1;
        if(nums[0] <= sum)
            prev[nums[0]] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<nums[i])
                curr[j]=prev[j];
                else
                curr[j] = (prev[j]||prev[j-nums[i]]);
            }
            prev=curr;
        }
        return prev[sum];
    }
};