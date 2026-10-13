class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            nums[i]*=-1;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=n/2;
        // if(n%2!=0)
        long long p1=0,p2=0;
        for(int i=0;i<k;i++)
        {
            p1+=pow(nums[i],2);
        }
        for(int i=k;i<n;i++)
        {
            p2+=pow(nums[i],2);
        }
        return p2-p1;
    }
};