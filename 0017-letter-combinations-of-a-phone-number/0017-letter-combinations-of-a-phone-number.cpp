class Solution {
public:
    void solve(int idx,string &digits,vector<string>&ans,string &temp,string s[])
    {
        if(idx==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s[digits[idx]-'0'].size();i++)
        {
            char curr=s[digits[idx]-'0'][i];
            temp.push_back(curr);
            solve(idx+1,digits,ans,temp,s);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       string temp;
       vector<string>ans;
       string s[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       solve(0,digits,ans,temp,s);
       return ans;
    }
};