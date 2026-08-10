class Solution {
public:
    void help(int left,int right,int n,vector<string>&ans,string res)
    {
         if(left>n) return;
         if(left<right) return;
         if(left==n&&right==n)
         {
            ans.push_back(res);
            return;
         }
         help(left+1,right,n,ans,res+'(');
         help(left,right+1,n,ans,res+')');
    }
    vector<string> generateParenthesis(int n) {
        int left=0,right=0;
        string res="";
        vector<string>ans;
        help(left,right,n,ans,res);
        return ans;
    }
};