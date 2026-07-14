class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(c>0)
                {
                ans+='(';
                }
                c++;
            }
            else
            {
                c--;
                if(c!=0) 
                {
                ans+=')';
                }
            }
        }
        return ans;
    }
};