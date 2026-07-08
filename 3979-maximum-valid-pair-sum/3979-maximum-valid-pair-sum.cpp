class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
          prefix[i]=max(prefix[i-1],nums[i]);
        }
        int res=0;
        for(int i=k;i<n;i++)
        {
            res=max(res,nums[i]+prefix[i-k]);
        }
        return res;
    }
};