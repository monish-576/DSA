class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int i=0,j=0;
        int ans=INT_MAX;
        int sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target)
            {
                  ans=min(ans,j-i+1);
                  sum-=nums[i];
                  i++;
            }
            j++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};