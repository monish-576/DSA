class Solution {
public:
    long long help(vector<int>&nums,int element,int k )
    {
        if(k<0) return 0;
        int i=0,j=0,n=nums.size(),z=0;
        long long ans=0;
        while(j<n)
        {
            if(nums[j]==element)
            z++;
            while(z>k)
            {
                if(nums[i]==element)
                z--;
                i++;
            }
            ans+=(j-i)+1;
            j++;
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int c=*max_element(nums.begin(),nums.end());
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==c)
            a++;
        }
        long long total = 1LL * nums.size() * (nums.size() + 1) / 2;
        return help(nums,c,a)-help(nums,c,k-1);
    }
};