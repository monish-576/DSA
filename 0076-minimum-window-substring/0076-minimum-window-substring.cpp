class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int n=s.size(),m=t.size();
        int i=0,j=0,c=0,ans=INT_MAX,idx=-1;
        unordered_map<char,int>mp;
        for(int k=0;k<t.size();k++)
        mp[t[k]]++;
        while(j<n)
        {
            
            if(mp[s[j]]>0)
            c++;
            mp[s[j]]--;
            while(c==m)
            {
                if(j-i+1<ans)
                {
                    ans=j-i+1;
                    idx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                c--;
                i++;
            }
            j++;
        }
        if (idx == -1) return "";
        return s.substr(idx,ans);
    }
};