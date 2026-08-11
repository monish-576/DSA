class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        int c=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]+1==nums[i]&&c==0)
            prefix[i]=prefix[i-1]+nums[i];
            else
            {
              c=1;
              prefix[i]=0;
            }
        }
        if(n>6)
        cout<<prefix[6];
        int large=*max_element(prefix.begin(),prefix.end());
        int ans=0;
        while(large<INT_MAX)
        {
             if(mp.find(large)==mp.end())
             {
                ans=large;
                break;
             }
             else
             large++;
        }
        return ans;
    }
};