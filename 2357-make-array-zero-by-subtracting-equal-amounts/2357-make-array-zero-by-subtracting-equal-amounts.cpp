class Solution {
public:
    void help(vector<int>&nums)
    {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) continue;
            else mini=min(mini,nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) continue;
            else 
            {
                nums[i]-=mini;
            }
        }
    }
    int minimumOperations(vector<int>& nums) {
        int c=0,ans=0;
        while(c!=1)
        {
            if(accumulate(nums.begin(),nums.end(),0)==0)
             {
                c=1;
                break;
             }
            ans++;
            help(nums);
        }
        return ans;
    }
};