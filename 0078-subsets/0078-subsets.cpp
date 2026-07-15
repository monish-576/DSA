class Solution {
public:
    void help(int idx,vector<vector<int>>&ans,vector<int>&nums,vector<int>&res)
    {
        if(idx==nums.size())
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        help(idx+1,ans,nums,res);
        res.pop_back();
        help(idx+1,ans,nums,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        help(0,ans,nums,res);
        return ans;
    }
};