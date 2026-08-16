class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int k=0,ans=0,p=0;
        while(j<nums.size())
        {
            if(nums[j]==0) k++;
            else
            p++;
            while(k>1)
            {
                if(nums[i]==0)
                k--;
                i++;
            }
            if(k==0)
            ans=max(ans,j-i+1);
            else
            ans=max(ans,j-i);
            j++;
        }
        if(p==nums.size()) return ans-1;
        return ans;
    }
};