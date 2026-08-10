class Solution {
public:
    void help(int idx,string digits,vector<string>&s,string res,vector<string>&ans)
    {
        if(idx==digits.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=0;i<s[digits[idx]-'0'].size();i++)
        {
            res+=s[digits[idx]-'0'][i];
            help(idx+1,digits,s,res,ans);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string res="";
        help(0,digits,s,res,ans);
        return ans;
    }
};