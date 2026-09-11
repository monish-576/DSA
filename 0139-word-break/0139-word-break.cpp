class Solution {
public:
    bool help(int idx,string s,set<string>&s1,vector<int>&dp)
    {
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        bool k=false;
        for(int j=idx;j<s.size();j++)
        {
                   temp+=s[j];
                   if(s1.find(temp)!=s1.end())
                   {
                      if(help(j+1,s,s1,dp))
                      return dp[idx]=true;
                   }
        }
        return dp[idx]=k;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>s1(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return help(0,s,s1,dp);
    }
};