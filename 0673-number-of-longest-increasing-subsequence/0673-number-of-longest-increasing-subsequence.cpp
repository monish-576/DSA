class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),count(n,1);
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                        count[i]=count[prev];
                    }
                    else if(dp[prev]+1==dp[i])
                    {
                        count[i]+=count[prev];
                    }
                }
            }
        }
        int res=*max_element(dp.begin(),dp.end());
        int c=0;
        for(int i=0;i<n;i++)
        {
           if(res==dp[i])
           c+=count[i];
        }
        return c;
    }
};