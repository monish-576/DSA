class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles,sum=numBottles;
        while(n>=numExchange)
        {
            sum+=(n/numExchange);
            n=(n/numExchange)+(n%numExchange);
        }
        return sum;
    }
};