class Solution {
public:
    int help(vector<int>&nums,int k)
    {
        int i=0,j=0;
        int c=0;
        map<int,int>mp;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                if(mp[nums[i]]==1)
                mp.erase(nums[i]);
                else
                mp[nums[i]]--;
                i++;
            }
            if(mp.size()<=k)
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};