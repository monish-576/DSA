class Solution {
public:
    int help(int i,int j,string word1,string word2,vector<vector<int>>&dp)
    {
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return help(i+1,j+1,word1,word2,dp);
        return dp[i][j]=min({1+help(i,j+1,word1,word2,dp),1+help(i+1,j,word1,word2,dp),1+help(i+1,j+1,word1,word2,dp)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return help(0,0,word1,word2,dp);
    }
};