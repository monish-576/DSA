class Solution {
public:
    int help(int num)
    {
          int c=0,sum=0;
          for(int i=1;i<=sqrt(num);i++)
          {
             if(num%i==0)
             {
                if(num/i==i)
                {
                    c++;
                    sum+=i;
                }
                else
                {
                    c+=2;
                    sum+=i;
                    sum+=num/i;
                }
             }
          }
          if(c==4) return sum;
          return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=help(nums[i]);
        }
        return ans;
    }
};