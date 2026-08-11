class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int size=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        while(j<s.size())
        {
            while(mp.find(s[j])!=mp.end())
            {
                mp.erase(s[i]);
                i++;
            }
            mp[s[j]]=1;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};