class Solution {
public:
    bool help(int x,int i)
    {
        int sum=0;
        while(x>0)
        {
            sum+=x%10;
            x/=10;
        }
        return sum==i;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(help(nums[i],i)) return i;
        }
        return -1;
    }
};