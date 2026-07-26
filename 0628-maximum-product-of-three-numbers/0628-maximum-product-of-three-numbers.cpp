class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0,k=0,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            c++;
            else if(nums[i]==0)
            k=1;
        }
        if(k==1&&c==n) return 0;
        else return max((long long)nums[0]*nums[1]*nums[n-1],(long long)nums[n-1]*nums[n-2]*nums[n-3]);
    }
};