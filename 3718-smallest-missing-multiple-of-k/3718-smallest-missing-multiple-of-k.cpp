class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]=1;
        }
        int c=0,pr=1;
        while(c!=1)
        {
           if(mp.find(k*pr)==mp.end())
           {
              break;
           }
           pr++;
        }
        return pr*k;
    }
};