class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }
        while(maxi>0)
        {
            vector<int>res;
            for(auto x:mp)
            {
                if(x.second>0) 
                {
                    res.push_back(x.first);
                    mp[x.first]--;
                }
            }
            ans.push_back(res);
            maxi--;
        }
        return ans;
    }
};