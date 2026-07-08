class Solution {
public:
    int help(vector<int>&nums,int goal)
    {
        if(goal<0) return 0;
        int i=0,j=0,n=nums.size(),sum=0,ans=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum=sum-nums[i];
                i++;
            }
            if(sum<=goal)
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal)-help(nums,goal-1);
    }
};