class Solution {
public:
    int ans=INT_MAX;
    void help2(int idx,vector<int>&nums,int goal,int right,set<int>&s2,int x)
    {
         if(idx==right)
         {
              ans=min(abs(x-goal),ans);
              s2.insert(x);
              return;
         }
         help2(idx+1,nums,goal,right,s2,x);
         help2(idx+1,nums,goal,right,s2,x+nums[idx]);
    }
    void help1(int idx,vector<int>&nums,int goal,int right,set<int>&s1,int x)
    {
         if(idx==right)
         {
              ans=min(abs(x-goal),ans);
              s1.insert(x);
              return;
         }
         help1(idx+1,nums,goal,right,s1,x);
         help1(idx+1,nums,goal,right,s1,x+nums[idx]);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        set<int>s1,s2;
        help1(0,nums,goal,n/2,s1,0);
        help2(n/2,nums,goal,n,s2,0);
       for (auto x : s1)
       {
          int b = goal - x;

          auto it = s2.lower_bound(b);

          if (it != s2.end())
        ans = min(ans, abs(goal - (x + *it)));

        if (it != s2.begin())
        {
        --it;
        ans = min(ans, abs(goal - (x + *it)));
        }
        }
        return ans;
    }
};