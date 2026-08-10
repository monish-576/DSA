class Solution {
public:
    void help(int left,int right,int n,string res,vector<string>&ans)
    {
        if(left>n) return;
        if(left<right) return;
        if(left==n&&right==n)
        {
            ans.push_back(res);
            return;
        }
        help(left+1,right,n,res+'(',ans);
        help(left,right+1,n,res+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        help(0,0,n,res,ans);
        return ans;
    }
};