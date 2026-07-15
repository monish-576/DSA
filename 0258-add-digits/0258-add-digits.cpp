class Solution {
public:
    int help(int num)
    {
        if(num<=9) return num;
        int x=0;
        while(num>0)
        {
            x+=(num%10);
            num/=10;
        }
        num=x;
       return help(num);
    }
    int addDigits(int num) {
        return help(num);
    }
};