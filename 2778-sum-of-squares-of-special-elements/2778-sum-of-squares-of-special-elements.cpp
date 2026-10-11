class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int pr=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
             if(n%(i+1)==0)
              pr+=nums[i]*nums[i];
        }
        return pr;
    }
};