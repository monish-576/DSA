class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
       vector<int>suffix(n);
       suffix[n-1]=height[n-1];
       for(int i=n-2;i>=0;i--)
       {
           suffix[i]=max(height[i],suffix[i+1]);
       }
       int ans;
       int prefix=height[0];
       ans=min(prefix,suffix[0])-height[0];
       for(int i=1;i<n;i++)
       {
          prefix=max(prefix,height[i]);
          ans+=min(prefix,suffix[i])-height[i];
       }
       return ans;
    }
};