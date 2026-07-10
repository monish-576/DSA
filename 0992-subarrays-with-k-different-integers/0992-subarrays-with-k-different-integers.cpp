class Solution {
public:
    int help(vector<int>& nums, int k)
    {
         int n=nums.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                if(mp.find(nums[i])!=mp.end())
                {
                     if(mp[nums[i]]==1)
                     mp.erase(nums[i]);
                     else
                     mp[nums[i]]--;
                }
               
                i++;
            }
            if(mp.size()<=k)
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return help(nums,k)-help(nums,k-1);
    }
};