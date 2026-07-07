class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res=0,sum=0,num=0;
        while(n>0)
        {
            num*=10;
            num+=n%10;
            n/=10;
        }
        while(num>0)
        {
            if(num%10==0)
            {
                num/=10;
            }
            else
            {
                res=(res*10)+num%10;
                sum+=num%10;
                num/=10;
            }
        }
        return sum*res;
    }
};