class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int p=0,ans=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
          mp[nums[j]]++;
          p=max(mp[nums[j]],p);
          while(p>k)
          {
             if(p==mp[nums[i]])
             p--;
             mp[nums[i]]--;
             i++;
          }
          if(p<=k)
          ans=max(j-i+1,ans);
          j++;
        }
        return ans;
    }
};