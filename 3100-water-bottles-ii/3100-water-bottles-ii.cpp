class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int n = numBottles, sum = numBottles;

        while (n >= numExchange) {
            sum++;
            n = n - numExchange + 1; 
            numExchange++;           
        }

        return sum;
    }
};