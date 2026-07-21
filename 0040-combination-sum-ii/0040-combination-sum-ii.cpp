class Solution {
public:
    void help(int idx,vector<int>&candidates,int target,vector<int>&res,set<vector<int>>&s)
    {
        if(idx==candidates.size()||target<0)
        {
             if(target==0)
            {
             s.insert(res);
            }
            return;
        }
        if(target==0)
        {
            s.insert(res);
            return;
        }
        if(target>=candidates[idx])
        {
            res.push_back(candidates[idx]);
            help(idx+1,candidates,target-candidates[idx],res,s);
            res.pop_back();
        }
        while(idx+1<candidates.size() &&
          candidates[idx]==candidates[idx+1])
            {
               idx++;
            }
        help(idx+1,candidates,target,res,s);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        set<vector<int>>s;
        help(0,candidates,target,res,s);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};