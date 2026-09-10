class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        while(!pq.empty()&&k>0)
        {
            int x=pq.top();
            int y=floor(x/2);
            pq.pop();
            pq.push(x-y);
            k--;
        }
        int ans=0;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            ans+=x;
        }
        return ans;
    }
};