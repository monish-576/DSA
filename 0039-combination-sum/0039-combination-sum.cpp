class Solution {
public:
    void help(int idx,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&res)
    {
        if(idx==candidates.size()||target<0)
        return;
        if(target==0)
        {
         ans.push_back(res);
         return;
        }
        res.push_back(candidates[idx]);
        help(idx,candidates,target-candidates[idx],ans,res);
        res.pop_back();
        help(idx+1,candidates,target,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        help(0,candidates,target,ans,res);
        return ans;
    }
};