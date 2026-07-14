class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans=strs[0].size();
        for(int i=1;i<strs.size();i++)
        {
             string s1=strs[0];
             string s2=strs[i];
             int j=0,c=0;
             while(j<s1.size()&&j<s2.size())
             {
                if(s1[j]!=s2[j])
                break;
                else
                {
                    c++;
                    j++;
                }
             }
             ans=min(ans,c);
        }
        return strs[0].substr(0,ans);
    }
};