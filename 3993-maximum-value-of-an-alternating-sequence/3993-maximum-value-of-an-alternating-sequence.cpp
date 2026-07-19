class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long pr = 1LL * (n - 1) * m;
        pr+=s;
        long long k;
        if(n%2==0)
        {
         k=(n/2)-1;
         pr-=k*m;
         pr-=k;
        }
        else
        {
          k=n/2;
          pr-=k*m;
          pr-=(k-1);
        }
        return pr;
    }
};