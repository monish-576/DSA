class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int>mp;
            mp[s[i]]++;
            for(int j=i+1;j<s.size();j++)
            {
                mp[s[j]]++;
                int a=0,b=1000;
                for(auto &x:mp)
                {
                    a=max(a,x.second);
                    b=min(b,x.second);
                }
                ans+=a-b;
            }
        }
        return ans;
    }
};