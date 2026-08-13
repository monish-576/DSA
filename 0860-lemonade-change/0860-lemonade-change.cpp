class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,tens=0,twenty=0;
        int c=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            five++;
            else if(bills[i]==10&&five>0)
            {
                tens++;
                five--;
            }
            else if(bills[i]==20&&tens>0&&five>0)
            {
                twenty++;
                five--;
                tens--;
            }
            else if(bills[i]==20&&five>2)
            {
                twenty++;
                five-=3;
            }
            else
            {
                c=1;
                break;
            }
        }
        cout<<tens<<five<<twenty;
        return c==1? false:true;
    }
};