class Solution {
public: 
    bool static comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>>arr;
        for(auto x:mp)
        {
            arr.push_back({x.first,x.second});
        }
        sort(arr.begin(),arr.end(),comp);
        vector<int>ans(k);
        for(int i=0;i<k;i++)
        {
            ans[i]=arr[i].first;
        }
        return ans;
    }
};