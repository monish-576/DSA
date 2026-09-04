class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int a=*max_element(nums.begin(),nums.begin()+i+1);
            int b=*min_element(nums.begin()+i,nums.end());
            if(a-b<=k) ans=min(ans,i);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};