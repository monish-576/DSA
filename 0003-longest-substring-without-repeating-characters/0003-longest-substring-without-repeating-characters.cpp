class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        int n=s.size();
        int i=0,j=0,res=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
           while(mp[s[j]]>0)
            {
               mp[s[i]]--;
               i++;
            }
            res=max(res,j-i+1);
            mp[s[j]]++;
            j++;
        }
        return res;
    }
};