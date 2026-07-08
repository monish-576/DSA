class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            if(mp.find(s[j])==mp.end()||mp[s[j]]<i)
            {
                mp[s[j]]=j;
                ans=max(ans,j-i+1);
            }
            else
            {
            
                i=mp[s[j]]+1; 
                mp[s[j]]=j;
            }
            j++;
        }
        return ans;
    }
};