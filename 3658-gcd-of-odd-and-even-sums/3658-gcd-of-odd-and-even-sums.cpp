class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int os=0;
        int oe=0;
        for(int i=1;i<=n;i++)
        {
            os=os+(i*2)-1;
            oe=oe+(i*2);
        }
        while(os>0&&oe>0)
        {
            if(os>oe)
            os%=oe;
            else
            oe%=os;
        }
        if(os==0)
        return oe;
        else
        return os;
    }
};