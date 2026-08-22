class Solution {
public:
    bool checkDivisibility(int n) {
        int k=n;
        int sum=0;
        int pr=1;
        while(n>0)
        {
            sum+=n%10;
            pr*=n%10;
            n/=10;
        }
        return k%(sum+pr)==0 ? true:false;
    }
};