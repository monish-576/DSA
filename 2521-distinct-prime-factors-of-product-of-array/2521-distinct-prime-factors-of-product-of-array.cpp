class Solution {
public:
    void help(int n,vector<int>&spf,set<int>&s)
    {
        while(n>1)
        {
            s.insert(spf[n]);
            n/=spf[n];
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>spf(10001);
        for(int i=0;i<1001;i++)
        {
            spf[i]=i;
        }
        for(int i=2;i<=1000;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=1000;j+=i)
                {
                    if(spf[j]==j)
                    spf[j]=i;
                }
            }
        }
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            help(nums[i],spf,s);
        }
        return s.size();
    }
};