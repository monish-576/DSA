class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffix(nums.size());
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(nums[i],suffix[i+1]);
        }
        int ans=INT_MAX;
        int prefix=nums[0];
        if(prefix-suffix[0]<=k) return 0;
        for(int i=1;i<n;i++)
        {
            prefix=max(nums[i],prefix);
            if(prefix-suffix[i]<=k)
            {
                ans=i;
                break;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};