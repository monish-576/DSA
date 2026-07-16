class Solution {
public:
    int gcd(int a,int b)
    {
        
        while(b>0)
        {
            int x=a%b;
            a=b;
            b=x;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        int x=nums[0];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            x=max(x,nums[i]);
            prefix[i]=gcd(x,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        long long ans=0;
        int i=0,j=n-1;
        while(i<j)
        {
            ans+=gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return ans;
    }
};