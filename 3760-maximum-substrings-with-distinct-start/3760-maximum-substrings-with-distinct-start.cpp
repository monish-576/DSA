class Solution {
public:
    int maxDistinct(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            ans++;
        }
        return ans;
    }
};