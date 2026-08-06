class Solution {
public:
    bool help(int n,int k)
    {
        int c=1;
        while(n>0)
        {
            c=c*(n%10);
            n/=10;
        }
        cout<<c<<" ";
        return c%k==0;
    }
    int smallestNumber(int n, int t) {
        int ans;
        for(int i=n;i<=100;i++)
        {
            if(help(i,t))
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};