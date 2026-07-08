class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n),suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]*prefix[i-1];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=nums[i]*suffix[i+1];
        }
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            res[i]=suffix[i+1];
            else if(i==n-1)
            res[i]=prefix[i-1];
            else
            res[i]=prefix[i-1]*suffix[i+1];
        }
        return res;
    }
};