class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int i=0,j=0;
        int p=0;
        while(j<nums.size())
        {
            while(p>k)
            {
                if(nums[i]==0) p--;
                i++;
            }
            if(nums[j]==0)
            p++;
            if(p<=k)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};