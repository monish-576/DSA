class Solution {
public:
    int help(vector<int>&nums,int i,int j,int p)
    {
        if(i>j) return 0;
        if(p==0)
        {
            int s1=nums[i]+help(nums,i+1,j,1);
            int s2=nums[j]+help(nums,i,j-1,1);
            return max(s1,s2);
        }
        else
        {
            int s1=help(nums,i+1,j,0);
            int s2=help(nums,i,j-1,0);
            return min(s1,s2);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int s1=help(nums,0,nums.size()-1,0);
        int s2=tot-s1;
        return s1>=s2;
    }
};