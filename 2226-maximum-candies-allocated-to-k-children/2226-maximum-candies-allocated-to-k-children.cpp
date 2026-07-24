class Solution {
public:
    bool help(long long m,vector<int>&candies,long long k)
    {
        long long ans=0;
        for(int i=0;i<candies.size();i++)
        {
            ans+=candies[i]/m;
        }
        return ans>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1,high=*max_element(candies.begin(),candies.end());
        long long ans;
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if(sum<k) return 0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(help(mid,candies,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return (int)ans;
    }
};