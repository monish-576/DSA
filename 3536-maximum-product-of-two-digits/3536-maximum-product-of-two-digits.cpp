class Solution {
public:
    int maxProduct(int n) {
      vector<long long>ans;
      unordered_map<long long,int>mp;
      while(n>0)
      {
        ans.push_back(n%10);
        mp[n%10]++;
        n/=10;
      }
      sort(ans.begin(),ans.end());
      int s=ans.size();
      if(mp[ans[s-1]]>1)
      return ans[s-1]*ans[s-1];
      else
      return ans[s-1]*ans[s-2];
    }
};