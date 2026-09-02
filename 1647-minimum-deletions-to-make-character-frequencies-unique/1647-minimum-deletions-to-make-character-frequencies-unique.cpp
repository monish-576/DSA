class Solution {
public:
    int minDeletions(string s) {
       vector<int>arr(26,0);
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int ans=0;
        int x=arr[0];
        for(int i=1;i<26;i++)
        {
              if(arr[i]==0) break;
              if(arr[i]>=x)
              {
                int newFreq = max(0, x- 1);
                ans += arr[i] - newFreq;
                x = newFreq;
              }
              else
              x=arr[i];
        }
        return ans;
    }
};