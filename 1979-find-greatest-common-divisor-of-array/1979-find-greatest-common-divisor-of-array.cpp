class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int b=*min_element(nums.begin(),nums.end());
        while(a>0&&b>0)
        {
            if(a>b)
            {
                a%=b;
            }
            else
            {
                b%=a;
            }
        }
        if(a==0)
        return b;
        else
        return a;
    }
};