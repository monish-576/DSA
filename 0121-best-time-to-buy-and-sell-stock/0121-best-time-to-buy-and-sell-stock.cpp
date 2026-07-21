class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small=prices[0],ans=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<small)
            small=prices[i];
            else
            ans=max(prices[i]-small,ans);
        }
        return ans;
    }
};