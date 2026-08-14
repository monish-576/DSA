class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int k=0,ans=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
           mp[s[j]]++;
           k=max(k,mp[s[j]]);
           while(mp[s[j]]>2)
           {
              if(mp[s[i]]==k)
              k--;
              mp[s[i]]--;
              i++;
           }
           if(k<=2)
           {
            ans=max(ans,j-i+1);
           }
           j++;
        }
        return ans;
    }
};