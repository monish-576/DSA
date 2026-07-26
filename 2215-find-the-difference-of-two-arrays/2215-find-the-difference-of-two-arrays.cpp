class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>mp1,mp2;
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>res;
        for(int i=0;i<max(n1,n2);i++)
        {
             if(i>=n1)
             {
                mp2.insert(nums2[i]);
             }
             else if(i>=n2)
             {
                mp1.insert(nums1[i]);
             }
             else
             {
                mp1.insert(nums1[i]);
                mp2.insert(nums2[i]);
             }
        }
        vector<int>d1,d2;
        for(auto x:mp1)
        {
            if(mp2.find(x)==mp2.end())
            {
                 d1.push_back(x);
            }
        }
        for(auto x:mp2)
        {
            if(mp1.find(x)==mp1.end())
            {
                 d2.push_back(x);
            }
        }
        res.push_back(d1);
        res.push_back(d2);
        return res;
    }
};