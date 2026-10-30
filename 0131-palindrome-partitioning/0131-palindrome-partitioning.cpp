class Solution {
public:
    bool istrue(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void help(int i,string &s,vector<vector<string>>&ans,vector<string>&res)
    {
        if(i==s.size())
        {
            ans.push_back(res);
            return;
        }
        string temp="";
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(istrue(temp))
            {
                res.push_back(temp);
                help(j+1,s,ans,res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        help(0,s,ans,res);
        return ans;
    }
};