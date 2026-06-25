class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int>mp;
            mp[nums[i]]++;
            if(2*mp[target]>(i-i)+1)
            c++;
            for(int j=i+1;j<nums.size();j++)
            {
                mp[nums[j]]++;
                if(2*mp[target]>(j-i)+1)
                c++;
            }
        }
        return c;
    }
};