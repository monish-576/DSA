class Solution {
public:
    void help(int a,int n,int k,vector<vector<int>>&ans,vector<int>&curr)
    {
         if(curr.size()==k) 
         {
             ans.push_back(curr);
             return;
         }   
         for(int i=a;i<=n;i++)
         {
             curr.push_back(i);
             help(i+1,n,k,ans,curr);
             curr.pop_back();
         }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        help(1,n,k,ans,curr);
        return ans;
    }
};