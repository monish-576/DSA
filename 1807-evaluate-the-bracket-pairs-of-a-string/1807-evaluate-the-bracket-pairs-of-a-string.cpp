class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++)
        {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                string k="";
                int j=i+1;
                while(j<s.size()&&s[j]!=')')
                {
                    k+=s[j];
                    j++;
                }
                if(mp.find(k)!=mp.end())
                ans+=mp[k];
                else
                ans+='?';
                i=j;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};