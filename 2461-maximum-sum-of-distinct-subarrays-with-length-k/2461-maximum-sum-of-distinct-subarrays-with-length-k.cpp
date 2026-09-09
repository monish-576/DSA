class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        long long ans=0,sum=0;
        map<int,int>mp;
        while(j<n)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]]>1)
            {
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            while(j-i+1>k)
            {
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k) ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};